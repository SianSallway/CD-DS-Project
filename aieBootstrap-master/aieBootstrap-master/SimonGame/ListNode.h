#pragma once
class ListNode
{
public:
	ListNode(int value);
	~ListNode();

	void SetValue(int value);
	void SetNext(ListNode* next);
	ListNode* GetNext();
	int GetValue();

private:

	ListNode * nextNode = nullptr;
	int nodeValue;

};

