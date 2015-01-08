#include "stdafx.h"
#include "FileCompressor.h"

FileCompressor::FileCompressor(string inputFileName, string outputFileName)
{
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
	write = new Serializer(outputFileName, false);
	read = new Serializer(inputFileName, true);
	progress = 0;
}

FileCompressor::~FileCompressor()
{
	delete(write);
	delete(read);
}

void FileCompressor::readInputFile(string fileName)
{
	ifstream file;
	file.open(fileName, ios::in | ios::binary);

	string readLine;
	if (file.is_open())
	{
		//Get the length of the file first
		streampos begin = file.tellg();
		file.seekg(0, ios::end);
		streampos end = file.tellg();
		length = end - begin;
		//Create the buffer from that length of the file.
		fileBytes = new byte[length];

		file.seekg(0, ios::beg);
		for (int i = 0; i < length; i++)
		{
			fileBytes[i] = file.get();
		}
		file.close();
	}
}

int FileCompressor::getFileLength()
{
	return length;
}

byte** FileCompressor::getFileBytes()
{
	return &fileBytes;
}

__int8 FileCompressor::popBit(queue<__int8>* bitstream)
{
	__int8 bit = bitstream->front();
	bitstream->pop();
	return bit;
}

void FileCompressor::compress()
{
	progress = 5;
	readInputFile(inputFileName);
	progress = 20;
	string* huffmanHash = *this->createTree();
	progress = 40;
	//Using an 8 bit int for the queue, since each BIT
	//is represented by 4 BYTES otherwise
	queue<__int8> bitstream = queue<__int8>();

	//For each of the bytes in the file...
	for (int i = 0; i < length; i++)
	{
		const char* code = huffmanHash[fileBytes[i]].c_str();
		int codeLength = huffmanHash[fileBytes[i]].length();
		for (int j = 0; j < codeLength; j++)
		{
			//Since the strings are made up entirely of 1's and 0's,
			//You can subtract the ascii value of '0' to get an integer
			//value of 0 or 1 from '0' or '1' respectively.
			bitstream.push(code[j] - '0');
		}
	}
	progress = 60;
	//Once we have the bitstream, we can now pull out bytes from it and 
	//write them to the compressed file.
	byte nextByte;
	while (bitstream.size() > 7)
	{
		nextByte = 0;
		for (int i = 0; i < 8; i++)
		{
			nextByte = nextByte | (popBit(&bitstream) << i);
		}
		write->IO<byte>(nextByte);
	}
	progress = 90;
	nextByte = 0;
	//Write out the last few bits and add junk bits as necessary.
	byte junkBits = '8' - bitstream.size();
	for (int i = 0; i < 8; i++)
	{
		if (bitstream.size() > 0)
			nextByte = nextByte | (popBit(&bitstream) << i);
		else
			nextByte = nextByte | (0 << i);
	}
	write->IO<byte>(nextByte);
	write->IO<byte>(junkBits);
	write->close();
	progress = 100;
}

void FileCompressor::decompress()
{
	progress = 5;
	BinaryTree<HuffmanData>* tree = BinaryTree<HuffmanData>::reconstruct(read);
	progress = 20;
	queue<char> bytestream = queue<char>();
	char nextByte;

	//The first byte needs to be read outside the loop, because feof doesn't
	//set a flag unless another read is attempted past the end of the file
	read->IO<char>(nextByte);
	while (read->hasNext())
	{
		bytestream.push(nextByte);
		read->IO<char>(nextByte);
	}
	read->close();
	progress = 50;
	string treePath = "";
	int validBits = 8;
	node* node = nullptr;
	//The final bit is our junk bit control byte
	while (bytestream.size() > 1)
	{
		__int8 nextBit;
		char nextByte = popBit(&bytestream);
		if (bytestream.size() == 1)
			validBits = validBits - (bytestream.back() - '0');

		for (int i = 0; i < validBits; i++)
		{
			nextBit = (nextByte >> i) & 1;
			node = tree->findLeaf(node, (char)(nextBit + (int)'0'));
			if (node->isLeaf())
			{
				write->IO<char>(node->data.byte);
				node = nullptr; //Start again from the root node
			}
		}
	}
	progress = 90;
	write->close();
	progress = 100;
}

string** FileCompressor::createTree()
{
	list<node*> availableNodes = list<node*>();

	vector<HuffmanData>* sortedBytes = sortBytes(this->getFileBytes(), this->getFileLength());

	for each (HuffmanData byte in *sortedBytes)
	{
		//If a byte doesn't show up in the original file, then don't add it to the tree.
		if (byte.frequency != 0)
			availableNodes.push_back(new node(byte, nullptr, nullptr));
	}

	while (availableNodes.size() > 1)
	{
		//Start by getting a handle to the first two nodes and popping them off the list.
		node* leftNode = availableNodes.front();
		availableNodes.pop_front();
		node* rightNode = availableNodes.front();
		availableNodes.pop_front();

		//Create a new node using the first two nodes as children
		node* parentNode = new node(HuffmanData(leftNode->data.frequency + rightNode->data.frequency, 14), leftNode, rightNode);

		//Now find the appropriate place to put the new node in the list
		insertNode(parentNode, &availableNodes);
	}

	BinaryTree<HuffmanData> tree = BinaryTree<HuffmanData>(availableNodes.front());

	string* huffmanCodes = new string[0x101];
	for (size_t i = 0; i < 0x101; i++)
	{
		huffmanCodes[i] = "";
	}
	generateHuffmanCodes(&tree, &huffmanCodes);
	tree.serialize(write);
	return &huffmanCodes;
}

void FileCompressor::generateHuffmanCodes(BinaryTree<HuffmanData>* tree, string** huffmanCodes)
{
	generateHuffmanCode(tree->getRoot(), huffmanCodes, "");
}

void FileCompressor::generateHuffmanCode(node *node, string** huffmanHash, string huffmanCode)
{
	//If the node is null, don't do anything.
	if (node != NULL)
	{
		//If the node is a leaf node, set the data for it
		if (node->left == NULL && node->right == NULL)
			(*huffmanHash)[(unsigned char)node->data.byte] = huffmanCode;
		//Otherwise, go down the tree again.
		else
		{
			generateHuffmanCode(node->left, huffmanHash, huffmanCode + "0");   // Traverse the left sub-tree
			generateHuffmanCode(node->right, huffmanHash, huffmanCode + "1");   // Traverse the right sub-tree
		}
	}
}

void FileCompressor::insertNode(node* parentNode, list<node*>* availableNodes)
{
	list<node*>::iterator iter = availableNodes->begin();
	for each (node* var in *availableNodes)
	{
		if (var->data.frequency > parentNode->data.frequency)
		{
			availableNodes->insert(iter, parentNode);
			return;
		}
		iter++;
	}
	//If this is the biggest node, add it to the back of the list
	availableNodes->push_back(parentNode);
}

vector<HuffmanData>* FileCompressor::sortBytes(byte** file, int length)
{
	//Create a vector so that we can sort our frequencies easily.
	vector<HuffmanData>* sortedFrequencies = new vector<HuffmanData>();
	byte* byteValues = *file;

	for (int i = 0; i < 0x100; i++)
	{
		sortedFrequencies->push_back(HuffmanData(0, i));
	}

	for (int i = 0; i < length; i++)
	{
		sortedFrequencies->at(byteValues[i]).frequency += 1;
	}

	//Sort the list based on frequency value.
	sort(sortedFrequencies->begin(), sortedFrequencies->end());

	return sortedFrequencies;
}

int FileCompressor::getProgress()
{
	return progress;
}