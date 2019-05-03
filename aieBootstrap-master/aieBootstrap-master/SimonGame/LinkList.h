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
	void Begin();
	//returns an iterator to a null element of the list
	void End();
	//return the first element by value, assert if no elements 
	ListNode* First();
	//return the last element by value, assert if no elements 
	ListNode* Last();


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
	void ClearList(LinkList* list);

private:

	ListNode * tailNode = nullptr;
	ListNode* headNode = nullptr;

};

