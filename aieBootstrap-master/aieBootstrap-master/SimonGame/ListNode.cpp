#include "ListNode.h"

//passes in an integer to be stored in the nodeValue variable
void ListNode::SetValue(int value)
{
	nodeValue = value;
}

//returns the value stored in the nodeValue variable that has been assigned to a node
int ListNode::GetValue()
{
	return nodeValue;
}

//creates a new node to be added to the list and passes in a integer to be set to the node by calling the SetValue function
ListNode::ListNode(int value)
{
	SetValue(value);
}

//passes in a node to be added or moved next to another node in the list
void ListNode::SetNext(ListNode* next)
{
	//sets the node to be moved or added to the nextNode variable 
	nextNode = next;
}

//returns the value stored in the node next to another chosen node
ListNode* ListNode::GetNext()
{
	return nextNode;
}

ListNode::~ListNode()
{
}
