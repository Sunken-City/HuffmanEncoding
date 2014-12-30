#include "stdafx.h"
#include "BinaryFileReader.h"

BinaryFileReader::BinaryFileReader(string fileName)
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
		int length = end - begin;
		//Create the buffer from that length of the file.
		fileBytes = new char[length];

		inputFile->seekg(0, ios::beg);
		inputFile->read(fileBytes, length);
		inputFile->close();
	}
}

char** BinaryFileReader::getFileBytes()
{
	return &fileBytes;
}