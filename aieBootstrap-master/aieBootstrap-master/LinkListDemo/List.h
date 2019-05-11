#pragma once
#include "Node.h"
class List
{
public:
	List();
	~List();

	//returns if the list is empty or not 
	bool isEmpty() const;
	//return the first element by value, assert if no elements 
	Node* First();
	//return the last element by value, assert if no elements 
	Node* Last();


	//---FUNTIONS FOR ADDING---

	//adding an element to the start of the list 
	void PushFront(int value);
	//adding an element to the end of the list
	void PushBack(int value);

	//---FUNTIONS FOR REMOVING--

	//removes the first node in the list 
	void PopFront();
	//removes a node from the back of the list 
	void PopBack();
	//removes an element from the list by its iterator
	void Erase(int iterator);
	//removes an element from the list by its value 
	void Remove(int value);
	//removes all elements from the list
	void ClearList(List* list);

private:

	Node * tailNode = nullptr;
	Node* headNode = nullptr;

};

