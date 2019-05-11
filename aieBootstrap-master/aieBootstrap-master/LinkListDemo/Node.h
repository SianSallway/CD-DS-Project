#pragma once
class Node
{
public:
	Node(int value);
	~Node();

	void SetValue(int value);
	void SetNext(Node* next);
	Node* GetNext();
	int GetValue();

private:

	Node * nextNode = nullptr;
	int nodeValue;
};

