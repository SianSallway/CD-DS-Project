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
	HashTable(unsigned int size) : m_size(size), m_data(new aie::Texture*[size]) {}
	~HashTable() { delete[] m_data; }

	aie::Texture*& operator[] (const string& key)
	{
		auto hashedKey = HashFunction(key) % m_size; 
		
		cout << "Key: " << hashedKey << "\n";

		return m_data[hashedKey];
	}

private:

	// ideally this would be a std::function
	// specified as a template parameter
	unsigned int HashFunction(const string& key) const;
	
	aie::Texture** m_data;
	unsigned int m_size;
};

