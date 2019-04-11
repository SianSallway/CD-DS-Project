#pragma once
#include <string>
#include <vector>
#include <memory>

//to be updated
using namespace std;

template<class T, class...Targs>
class ResourceManager
{
	//vector<shared_ptr<Resource<T>> > m_resources;
	map<string, shared_ptr<T>> m_map;

	ResourceManager(const ResourceManager&) {};

	ResourceManager& operator = (const ResourceManager&) {};

public:

	ResourceManager() {};
	~ResourceManager() {};

	shared_ptr<Resource<T>> get(const string filename, Targs...args)//edited
	{
		map<string, shared_ptr<T>>::iterator it = m_map.find(filename);
		
		if (it == m_map.end())
		{
			shared_ptr<T> resource(new T(filename.c_str()));
			it = m_map.insert(it, pair< string, shared_ptr<T> >(filename, resource))
		}
	
			return (*it).second;
	}

	int getCount()
	{
		return m_map.size();
	}

	void collectGarbage()
	{
		for (map< string, shared_ptr<T>>::iterator it = m_map.begin(); it != m_map.end();)
		{
			if (it->.use_count() == 1)
			{
				m_map.erase(it++);
			}
			else
			{
				++it;
			}
		}
	}

};

