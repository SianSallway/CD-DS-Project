#pragma once

//handles the behaiviour and properties of each list element
class Node
{
public:

	//creates a new node to be added to the list and passes in a integer to be set to the node by calling the SetValue function
	Node(int value);
	~Node();

	//passes in an integer to be stored in the nodeValue variable
	void SetValue(int value);
	//passes in a node to be added or moved next to another node in the list
	void SetNext(Node* next);
	//returns the value stored in the node next to another chosen node
	Node* GetNext();
	//returns the value stored in the nodeValue variable that has been assigned to a node
	int GetValue();

private:

	Node * nextNode = nullptr;	//ListNode type that points to the value stored in the next element of the list
	int nodeValue;				//stores an integer value that will be assigned to a node
};

