#include "Node.h"

void Node::SetValue(int value)
{
	nodeValue = value;
}

int Node::GetValue()
{
	return nodeValue;
}

Node::Node(int value)
{
	SetValue(value);
}

void Node::SetNext(Node* next)
{
	nextNode = next;
}

Node* Node::GetNext()
{
	return nextNode;
}

Node::~Node()
{
}

