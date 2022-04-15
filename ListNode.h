
#pragma once
class ListNode
{
private:
	int nodeData;
	ListNode* nextListNode;

public:
	ListNode();
	ListNode(int data);
	ListNode(int data, ListNode* nextNode);
	void SetData(int dataToSet);
	void SetNext(ListNode* nextNode);
	int GetData();
	ListNode* GetNextNode();
};

