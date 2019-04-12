#include "HashFunction.h"
#include <string>
#include <iostream>

using namespace std;

unsigned Hash(string data)
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < data.size(); ++i)
	{
		hash += data[i];
	}

	return hash;

	cout << hash << endl;

}

HashFunction::HashFunction()
{
	
}


HashFunction::~HashFunction()
{
}


