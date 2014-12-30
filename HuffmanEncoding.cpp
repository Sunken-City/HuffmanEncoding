// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryFileReader.h"
#include "BinaryTree.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, byte> huffmanData;
typedef BinaryNode<pair<int, byte>> node;

void createTree(vector<huffmanData>* sortedBytes)
{
	BinaryTree<huffmanData> tree = BinaryTree<huffmanData>();
	vector<node*> availableNodes = vector<node*>();
	for each (huffmanData byte in *sortedBytes)
	{
		availableNodes.push_back(new node(byte, nullptr, nullptr));
	}
	for (int i = 0; i < 0x100; i++)
	{
		cout << availableNodes.at(i)->data.second << ": " << availableNodes.at(i)->data.first << endl;
	}
}

vector<huffmanData>* sortBytes(byte** file, int length)
{
	//Create a vector so that we can sort our frequencies easily.
	vector<huffmanData>* sortedFrequencies = new vector<huffmanData>();
	byte* byteValues = *file;

	for (int i = 0; i < 0x100; i++)
	{
		sortedFrequencies->push_back(make_pair(0, i));
	}

	for (int i = 0; i < length; i++)
	{
		sortedFrequencies->at(byteValues[i]).first += 1;
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

