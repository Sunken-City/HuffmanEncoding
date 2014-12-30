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
int BinaryFileReader::getFileLength()
{
	return length;
}

byte** BinaryFileReader::getFileBytes()
{
	return &fileBytes;
}