#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace HashFunction {

	unsigned Hash(string data)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			hash += data[i];
			cout << data << "'s hash value is " << hash << endl;
		}

		return hash;
	}
}

int main()
{
	string userInput;

	cout << "Welcome User!!! \n";

	while (true)
	{
		cout << "\n";

		cout << "Please enter a sentence to evaluate \n";

		getline(cin, userInput);

		cout << "\n";

		HashFunction::Hash(userInput);

	}

}

