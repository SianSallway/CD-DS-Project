#pragma once
#include <functional>
#include "Application.h"
#include "Renderer2D.h"


namespace HashFun {

	typedef std::function< unsigned int(const char*, unsigned int)> HashFunc;

	// implementation of a basic addition hash
	//unsigned int badHash(const char* data, unsigned int length);

	// ADD YOUR FUNCTIONS HERE
	unsigned Hash(const char* name, unsigned int length);


	// a helper to access a default hash function
	static HashFunc default = Hash;
}

class HashFunction
{
public:
	HashFunction();
	~HashFunction();

private:

	aie::Texture* button1Texture;
	aie::Texture* buttonTexture;
};

