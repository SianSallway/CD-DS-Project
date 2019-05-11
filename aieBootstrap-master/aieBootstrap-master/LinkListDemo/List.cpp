#include "List.h"

#include <iostream>

using namespace std;

//returns if the list is empty or not 
bool List::isEmpty() const
{
	return headNode == nullptr;
}


//return the first element by value, assert if no elements 
Node* List::First()
{
	return headNode;
}

//return the last element by value, assert if no elements 
Node* List::Last()
{
	return tailNode;
}


//adding a node to the start of the list 
void List::PushFront(int value)
{
	Node* currentNode = new Node(value);
	currentNode->SetNext(headNode);
	headNode = currentNode;

	// was list emoty check?
	if (tailNode == nullptr)
		tailNode = headNode;

	cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
}

//adding a node to the end of the list
void List::PushBack(int value)
{
	Node* currentNode = new Node(value);
	currentNode->SetNext(nullptr);

	if (tailNode != nullptr)
	{
		tailNode->SetNext(currentNode);
	}

	tailNode = currentNode;

	// was list emoty check?
	if (headNode == nullptr)
	{
		headNode = tailNode;

		cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
	}


	cout << "a value has been added to the end of the list Tail Node: " << tailNode->GetValue() << endl;
}


//removes the first node in the list 
void List::PopFront()
{
	if (headNode != nullptr)
	{
		//set list.headNode to list.headNode.next 

		//let n be list.headNode

		//delete n
	}
}

//removes a node from the back of the list 
void List::PopBack()
{
	if (tailNode != nullptr)
	{
		tailNode = nullptr;
	}
}

List::List()
{
}

List::~List()
{
}
