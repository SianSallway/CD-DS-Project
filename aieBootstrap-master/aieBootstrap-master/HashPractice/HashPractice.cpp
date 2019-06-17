#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace HashFunction {

	unsigned SimpleHash(string data)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			hash += data[i];
			cout <<"SMPL: "<< data << "'s hash value is " << hash << endl;
		}

		return hash;
	}

	//Hash function written by Brian Kernighan and Dennis Ritchie that uses a single bit operation
	unsigned int ComplexHash(string data)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			hash += (hash * 1313) + data[i];
			cout <<"CPLX: " << data << "'s hash value is " << hash << "\n";
		}

		return (hash & 0x7FFFFFFF);
	}
}

int main()
{
	string userInput;

	cout << "Welcome User!!! \n";

	while (true)
	{
		cout << "\n";

		cout << "Please enter a sentence for the simple hash function \n";

		getline(cin, userInput);

		cout << "\n";

		HashFunction::SimpleHash(userInput);

		cout << "\n";

		cout << "Please enter a sentence for the complex hash function \n";

		getline(cin, userInput);

		cout << "\n";

		HashFunction::ComplexHash(userInput);

	}
}

