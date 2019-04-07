#pragma once
#include <functional>


namespace HashFun {

	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;

	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length);

	// ADD YOUR FUNCTIONS HERE
	unsigned nameHash(const char* name, unsigned int length);


	// a helper to access a default hash function
	static HashFunc default = badHash;
}

class HashFunction
{
public:
	HashFunction();
	~HashFunction();

};

