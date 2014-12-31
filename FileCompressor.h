#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Serializer.h"
#include "BinaryTree.h"

using namespace std;
typedef unsigned char byte;

class FileCompressor
{
public: 
	FileCompressor(string fileName);
	byte** getFileBytes();
	int getFileLength();
	void compress(string** huffmanHash, Serializer* write);
	void decompress(Serializer* write);

private:
	ifstream* inputFile;
	string fileName;
	byte* fileBytes;
	int length;
	__int8 popBit(queue<__int8>* bitstream);
};