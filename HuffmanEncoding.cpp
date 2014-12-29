// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string testString;
	cin >> testString;
	FILE* file;
	fopen_s(&file, "save.bin", "wb");
	fwrite(testString.c_str(), sizeof(testString), 1, file);
	cout << testString << " was written to file." << endl;
	return 0;
}

