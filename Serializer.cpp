#include "stdafx.h"
#include "Serializer.h"

Serializer::Serializer(bool readingMode)
{
	#pragma warning(push)
	#pragma warning(disable: 4996)
	if (readingMode)
	{
		this->file = fopen("new.kek", "rb");
	}
	else
	{
		this->file = fopen("new.kek", "wb");
	}
	this->readingMode = readingMode;
	#pragma warning(push)
}

void Serializer::close()
{
	fclose(this->file);
}