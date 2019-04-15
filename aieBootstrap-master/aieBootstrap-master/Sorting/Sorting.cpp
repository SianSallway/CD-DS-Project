#include "pch.h"
#include <iostream>

using namespace std;

void PrintArray(int array[], int n)
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
void Swap(int& a, int& b)
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
				Swap(array[i], array[i + 1]);
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

	for (int j = p; j <= r - 1; j++)
	{
		if (array[j] <= x)
		{
			i = i + 1;
			Swap(array[i], array[j]);
		}
	}
	Swap(array[i + 1], array[r]);

	return i + 1;
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

void Merge(int array[], int startIndex, int midIndex, int endIndex)
{
	//cout << "Merge: start " << startIndex << " mid: " << midIndex << " end: " << endIndex << endl;

	int leftEnd = midIndex - startIndex + 1;	// last index in left array
	int rightEnd = endIndex - midIndex;			// last index in right array
	//cout << "leftEnd: " << leftEnd << "   rightEnd: " << rightEnd << endl;

	int* leftArray = new int[leftEnd + 1];
	int* rightArray = new int[rightEnd + 1];

	for (int i = 0; i < leftEnd; i++)
	{
		leftArray[i] = array[startIndex + i];


	}

	for (int j = 0; j < rightEnd; j++)
	{
		rightArray[j] = array[midIndex + j + 1];
	}

	int i = 0;
	int j = 0;

	for (int k = startIndex; k < endIndex; k++)
	{
		if (j >= rightEnd || i < leftEnd && leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i = i + 1;
		}
		else 
		{
			array[k] = rightArray[j];
			j = j + 1;
		}
	} 

	delete[] leftArray;
	delete[] rightArray;
}

void MergeSort(int array[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int q = (startIndex + endIndex) / 2;
		MergeSort(array, startIndex, q);
		MergeSort(array, q + 1, endIndex);
		Merge(array, startIndex, q, endIndex);
	}
}

int main()
{
	//Define our data
	const int arraySize = 50;
	int arrayToSort[arraySize] = { 14,65,63,1,54,
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
	PrintArray(arrayToSort, arraySize);

	cout << "\n";

	/*BubbleSort(arrayToSort, arraySize);
	cout << "Bubble Sorted \n" << endl;
	PrintArray(arrayToSort, arraySize);

	cout << "\n";
	cout << "Press any key to use Insertion Sort\n";
	cin.get();
	cout << endl; */

	InsertionSort(arrayToSort, arraySize);
	cout << "Insertion Sorted\n" << endl;

	PrintArray(arrayToSort, arraySize);

	/*cout << "\n";
	cout << "Press any key to use Quick Sort\n";
	cin.get();
	cout << endl;*/

	/*QuickSort(arrayToSort, 0, arraySize - 1);
	cout << "Quick Sorted\n" << endl;

	PrintArray(arrayToSort, arraySize);*/

	cout << "\n";
	cout << "Press any key to use Merge Sort\n";
	cin.get();
	cout << endl;

	MergeSort(arrayToSort, 0, arraySize - 1);
	cout << "Merge Sorted\n" << endl;

	PrintArray(arrayToSort, arraySize);

	system("pause");
	return 0;
}

