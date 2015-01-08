#pragma once
#include <cstdio>
#include <string>

using namespace std;

class Serializer
{
public:
	Serializer(string fileName, bool readingMode);
	virtual ~Serializer();
	template<class T> void IO(T& IOable);
	void close();
	bool hasNext();

private:
	FILE* file;
	bool readingMode;
};

template<class T> void Serializer::IO(T& IOable)
{
	if (this->readingMode)
		fread(&IOable, sizeof(T), 1, this->file);
	else
		fwrite(&IOable, sizeof(T), 1, this->file);
}