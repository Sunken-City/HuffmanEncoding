// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryFileReader.h"
#include "BinaryTree.h"
#include "HuffmanData.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef BinaryNode<HuffmanData> node;

void createTree(vector<HuffmanData>* sortedBytes)
{
	BinaryTree<HuffmanData> tree = BinaryTree<HuffmanData>();
	vector<node*> availableNodes = vector<node*>();
	for each (HuffmanData byte in *sortedBytes)
	{
		//If a byte doesn't show up in the original file, then don't add it to the tree.
		if (byte.frequency != 0)
			availableNodes.push_back(new node(byte, nullptr, nullptr));
	}
}

vector<HuffmanData>* sortBytes(byte** file, int length)
{
	//Create a vector so that we can sort our frequencies easily.
	vector<HuffmanData>* sortedFrequencies = new vector<HuffmanData>();
	byte* byteValues = *file;

	for (int i = 0; i < 0x100; i++)
	{
		sortedFrequencies->push_back(HuffmanData(0, i));
	}

	for (int i = 0; i < length; i++)
	{
		sortedFrequencies->at(byteValues[i]).frequency += 1;
	}
	
	//Sort the list based on frequency value.
	sort(sortedFrequencies->begin(), sortedFrequencies->end());

	/*for (int i = 0; i < 0x100; i++)
	{
		cout << sortedFrequencies->at(i).second << ": " << sortedFrequencies->at(i).first << endl;
	}*/
	return sortedFrequencies;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Note that this is all temporary, I'll make a nicer interface later with error checking.
	cout << "File to compress: ";
	string fileName;
	cin >> fileName;

	BinaryFileReader file = BinaryFileReader(fileName);
	createTree(sortBytes(file.getFileBytes(), file.getFileLength()));
	
	//Stop the output window from closing immediately.
	cin >> fileName;
	return 0;
}

