
#pragma once
#include "ListNode.h"
class LinkedList
{
private:
	ListNode* listHead;
	ListNode* lastListElement;
	unsigned int elementsCount;

public:
	LinkedList();
	LinkedList(int elements[], unsigned int count);
	~LinkedList();

	ListNode* FirstElement();
	void Add(int data);
	bool Insert(int dataToInsert, unsigned int position);
	bool RemoveFirst();
	bool RemoveByData(int data);
	bool RemoveAllByData(int data);
	void ClearList();
	bool Update(unsigned int position, int newData);
	bool UpdateByData(int currentData, int newData);

};

