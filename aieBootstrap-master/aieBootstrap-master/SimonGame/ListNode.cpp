#include "ListNode.h"

void ListNode::SetValue(int value)
{
	nodeValue = value;
}

int ListNode::GetValue()
{
	return nodeValue;
}

ListNode::ListNode(int value)
{
	SetValue(value);
}

void ListNode::SetNext(ListNode* next)
{
	nextNode = next;
}

ListNode* ListNode::GetNext()
{
	return nextNode;
}

ListNode::~ListNode()
{
}
