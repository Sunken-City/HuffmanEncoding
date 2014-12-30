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

int _tmain(int argc, _TCHAR* argv[])
{
	//Note that this is all temporary, I'll make a nicer interface later with error checking.
	cout << "File to compress: ";
	string fileName;
	cin >> fileName;

	BinaryFileReader file = BinaryFileReader(fileName);
	
	cout << *(file.getFileBytes());
	cin >> fileName;
	return 0;
}

