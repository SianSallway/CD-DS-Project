#pragma once

//handles the behaiviour and properties of each list element
class ListNode
{
public:
	
	//creates a new node to be added to the list and passes in a integer to be set to the node by calling the SetValue function
	ListNode(int value);
	~ListNode();

	//passes in an integer to be stored in the nodeValue variable
	void SetValue(int value);
	//passes in a node to be added or moved next to another node in the list
	void SetNext(ListNode* next);
	//returns the value stored in the node next to another chosen node
	ListNode* GetNext();
	//returns the value stored in the nodeValue variable that has been assigned to a node
	int GetValue();

private:

	ListNode * nextNode = nullptr; //ListNode type that points to the value stored in the next element of the list
	int nodeValue;				   //stores an integer value that will be assigned to a node
};

