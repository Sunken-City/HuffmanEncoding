// HuffmanEncoding.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "FileCompressor.h"
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//Note that this is all temporary, I'll make a nicer interface later with error checking.
	cout << "File to compress: ";
	string fileName;
	cin >> fileName;

	FileCompressor file = FileCompressor(fileName);
	file.compress();

	file.decompress();
	cout << "Done!" << endl;

	//Stop the output window from closing immediately.
	cin >> fileName;
	return 0;
}

