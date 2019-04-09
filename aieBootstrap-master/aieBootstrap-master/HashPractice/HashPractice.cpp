#include "pch.h"
#include <iostream>

using namespace std;

namespace HashFunction {

	unsigned Hash(string data)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			hash += data[i];
			cout << "hash value is " <<  hash << endl;
		}

		return hash;
	}
}

int main()
{
	HashFunction::Hash("Hiya!!!");
}

