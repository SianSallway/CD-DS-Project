#include "DynamicArray.h"
#include <assert.h>
#include <iostream>

using namespace std;

DynamicArray::DynamicArray()
{
	capacity = 10;					//default size
	numOfElements = 0;				//no elements in array when created
	dynArray = new int[capacity];	//array of integers

	//initialise every element in the list to 0
	for ( int i = 0; i < capacity; i++)
	{
		dynArray[i] = 0;
	}

	nextIndex = 0;
	endIndex = 0;
}

DynamicArray::~DynamicArray()
{
	//ISSUE???
	delete [] dynArray; //frees memory 
	cout << "The array has been deleted" << endl;
}

//override [] operator
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

	//creating a new array that is larger to copy the original arrays data into
	int* tempArray = new int[capacity]; 

	//copying over the previous arrays data into the temp array
	for (int i = 0; i < nextIndex; i++) 
	{
		tempArray[i] = dynArray[i];
	}

	//initialise the remainder
	for (int j = nextIndex; j < capacity; j++)
	{
		tempArray[j] = 0;
	}

	//delete the old array
	delete[]dynArray;

	//assign array pointer to the new array
	dynArray = tempArray;
}

//returns if the array is empty or not
bool DynamicArray::isEmpty()
{
	//if the number of elements is 0 the list is infact empty
	if (numOfElements == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns array capacity
int DynamicArray::Size()
{
	return capacity;
}

//prints all array elements to the console 
void DynamicArray::PrintArray()
{
	cout << "------------------" << endl;

	for (int i = 0; i < Size(); ++i)
	{
		cout << dynArray[i] << " ";
	}

	cout << "\n";
	cout << "------------------" << endl;
}

//sorts array elements using insertion sort 
void DynamicArray::SortArray()
{
	for (int i = 0; i < Size(); i++)
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

	//print array now sorted 
	PrintArray();
}

//adding a new element to the end of the array
void DynamicArray::AddToEnd(int newElement)
{
	//if the number of elements has reached or exceeded the arrays capacity then expand it
	if (nextIndex == capacity) 
	{
		ExpandArray(newElement);
	}

	dynArray[nextIndex++] = newElement;
	
	//the number of elements in array has increased
	numOfElements++;
	endIndex = newElement;

	cout << "Added: " << newElement << endl;
	cout << "No. elements: " << numOfElements << endl;
	cout << "Next Index: " << nextIndex << endl;

	//print array now with new added element
	PrintArray();
}

//adds elements to the middle of the array
void DynamicArray::AddToMiddle(int newElement)
{
	//position the new element will be added is the middle of the array 
	int position = capacity / 2;

	int* tempArray = new int[capacity + 1];

	for (int i = 0; i < Size(); ++i)
	{
		//copy over all elements before the position 
		if (i < position)
		{
			tempArray[i] = dynArray[i];
		}

		//insert the new element at the position
		if (i == position)
		{
			tempArray[i] = newElement;
		}

		//copy over all elements after the position
		if (i > position)
		{
			tempArray[i] = dynArray[i - 1];
		}
	}

	//delete old array
	delete[] dynArray;

	//assign pointer to new array with new value
	dynArray = tempArray;

	//print array now with the new element added to the center
	PrintArray();
}

//removing an element from the end of the array
void DynamicArray::RemoveEnd()
{
	if (isEmpty())
	{
		cout << "list is already empty" << endl;
	}
	else
	{
		dynArray[numOfElements - 1] = 0;
		
		//the number of elements in array has decreased
		numOfElements -= 1;

		cout << "The last element of the array has been removed" << endl;
		cout << "No. elements: " << numOfElements << endl;
	}
	//print array now with the last element removed
	PrintArray();
}

//FIX
//remove elements from the middle of the array
void DynamicArray::RemoveElement(int element)
{
	int* tempArray = new int[capacity];

	//loop through elements and compare each one to element entered
	for (int i = 0; i < Size(); ++i)
	{
		//if the element entered is found
		if (dynArray[i] == element)
		{
			tempArray[i] = 0;

			//the number of elements in array has decreased
			numOfElements -= 1;

			//loop thorugh remaining elements and stop one element before the end of array
			for (int j = i; j < Size() - 1; j++)
			{
				if (j == endIndex)
				{
					//overwrite the end elements next index with 0;
					tempArray[j - 1] = 0;
					break;
				}
				else
				{
					//overwrite the current element with the next, deleting entered element and shifts all other down one
					tempArray[j] = dynArray[j + 1];
				}
			}

			break;
		}
		else
		{
			tempArray[i] = dynArray[i];
		}
	}

	delete[] dynArray;

	dynArray = tempArray;

	//print new array with element removed
	PrintArray();
}

//clears all array elements
void DynamicArray::EmptyArray()
{
	//loops through every element and initialises them to 0
	for (int i = 0; i < Size(); ++i)
	{
		dynArray[i] = 0;
	}

	PrintArray();
}