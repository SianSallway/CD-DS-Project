#include "DynamicArray.h"

void DynamicArray::CreateArray(int size)
{
	DynamicArray array;

	//array.elementsUsed = new array[size];
	array.memoryAllocated = size;
	array.elementsUsed = 0;
}

//adding a new element to the end of the array
void DynamicArray::AddToEnd(DynamicArray* array, ArrayElement* newElement)
{
	/*if(array.memoryAllocated == array.elementsUsed)
	{
		newElement = new array[array.memoryAllocated * 2];
		copy(newElement, array.elementsUsed, array.memoryAllocated);
		delete array.elementsUsed;
		array.elementsUsed = newElement;
		array.memoryAllocated *= 2;
	}

	array.elementsUsed[]*/
}

DynamicArray::DynamicArray()
{
}


DynamicArray::~DynamicArray()
{
}
