#pragma once
#include <iostream>
#include <string>
#include <memory>

using namespace std;

template<class T>
class Resource
{
public:
	
	Resource(const string& filename) : m_filename(filename) { m_data = std::unique_ptr<T>(newT(filename.c_str())); };

	~Resource() {};

	string getFilename()
	{
		return m_filename;
	};


private:

	unique_ptr<T> m_data;
	string m_filename;
};

