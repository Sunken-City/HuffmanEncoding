#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "Serializer.h"
#include "BinaryTree.h"

using namespace std;
typedef unsigned char byte;

class FileCompressor
{
public:
	FileCompressor(string fileName);
	byte** getFileBytes();
	int getFileLength();
	void compress();
	void decompress(); 
	string** createTree();

private:
	ifstream* inputFile;
	string fileName;
	byte* fileBytes;
	int length;
	Serializer write = Serializer("zippedTest.kek", false);
	Serializer read = Serializer("zippedTest.kek", true);
	__int8 popBit(queue<__int8>* bitstream);
	void insertNode(node* parentNode, list<node*>* availableNodes);
	void generateHuffmanCodes(BinaryTree<HuffmanData>* tree, string** huffmanCodes);
	void generateHuffmanCode(BinaryNode<HuffmanData> *node, string** huffmanHash, string huffmanCode); 
	vector<HuffmanData>* sortBytes(byte** file, int length);
};