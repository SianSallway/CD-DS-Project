#include "LinkList.h"
#include <iostream>

using namespace std;

//returns if the list is empty or not 
bool LinkList::isEmpty() const
{
	return headNode == nullptr;
}

//returns an iterator to the first element of the list
void LinkList::Begin()
{

}

//returns an iterator to a null element of the list
void LinkList::End()
{

}

//return the first element by value, assert if no elements 
ListNode* LinkList::First()
{
	return headNode;
}

//return the last element by value, assert if no elements 
ListNode* LinkList::Last()
{
	return tailNode;
}


//adding a node to the start of the list 
void LinkList::PushFront(int value)
{
	ListNode* currentNode = new ListNode(value);
	currentNode->SetNext(headNode);
	headNode = currentNode;
	cout << "a value has been added to the front of the list Head Node: " << headNode << endl;

}

//adding a node to the end of the list
void LinkList::PushBack(int value)
{
	//checks for empty or end
	if (isEmpty())
	{
		cout << "This list is empty!\n" << endl;
		PushFront(value);
	}
	else
	{
		ListNode* currentNode = new ListNode(value);
		currentNode->SetNext(nullptr);
		tailNode = currentNode;

		cout << "a value has been added to the end of the list Tail Node: " << tailNode << endl;
	}


}


//removes the first node in the list 
void LinkList::PopFront()
{
	if (headNode != nullptr)
	{
		//set list.headNode to list.headNode.next 

		//let n be list.headNode

		//delete n
	}
}

//removes a node from the back of the list 
void LinkList::PopBack()
{
	if (tailNode != nullptr)
	{
		tailNode = nullptr;
	}
}

LinkList::LinkList()
{
}


LinkList::~LinkList()
{
}

