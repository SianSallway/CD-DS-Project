#include "List.h"
#include <iostream>
#include <assert.h>

using namespace std;

//returns if the list is empty or not depending on if the head node is null
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

//adding a node to the start of the list assigning it the integer being passed in
void List::PushFront(int value)
{
	//set the current node to the value been added
	Node* currentNode = new Node(value);
	//set the current headNode to be the node next to currentNode
	currentNode->SetNext(headNode);
	//set currentNode to be the new headNode
	headNode = currentNode;

	// was list empty check?
	if (tailNode == nullptr)
		tailNode = headNode;

	//print the value added
	cout << "a value has been added to the front of the list Head Node: " << headNode->GetValue() << endl;
}

//adding an element to the end of the list assigning it the integer being passed in
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
		Node* currentNode = headNode;
		headNode = headNode->GetNext();
		delete currentNode;
		
		cout << "the front element has been deleted, the new first element is: " << headNode->GetValue() << endl;
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

//removes all elements from the list
void List::ClearList()
{ 
	while (true)
	{
		Node* currentNode = headNode;

		if (currentNode == nullptr) //if the headNode is equal to null then the list is empty or something went wrong
		{
			assert(currentNode == nullptr);
			break;
		}
		else if (currentNode != nullptr)
		{
			headNode = headNode->GetNext();
			delete currentNode;
		}

	}
}

//removes an element from the list by its value, this being the integer passed in
void List::Remove(int value)
{
	Node* currentNode = headNode; //set currentNode to be the headNode of list

	while (true)
	{
		if (currentNode == nullptr) //if the headNode is equal to null then the list is empty or something went wrong
		{
			assert(currentNode == nullptr);
		}

		if (currentNode->GetValue() == value) 	//compare headNode to currentNode, if they are the same set nextNode to headNode and delete currentNode
		{
			headNode = headNode->GetNext();
			delete currentNode;
			cout << value << " has been removed from the list" << endl;
			break;
		}
		else //if not the same get the next element in the list to compare
		{
			currentNode = currentNode->GetNext();	
		}
	}
}

//returns the amount of elements in the list
void List::Count()
{
	int counter = 0;
	Node* currentNode = headNode;

	while (true)
	{
		if (headNode == nullptr) //if the headNode is equal to null then the list is empty or something went wrong
		{
			cout << "The list has no elements" << endl;
			break;
		}
		else if (currentNode != nullptr) 	
		{
			counter += 1;
			currentNode = currentNode->GetNext();
		}
		else if (currentNode == nullptr) 
		{
			cout << "The list has " << counter <<" elements"<< endl;
			break;
		}
	}
}

List::List()
{
}

List::~List()
{
}
