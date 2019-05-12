#include "DynamicArray.h"
#include <assert.h>
#include <iostream>

using namespace std;

//returns if the array is empty or not
bool DynamicArray::isEmpty()
{
	if (numOfElements == 0)
	{
		return true;
	}
}

//adding a new element to the end of the array
void DynamicArray::AddToEnd(int newElement)
{
	if (numOfElements >= capacity) //if the number of elements has reached or exceeded the arrays capacity then expand it
	{
		ExpandArray();
	}
	else
	{
		dynArray[numOfElements + 1] = newElement;
		cout << "Element has been added to the end of the array: " << newElement << endl;
	}
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

//initializes array
void DynamicArray::Initialize(int position)
{
	for (size_t i = position; i < capacity; i++)
	{
		dynArray[i] = 0;
	}
}

//altering the size of the array
void DynamicArray::ExpandArray()
{
	capacity *= 2; //doubling the capacity of the array

	int* tempArray = new int[capacity]; //creating a new array that is larger to copy the original arrays data into

	for (size_t i = 0; i < numOfElements; i++) //copying over the previous arrays data
	{
		tempArray[i] = dynArray[i];
	}

	delete[]dynArray;

	dynArray = tempArray;

	Initialize(numOfElements);
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

DynamicArray::DynamicArray()
{
	capacity = 10; //default size
	numOfElements = 0; //no elements in array when created
	dynArray = new int[capacity]; //array of integers
}

DynamicArray::~DynamicArray()
{
	delete [] dynArray; //frees memory 
}
