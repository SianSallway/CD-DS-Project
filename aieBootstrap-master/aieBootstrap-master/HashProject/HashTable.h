#pragma once
#include <string>
#include "Application.h"
#include "Renderer2D.h"
#include "Texture.h"
#include <iostream>

using namespace std;

class HashTable
{
public:
	HashTable(unsigned int tableSize) : size(tableSize), data(new aie::Texture*[tableSize]) {}
	~HashTable() { delete[] data; }

	aie::Texture*& operator[] (const string& key)
	{
		cout << "Entered: " << key << "\n";

		auto hashedKey = HashFunction(key) % size;
		
		cout << "Hashed Key: " << hashedKey << "\n";

		return data[hashedKey];
	}

private:

	// ideally this would be a std::function
	// specified as a template parameter
	unsigned int HashFunction(const string& key) const;
	
	aie::Texture** data;
	unsigned int size;
};

