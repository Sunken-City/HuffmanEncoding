#pragma once
#include "Serializeable.h"
#include "Serializer.h"

//Simple object that contains a key-value pair of byte and frequency
class HuffmanData : public Serializeable
{
public:
	char byte;
	int frequency;

	HuffmanData()
	{
		this->frequency = 0;
		this->byte = 0;
	}

	HuffmanData(int frequency, char byte)
	{
		this->frequency = frequency;
		this->byte = byte;
	}

	bool operator< (HuffmanData& rhs)
	{
		//If the frequency is less than the rhs' frequency, return true.
		return this->frequency < rhs.frequency;
	}

	bool operator== (HuffmanData& rhs)
	{
		//If the data payload and frequency are equivalent, return true.
		return ((this->byte == rhs.byte) && (this->frequency == rhs.frequency));
	}

	void serialize(Serializer* write)
	{
		write->IO<int>(this->frequency);
		write->IO<char>(this->byte);
	}

	HuffmanData* reconstruct(Serializer* read)
	{
		HuffmanData* data = new HuffmanData();
		read->IO<int>(this->frequency);
		read->IO<char>(this->byte);
		return data;
	}
};