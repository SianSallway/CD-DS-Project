#include "Node.h"

//passes in an integer to be stored in the nodeValue variable
void Node::SetValue(int value)
{
	nodeValue = value;
}

//returns the value stored in the nodeValue variable that has been assigned to a node
int Node::GetValue()
{
	return nodeValue;
}

//creates a new node to be added to the list and passes in a integer to be set to the node by calling the SetValue function
Node::Node(int value)
{
	SetValue(value);
}

//passes in a node to be added or moved next to another node in the list
void Node::SetNext(Node* next)
{
	nextNode = next;
}

//returns the value stored in the node next to another chosen node
Node* Node::GetNext()
{
	return nextNode;
}

Node::~Node()
{
}

