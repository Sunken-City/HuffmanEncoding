#include "stdafx.h"

Serializer::Serializer(string fileName, bool readingMode)
{
#pragma warning(push)
#pragma warning(disable: 4996)
	if (readingMode)
		this->file = fopen(fileName.c_str(), "rb");
	else
		this->file = fopen(fileName.c_str(), "wb");
	//Set up the buffer to ensure proper output
	setvbuf(file, NULL, _IOFBF, BUFSIZ);
	this->readingMode = readingMode;
#pragma warning(pop)
}

Serializer::~Serializer()
{
	close();
}

void Serializer::close()
{
	fclose(this->file);
}

bool Serializer::hasNext()
{
	return !feof(file);
}