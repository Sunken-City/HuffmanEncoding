// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string testString;
	cin >> testString;
	fstream testFile;
	testFile.open("save.bin", ios::out | ios::binary);
	testFile << testString;
	testFile.close();
	cout << testString << " was written to file." << endl;
	testFile.open("save.bin", ios::in | ios::binary);
	string readLine;
	if (testFile.is_open())
	{
		while (getline(testFile, readLine))
		{
			cout << readLine << '\n';
		}
		testFile.close();
	}
	return 0;
}

