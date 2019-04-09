#pragma once
#include <string>
#include <vector>
#include "Resource.h"

using namespace std;

template<class T>
class ResourceManager
{
	vector<shared_ptr<Resource<T>> > m_resources;

	ResourceManager(const ResourceManager&) {};

	ResourceManager& operator = (const ResourceManager&) {};

public:

	ResourceManager() {};
	~ResourceManager() {};

	shared_ptr<Resource<T>> get(const string filename) 
	{
		vector< shared_ptr<Resource<T>> >::iterator it; 

		for (it = m_resources.begin(); it != m_resources.end(); it++)
		{
			if (filename.compare((*it)->getFilename()) == 0)
			{
				return (*it);
			}
		}

		shared_ptr<Resource<T>> resource(new Resource<T>(filename));
		m_resources.push_back(resource);

			return resource;
	}

	int getCount()
	{
		return m_resources.size();
	}

	void collectGarbage()
	{
		for (vector< shared_ptr<Resource<T>> >::iterator it = m_resources.begin(); it != m_resources.end();)
		{
			if ((*it).use_count() == 1)
			{
				it = m_resources.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

};

