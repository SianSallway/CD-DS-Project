#pragma once
class ListNode
{
public:
	ListNode(int value);
	~ListNode();

	void SetValue(int value);
	void SetNext(ListNode* next);
	ListNode* GetNext();

private:

	ListNode * nextNode = nullptr;
	int nodeValue;

};

