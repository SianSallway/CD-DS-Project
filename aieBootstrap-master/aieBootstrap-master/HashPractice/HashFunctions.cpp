#include "pch.h"
#include "HashFunctions.h"
#include <string>
#include <iostream>

using namespace std;

namespace HashFunction {

	unsigned Hash(string data)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			hash += data[i];
		}

		return hash;



	}
}

HashFunctions::HashFunctions()
{
	HashFunction::Hash("Hiya!!!");

}


HashFunctions::~HashFunctions()
{
}
