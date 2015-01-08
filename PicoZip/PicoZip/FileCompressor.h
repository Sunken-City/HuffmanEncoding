#pragma once
#include <queue>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;
typedef unsigned char byte;
typedef BinaryNode<HuffmanData> node;

class FileCompressor
{
public:
	FileCompressor(string inputFileName, string outputFileName);
	virtual ~FileCompressor();
	byte** getFileBytes();
	int getFileLength();
	void compress();
	void decompress();
	string** createTree();
	int getProgress();

private:
	string inputFileName;
	string outputFileName;
	byte* fileBytes;
	int length;
	int progress;
	Serializer* write;
	Serializer* read;

	void readInputFile(string fileName);
	__int8 popBit(queue<__int8>* bitstream);
	void insertNode(node* parentNode, list<node*>* availableNodes);
	void generateHuffmanCodes(BinaryTree<HuffmanData>* tree, string** huffmanCodes);
	void generateHuffmanCode(node *node, string** huffmanHash, string huffmanCode); 
	vector<HuffmanData>* sortBytes(byte** file, int length);
};