#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned char byte;

class BinaryFileReader
{
public: 
	BinaryFileReader(string fileName);
	byte** getFileBytes();
	int getFileLength();

private:
	ifstream* inputFile;
	string fileName;
	byte* fileBytes;
	int length;
};