// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryFileReader.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int** sortBytes(byte** file, int length)
{
	//Create an array from 0x00 to 0xFF to hold all of the frequencies in.
	int* frequencies = new int[0x100];
	byte* byteValues = *file;

	for (int i = 0; i < 0x100; i++)
	{
		frequencies[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		frequencies[byteValues[i]] += 1;
	}

	return &frequencies;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Note that this is all temporary, I'll make a nicer interface later with error checking.
	cout << "File to compress: ";
	string fileName;
	cin >> fileName;

	BinaryFileReader file = BinaryFileReader(fileName);
	sortBytes(file.getFileBytes(), file.getFileLength());
	
	//Stop the output window from closing immediately.
	cin >> fileName;
	return 0;
}

