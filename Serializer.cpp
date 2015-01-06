#include "stdafx.h"
#include "Serializer.h"

Serializer::Serializer(string fileName, bool readingMode)
{
	#pragma warning(push)
	#pragma warning(disable: 4996)
	if (readingMode)
	{
		this->file = fopen(fileName.c_str(), "rb");
		setvbuf(file, NULL, _IOFBF, 1048576);
	}
	else
	{
		this->file = fopen(fileName.c_str(), "wb"); 
		setvbuf(file, NULL, _IOFBF, 1048576);
	}
	this->readingMode = readingMode;
	#pragma warning(push)
}

void Serializer::close()
{
	fclose(this->file);
}

bool Serializer::hasNext()
{
	return !feof(file);
}