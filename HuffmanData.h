#pragma once


class HuffmanData
{
public:
	bool operator== (HuffmanData& rhs)
	{
		//If the data payload and frequency are equivalent, return true.
		return ((this->data == rhs.data) && (this->frequency == rhs.frequency));
	}

private:
	char data;
	int frequency;
};