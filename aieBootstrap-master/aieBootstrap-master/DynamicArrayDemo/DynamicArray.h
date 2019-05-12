#pragma once

class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	//returns if the array is empty or not
	bool isEmpty();

	//adding a new element to the end of the array
	void AddToEnd(int newElement);
	//adds elements to the middle of the array
	void AddToMiddle(int newElement);
	//removing an element from the end of the array
	void RemoveEnd();
	//remove elements from the middle of the array
	void RemovePos(int position);
	//altering the size of the array
	void ExpandArray();
	//initializes array
	void Initialize(int position);
	//returns array index
	int GetIndex(int index);

protected:

	int* dynArray;		//pointer to array itself
	int capacity;		//the amount of memory allocated to the array
	int numOfElements;	//number of elements in the array

};

