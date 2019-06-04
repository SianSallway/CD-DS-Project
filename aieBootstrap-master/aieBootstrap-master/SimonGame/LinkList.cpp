#include "LinkList.h"
#include <iostream>

using namespace std;

//returns if the list is empty or not depending on if the head node is null
bool LinkList::isEmpty() const
{
	return headNode == nullptr;
}

//returns the first element by value 
ListNode* LinkList::First()
{
	return headNode;
}

//returns the last element by value
ListNode* LinkList::Last()
{
	return tailNode;
}

//adding a node to the start of the list assigning it the integer being passed in
void LinkList::PushFront(int value)
{
	ListNode* currentNode = new ListNode(value);
	currentNode->SetNext(headNode);
	headNode = currentNode;

	// was list emoty check?
	if (tailNode == nullptr)
		tailNode = headNode;

	//print the value added
	cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
}

//adding an element to the end of the list assigning it the integer being passed in
void LinkList::PushBack(int value)
{
	//set the current node to the value being added to the list
	ListNode* currentNode = new ListNode(value);
	//set the node next to the current node to null, making the current node the end of the list 
	currentNode->SetNext(nullptr);

	//the value serving as the tailNode has its netxNode set to the value being added, making it the second last element in the list
	if (tailNode != nullptr)
	{
		tailNode->SetNext(currentNode);
	}

	//the tailNode is set to the currentNode(the new value being added)
	tailNode = currentNode;

	//if the list is empty then the headNode and tailNode are the same node
	if (headNode == nullptr)
	{
		headNode = tailNode;

		cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
	}

	//print the value added
	cout << "a value has been added to the end of the list Tail Node: " << tailNode->GetValue() << endl;
}

LinkList::LinkList()
{
}


LinkList::~LinkList()
{
}

