#include "stdafx.h"
#include "FileCompressor.h"

FileCompressor::FileCompressor(string fileName)
{
	ifstream file;
	file.open(fileName, ios::in | ios::binary);
	inputFile = &file;

	string readLine;
	if (inputFile->is_open())
	{
		//Get the length of the file first
		streampos begin = inputFile->tellg();
		inputFile->seekg(0, ios::end);
		streampos end = inputFile->tellg();
		length = end - begin;
		//Create the buffer from that length of the file.
		fileBytes = new byte[length];

		inputFile->seekg(0, ios::beg);
		for (int i = 0; i < length; i++)
		{
			fileBytes[i] = inputFile->get();
		}
		inputFile->close();
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

void FileCompressor::compress(string** huffmanCodes, Serializer* write)
{
	string* huffmanHash = *huffmanCodes;
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
}

void FileCompressor::decompress(Serializer* read)
{
	BinaryTree<HuffmanData>* tree = BinaryTree<HuffmanData>::reconstruct(*read);
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
	Serializer write = Serializer("output.jpg", false);
	string treePath = "";
	int validBits = 8;
	int iterationCount = 0;
	//The back bit is our junk bit control byte
	while (bytestream.size() > 1)
	{
		__int8 nextBit;
		char nextByte = popBit(&bytestream);
		BinaryNode<HuffmanData>* node = nullptr;
		if (bytestream.size() == 1)
		{
			validBits = validBits - (bytestream.back() - '0');
		}
		for (int i = 0; i < validBits; i++)
		{
			node = NULL;
			nextBit = (nextByte >> i) & 1;
			treePath += (char)(nextBit + (int)'0');
			node = tree->findLeaf(treePath);
			if (node != NULL)
			{
				write.IO<char>(node->data.byte);
				treePath = "";
				iterationCount++;
			}
		}
	}
	write.close();
}