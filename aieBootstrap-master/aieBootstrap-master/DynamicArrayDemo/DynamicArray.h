#pragma once
#include "ArrayElement.h"

class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	//creates array
	void CreateArray(int size);
	//adding a new element to the end of the array
	void AddToEnd(DynamicArray* array, ArrayElement* newElement);

protected:

	DynamicArray* dynArray;
	int memoryAllocated;
	int elementsUsed;

};

