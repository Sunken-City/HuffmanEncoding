// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Note that this is all temporary, I'll make a nicer interface later with error checking.
	cout << "File to compress: ";
	string fileName;
	cin >> fileName;

	ifstream file;
	file.open(fileName, ios::in | ios::binary);

	string readLine;
	char* fileBytes = nullptr;
	if (file.is_open())
	{
		//Get the length of the file first
		streampos begin = file.tellg();
		file.seekg(0, ios::end);
		streampos end = file.tellg();
		int length = end - begin;
		//Create the buffer from that length of the file.
		fileBytes = new char[length];

		file.seekg(0, ios::beg);
		file.read(fileBytes, length);
		file.close();
	}
	cout << fileBytes;
	cin >> fileName;
	return 0;
}

