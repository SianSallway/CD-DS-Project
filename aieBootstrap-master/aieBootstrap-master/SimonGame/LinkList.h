#pragma once
#include "ListNode.h"

//handles the methods and organisation of the link list 
class LinkList
{
public:
	LinkList();
	~LinkList();

	//returns if the list is empty or not depending on if the head node is null
	bool isEmpty() const;
	//return the first element by value, assert if no elements 
	ListNode* First();
	//return the last element by value, assert if no elements 
	ListNode* Last();

	//---FUNTIONS FOR ADDING---

	//adding a node to the start of the list assigning it the integer being passed in
	void PushFront(int value);
	//adding an element to the end of the list assigning it the integer being passed in
	void PushBack(int value);


private:

	ListNode * tailNode = nullptr;	//ListNode type that points to the the value stored at the end of the list 
	ListNode* headNode = nullptr;	//ListNode type that points to the the value stored at the start of the list 

};

