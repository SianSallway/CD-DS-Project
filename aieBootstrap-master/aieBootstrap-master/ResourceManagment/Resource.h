#pragma once
#include <string>

using namespace std;

template<class T>
class Resource
{
public:
	Resource(const string& filename) : m_filename(filename)
	{
		m_data = unique_ptr<T>(new T(filename.c_str()));
	};

	~Resource() {};

	T* getData() const
	{
		return m_data.get();
	}

private: 

	unique_ptr<T> m_data;
	string m_filname;

};

