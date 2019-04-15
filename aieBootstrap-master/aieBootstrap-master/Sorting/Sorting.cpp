#include "pch.h"
#include <iostream>

using namespace std;

//iterates through each element from index 0 to n, and outputs it to std::cout
//don't forget to #include <iostream>
void print_array(int array[], int n)
{
	for (int i = 0; i != n; ++i)
	{
		cout << array[i] << ", \t";
		if (i % 10 == 9)
		{
			cout << endl;
		}
	}
}

//swaps the contents of a and b
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool Compare(int a, int b)
{
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BubbleSort(int array[], int length)
{
	//Bail for single element or invalid indices 
	if (length < 2)
	{
		return;
	}

	//Track if list is sorted 
	bool sorted = false; // set to false to ensure thewhile loop starts up 
	while (!sorted)
	{
		sorted = true;

		for (int i = 0; i != length - 1; i++)
		{
			if (Compare(array[i], array[i + 1]) == true)
			{
				swap(array[i], array[i + 1]);
				sorted = false;
			}
		}
	}
}

void InsertionSort(int array[], int length)
{

	for (int i = 0; i < length; i++)
	{
		int key = array[i];
		int j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;

			array[j + 1] = key;
		}
	}
}


int main()
{
	//Define our data
	const int array_size = 50;
	int array_to_be_sorted[array_size] = { 14,65,63,1,54,
										89,84,9,98,57,
										71,18,21,84,69,
										28,11,83,13,42,
										64,58,78,82,13,
										9,96,14,39,89,
										40,32,51,85,48,
										40,23,15,94,93,
										35,81,1,9,43,
										39,15,17,97,52 };


	//int* valuesToSort = new int[size];

	//Profile bubble sort 
	//memcpy(valuesToSort, value, sizeof(int)*size);

	//Print the unsorted array
	cout << "Unsorted\n" << endl;
	print_array(array_to_be_sorted, array_size);

	cout << "\n";

	BubbleSort(array_to_be_sorted, array_size);
	cout << "Bubble Sort \n" << endl;
	print_array(array_to_be_sorted, array_size);

	cout << "\n";
	cout << "Press any key to profile Insertion Sort\n";
	cin.get();
	cout << endl;

	InsertionSort(array_to_be_sorted, array_size);
	cout << "Insertion Sort\n" << endl;

	print_array(array_to_be_sorted, array_size);

	system("pause");
	return 0;
}

