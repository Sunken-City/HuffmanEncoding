#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Serializer.h"

using namespace std;
typedef unsigned char byte;

class FileCompressor
{
public: 
	FileCompressor(string fileName);
	byte** getFileBytes();
	int getFileLength();
	void compressFile(string** huffmanHash, Serializer* write);

private:
	ifstream* inputFile;
	string fileName;
	byte* fileBytes;
	int length;
	__int8 popBit(queue<__int8>* bitstream);
};