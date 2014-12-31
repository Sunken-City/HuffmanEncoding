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
	while (bitstream.size() > 7)
	{
		byte nextByte = 0;
		for (int i = 0; i < 8; i++)
		{
			nextByte = nextByte | (popBit(&bitstream) << i);
		}
		write->IO<byte>(nextByte);
	}
	write->close();
}

void FileCompressor::decompress(Serializer* read)
{
	BinaryTree<HuffmanData>* tree = BinaryTree<HuffmanData>::reconstruct(*read);
	queue<char> bytestream = queue<char>();
	while (read->hasNext())
	{
		char nextByte;
		read->IO<char>(nextByte);
		bytestream.push(nextByte);
	}

	Serializer write = Serializer("output.txt", false);
	while (bytestream.size() > 0)
	{
		__int8 nextBit = 0;
		char nextByte = popBit(&bytestream);
		string treePath = "";
		for (int i = 0; i < 8; i++)
		{
			nextBit = (nextByte >> i) & 1;
			treePath += (char)(nextBit + (int)'0');
		}
		//write.IO<char>(nextByte);
	}
}