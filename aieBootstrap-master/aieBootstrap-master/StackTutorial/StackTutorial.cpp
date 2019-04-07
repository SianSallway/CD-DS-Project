// StackTutorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> pracStack;

	cout << "The stack size is: " << pracStack.size() << endl;

	pracStack.push(5);

	cout << "The stack size is now: " << pracStack.size() << endl;


	
}


