#pragma once

//handles the methods and organisation of the link list 
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	//override [] operator
	int& operator [] (int index);
	//returns if the array is empty or not
	bool isEmpty();
	//adding a new element to the end of the array
	void AddToEnd(int newElement);
	//adds elements to the middle of the array
	void AddToMiddle(int newElement);
	//removing an element from the end of the array
	void RemoveEnd();
	//remove elements from the middle of the array
	void RemoveElement(int position);
	//clears all array elements
	void EmptyArray();
	//altering the size of the array
	void ExpandArray(int index);
	//initializes array
	void Initialize(int position);
	//returns array index
	int GetIndex(int index);
	//returns array capacity
	int Size();
	//sorts array elements using insertion sort 
	void SortArray();
	//prints all array elements to the console 
	void PrintArray();

protected:

	int* dynArray;		//pointer to array itself
	int capacity;		//the amount of memory allocated to the array
	int numOfElements;	//number of elements in the array
	int endIndex;		//index of the element at the end of the array

};

