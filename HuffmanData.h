#pragma once

//Simple object that contains a key-value pair of byte and frequency
class HuffmanData
{
public:
	char byte;
	int frequency;

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
};