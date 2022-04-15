#include "ListNode.h"
ListNode::ListNode()
{
	nodeData = 0;
	nextListNode = nullptr;
}

ListNode::ListNode(int data)
{
	nodeData = data;
	nextListNode = nullptr;
}

ListNode::ListNode(int data, ListNode* nextNode)
{
	nodeData = data;
	nextListNode = nextNode;
}

void ListNode::SetData(int dataToSet)
{
	nodeData = dataToSet;
}

void ListNode::SetNext(ListNode* nextNode)
{
	nextListNode = nextNode;
}

int ListNode::GetData()
{
	return nodeData;
}
ListNode* ListNode::GetNextNode()
{
	return nextListNode;
}