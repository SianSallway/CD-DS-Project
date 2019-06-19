#include "DynamicArray.h"
#include <assert.h>
#include <iostream>

using namespace std;

DynamicArray::DynamicArray()
{
	capacity = 10; //default size
	numOfElements = 0; //no elements in array when created
	dynArray = new int[capacity]; //array of integers

	for ( int i = 0; i < capacity; i++)
	{
		dynArray[i] = 0;
	}

	nextIndex = 0;
}

DynamicArray::~DynamicArray()
{
	delete [] dynArray; //frees memory 
	cout << "The array has been deleted" << endl;
}

int& DynamicArray::operator [] (int index)
{	
	//this element in the array? if not allocate a bigger array
	if (index >= capacity)
	{
		ExpandArray(index);
	}

	//if the index is greater than the capacity 
	if (index > capacity)
	{
		nextIndex = index + 1;
	}

	//a reference to the element 
	return *(dynArray + index);
}

//altering the size of the array
void DynamicArray::ExpandArray(int index)
{
	//doubling the capacity of the array
	capacity = index + 10;

	int* tempArray = new int[capacity]; //creating a new array that is larger to copy the original arrays data into

	for (int i = 0; i < nextIndex; i++) //copying over the previous arrays data
	{
		tempArray[i] = dynArray[i];
	}

	for (int j = nextIndex; j < capacity; j++)
	{
		tempArray[j] = 0;
	}

	delete[]dynArray;

	dynArray = tempArray;

	//Initialize(numOfElements);
}

//returns if the array is empty or not
bool DynamicArray::isEmpty()
{
	if (numOfElements == 0)
	{
		return true;
	}
}

int DynamicArray::Size()
{
	return capacity;
}

//prints all array elements to the console 
void DynamicArray::PrintArray(DynamicArray array)
{
	cout << "------------------" << endl;

	for (int i = 0; i < Size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
	cout << "------------------" << endl;
}

//sorts array elements using insertion sort 
void DynamicArray::SortArray()
{
	for (int i = 0; i < capacity; i++)
	{
		int key = dynArray[i];
		int j = i - 1;

		while (j >= 0 && dynArray[j] > key)
		{
			dynArray[j + 1] = dynArray[j];

			j = j - 1;

			dynArray[j + 1] = key;
		}
	}
}

//adding a new element to the end of the array
void DynamicArray::AddToEnd(int newElement)
{
	if (nextIndex == capacity) //if the number of elements has reached or exceeded the arrays capacity then expand it
	{
		ExpandArray(newElement);
	}
	/*else
	{
		dynArray[numOfElements + 1] = newElement;
		cout << "Element has been added to the end of the array: " << newElement << endl;
		cout << "Number of elements: " << numOfElements << endl;
	}*/

	dynArray[nextIndex++] = newElement;
	cout << "Added: " << newElement << endl;
}

//adds elements to the middle of the array
void DynamicArray::AddToMiddle(int newElement)
{
	int position = numOfElements / 2; //middle of array

	for (size_t i = 0; i < position; i++)
	{
		dynArray[position] = newElement;
		cout << "Element has been added to the middle of the array: " << newElement << endl;
	}

	//cout << dynArray[capacity] << " " << endl;

}

//removing an element from the end of the array
void DynamicArray::RemoveEnd()
{
	if (isEmpty())
	{
		cout << "Array is empty" << endl;
	}
	else
	{
		dynArray[numOfElements - 1] = 0;
		cout << "The last element of the array has been removed" << endl;
	}
}

//remove elements from the middle of the array
void DynamicArray::RemovePos(int position)
{
	int* tempArray = new int[capacity];

	for (size_t i = position; i < numOfElements; i++) //copying the arrays data up one slot
	{
		tempArray[i] = dynArray[i];
		dynArray[i] = dynArray[i + 1];
		tempArray = dynArray;
	}
	//cout << dynArray[capacity] << " " << endl;
}

//initializes array
void DynamicArray::Initialize(int position)
{
	for (size_t i = position; i < capacity; i++)
	{
		dynArray[i] = 0;
	}
}

//returns array index
int DynamicArray::GetIndex(int index)
{
	if (index < 0 || index >= numOfElements)
	{
		assert(index < 0 || index >= numOfElements);
	}

	return index;
}