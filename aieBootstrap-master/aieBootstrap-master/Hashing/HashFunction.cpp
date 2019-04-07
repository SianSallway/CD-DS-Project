#include "HashFunction.h"

namespace HashFun {

	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length) {
		
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash += data[i];
		}

		return hash;
	}

	//My implementaions
	unsigned nameHash(const char* name, unsigned int length)
	{
		int hash = 100;
		
		for (int i = 0; i < length; i++)
		{
			hash += name[i];
		}

		return hash;
	}
}

HashFunction::HashFunction()
{
}


HashFunction::~HashFunction()
{
}


