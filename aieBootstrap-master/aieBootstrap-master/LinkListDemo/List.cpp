#include "List.h"
#include <iostream>
#include <assert.h>

using namespace std;

//returns if the list is empty or not depending on if the head node is null
bool List::isEmpty() const
{
	return headNode == nullptr;
}

//loops through prints all elements to the console 
void List::PrintList()
{
	//set current node to the head node
	Node* currentNode = headNode;

	if (currentNode == nullptr) //if the headNode is equal to null then the list is empty or something went wrong
	{
		cout << "No list to print" << endl;
	}
	else
	{ 
		cout << currentNode->GetValue() << ", " << endl;

		while (true)
		{
			currentNode = currentNode->GetNext();

			if (currentNode->GetNext() == tailNode)
			{
				cout << currentNode->GetValue() << ", " << endl;
				cout << tailNode->GetValue() << endl;
				cout << "End of list" << endl;
				break;
			}

			cout << currentNode->GetValue() << ", " << endl;
		}
	}
	
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
	//set current node to the first element of the list
	Node* currentNode = headNode;

	if (currentNode != nullptr)
	{
		//set the new headnode to the node next to it
		headNode = currentNode->GetNext();

		//delete the previous head node
		delete currentNode;
		
		cout << "the front element has been deleted, the new first element is: " << headNode->GetValue() << endl;
	}
}

//removes a node from the back of the list 
void List::PopBack()
{
	//set current node to the first element of the list
	Node* currentNode = headNode;

	while (true)
	{
		if (currentNode != nullptr)
		{
			//if the node next to the current node is the tail node, current node will become the new tail node
			if (currentNode->GetNext() == tailNode)
			{
				//delete current tail node
				delete tailNode;

				//set tail node to the current node
				tailNode = currentNode;
				break;
			}
			else
			{
				currentNode = currentNode->GetNext();
			}
		}
	}
}

//loops through and removes all elements from the list
void List::ClearList()
{ 
	while (true)
	{
		//set current node to the first element of the list
		Node* currentNode = headNode;

		if (currentNode == nullptr) //if the headNode is equal to null then the list is empty or something went wrong
		{
			cout << "List is empty!" << endl;
			//assert(currentNode == nullptr);
			break;
		}
		else if (currentNode != nullptr)
		{
			//set the new headnode to the node next to it
			headNode = headNode->GetNext();

			cout << "Deleting: " << currentNode->GetNext() << endl;

			//delete the previous head node
			delete currentNode;
		}
	}
}

//removes an element from the list by its value, this being the integer passed in
void List::Remove(int value) //FIX
{
	Node* nodeToRemove;
	Node* currentNode = headNode; //set currentNode to be the headNode of list

	if (currentNode == nullptr) //if the headNode is equal to null then the list is empty or something went wrong
	{
		assert(currentNode == nullptr);
	}
	else
	{
		while (true)
		{
			if (currentNode->GetValue() == value) 	//compare headNode to currentNode, if they are the same set nextNode to headNode and delete currentNode
			{
				nodeToRemove = currentNode;
				currentNode = currentNode->GetNext();

				delete nodeToRemove;

				cout << value << " has been removed from the list" << endl;
				break;
			}
			else //if not the same get the next element in the list to compare
			{
				currentNode = currentNode->GetNext();
			}
		}
	}
	/*if (currentNode->GetValue() == value) 	//compare headNode to currentNode, if they are the same set nextNode to headNode and delete currentNode
	{
		headNode = headNode->GetNext();
		delete currentNode;
		cout << value << " has been removed from the list" << endl;
	}*/
}

//returns the amount of elements in the list
void List::Count()//FIX
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
