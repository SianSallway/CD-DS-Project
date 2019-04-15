#include "pch.h"
#include <iostream>

using namespace std;

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
}\

int Partition(int array[], int p, int r)
{
	int x = array[r];
	int i = p - 1;

	for (int j = p; j < r - 1; j++)
	{
		if (array[j] < x)
		{
			i = i + 1;
			swap(array[i], array[j]);
			swap(array[i + 1], array[r]);


			return i + 1;
		}
	}

}

void QuickSort(int array[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(array, p, r);

		QuickSort(array, p, q - 1);
		QuickSort(array, q + 1, r);
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


	//Print the unsorted array
	cout << "Unsorted\n" << endl;
	print_array(array_to_be_sorted, array_size);

	cout << "\n";

	/*BubbleSort(array_to_be_sorted, array_size);
	cout << "Bubble Sort \n" << endl;
	print_array(array_to_be_sorted, array_size);

	cout << "\n";
	cout << "Press any key to use Insertion Sort\n";
	cin.get();
	cout << endl;*/

	InsertionSort(array_to_be_sorted, array_size);
	cout << "Insertion Sort\n" << endl;

	print_array(array_to_be_sorted, array_size);

	/*cout << "\n";
	cout << "Press any key to use Quick Sort\n";
	cin.get();
	cout << endl;

	QuickSort(array_to_be_sorted, 0, array_size - 1);
	cout << "Quick Sort\n" << endl;

	print_array(array_to_be_sorted, array_size);*/

	system("pause");
	return 0;
}

