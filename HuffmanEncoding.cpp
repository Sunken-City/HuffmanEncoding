// HuffmanEncoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileCompressor.h"
#include "BinaryTree.h"
#include "HuffmanData.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <bitset>

using namespace std;
typedef BinaryNode<HuffmanData> node;
void insertNode(node* parentNode, list<node*>* availableNodes)
{
	list<node*>::iterator iter = availableNodes->begin();
	for each (node* var in *availableNodes)
	{
		if (var->data.frequency > parentNode->data.frequency)
		{
			availableNodes->insert(iter, parentNode);
			return;
		}
		iter++;
	}
	//If this is the biggest node, add it to the back of the list
	availableNodes->push_back(parentNode);
}

void generateHuffmanCode(BinaryNode<HuffmanData> *node, string** huffmanHash, string huffmanCode)
{
	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL)
			(*huffmanHash)[node->data.byte] = huffmanCode;
		generateHuffmanCode(node->left, huffmanHash, huffmanCode + "0");   // Traverse the left sub-tree
		generateHuffmanCode(node->right, huffmanHash, huffmanCode + "1");   // Traverse the right sub-tree
	}
}

void generateHuffmanCodes(BinaryTree<HuffmanData>* tree, string** huffmanCodes)
{
	generateHuffmanCode(tree->getRoot(), huffmanCodes, "");
}

string** createTree(vector<HuffmanData>* sortedBytes)
{
	list<node*> availableNodes = list<node*>();
	for each (HuffmanData byte in *sortedBytes)
	{
		//If a byte doesn't show up in the original file, then don't add it to the tree.
		if (byte.frequency != 0)
			availableNodes.push_back(new node(byte, nullptr, nullptr));
	}
	
	while (availableNodes.size() > 1)
	{
		//Start by getting a handle to the first two nodes and popping them off the list.
		node* leftNode = availableNodes.front();
		availableNodes.pop_front();
		node* rightNode = availableNodes.front();
		availableNodes.pop_front();

		//Create a new node using the first two nodes as children
		node* parentNode = new node(HuffmanData(leftNode->data.frequency + rightNode->data.frequency, 14), leftNode, rightNode);
		//cout << parentNode->data.frequency << " left -> " << parentNode->left->data.byte << " right -> " << parentNode->right->data.byte << endl;

		//Now find the appropriate place to put the new node in the list
		insertNode(parentNode, &availableNodes);
	}

	BinaryTree<HuffmanData> tree = BinaryTree<HuffmanData>(availableNodes.front());

	string* huffmanCodes = new string[0x100];
	for (size_t i = 0; i < 0x100; i++)
	{
		huffmanCodes[i] = "";
	}
	generateHuffmanCodes(&tree, &huffmanCodes);
	return &huffmanCodes;
	/*for (size_t i = 0; i < 0x100; i++)
	{
		if (huffmanCodes[i] != "")
			cout << (char)i << " has the code: " << huffmanCodes[i] << endl;
	}*/

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

	return sortedFrequencies;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Note that this is all temporary, I'll make a nicer interface later with error checking.
	cout << "File to compress: ";
	string fileName;
	cin >> fileName;

	FileCompressor file = FileCompressor(fileName);
	string* huffmanHash = *createTree(sortBytes(file.getFileBytes(), file.getFileLength()));
	
	file.compressFile(&huffmanHash);

	//Stop the output window from closing immediately.
	cin >> fileName;
	return 0;
}

