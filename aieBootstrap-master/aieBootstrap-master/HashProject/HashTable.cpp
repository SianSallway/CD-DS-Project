#include "HashTable.h"
#include <iostream>

using namespace std;

//Hash function written by Brian Kernighan and Dennis Ritchie that uses a single bit operation
unsigned int HashTable::HashFunction(const string& key) const
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < key.size(); ++i)
	{
		hash += (hash * 1313) + key[i];
	}

	cout << "Hash Value: " << hash << "\n";

	return (hash & 0x7FFFFFFF);
}