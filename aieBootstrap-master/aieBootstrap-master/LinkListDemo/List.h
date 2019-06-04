#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Node.h"

//handles the methods and organisation of the link list 
class List
{
public:
	List();
	~List();

	//returns if the list is empty or not depending on if the head node is null
	bool isEmpty() const;
	//return the first element by value, assert if no elements 
	Node* First();
	//return the last element by value, assert if no elements 
	Node* Last();

	//---FUNTIONS FOR ADDING---

	//adding a node to the start of the list assigning it the integer being passed in 
	void PushFront(int value);
	//adding an element to the end of the list assigning it the integer being passed in
	void PushBack(int value);

	//---FUNTIONS FOR REMOVING--

	//removes the first node in the list 
	void PopFront();
	//removes a node from the back of the list 
	void PopBack();
	//removes an element from the list by its value, this being the integer passed in
	void Remove(int value);
	//removes all elements from the list
	void ClearList();
	//returns the amount of elements in the list
	void Count();

private:

	Node * tailNode = nullptr;	//ListNode type that points to the the value stored at the end of the list
	Node* headNode = nullptr;	//ListNode type that points to the the value stored at the start of the list 

};

