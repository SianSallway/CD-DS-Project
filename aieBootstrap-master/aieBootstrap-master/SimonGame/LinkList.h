#pragma once
#include "ListNode.h"
class LinkList
{
public:
	LinkList();
	~LinkList();

	//returns if the list is empty or not 
	bool isEmpty() const;
	//returns an iterator to the first element of the list
	//return the first element by value, assert if no elements 
	ListNode* First();
	//return the last element by value, assert if no elements 
	ListNode* Last();

	//---FUNTIONS FOR ADDING---

	//adding an element to the start of the list 
	void PushFront(int value);
	//adding an element to the end of the list
	void PushBack(int value);


private:

	ListNode * tailNode = nullptr;
	ListNode* headNode = nullptr;

};

