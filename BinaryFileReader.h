#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BinaryFileReader
{
public: 
	BinaryFileReader(string fileName);
	char** getFileBytes();

private:
	ifstream* inputFile;
	string fileName;
	char* fileBytes;
};