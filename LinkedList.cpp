#include "LinkedList.h"
LinkedList::LinkedList()
{
	elementsCount = 0;
	lastListElement = nullptr;
	listHead = nullptr;
}

LinkedList::LinkedList(int elements[], unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		Add(elements[i]);
	}
}

LinkedList::~LinkedList()
{
	ClearList();
}

ListNode* LinkedList::FirstElement()
{
	return listHead;
}

void LinkedList::Add(int data)
{
	ListNode* newNode = new ListNode(data);
	if (listHead == nullptr)
	{
		listHead = newNode;
	}

	if (lastListElement)
	{
		lastListElement->SetNext(newNode);
	}
	elementsCount++;
	lastListElement = newNode;
}

bool LinkedList::Insert(int dataToInsert, unsigned int position)
{
	unsigned int currentPosition = 0;

	if (position > elementsCount)
		return false;

	ListNode* listIterator = listHead;
	while (currentPosition < position)
	{
		ListNode* currentNode = listIterator;
		listIterator = listIterator->GetNextNode();
		currentPosition++;
		if (currentPosition == position)
		{
			ListNode* newNode = new ListNode(dataToInsert, listIterator);
			currentNode->SetNext(newNode);
			elementsCount++;
		}
	}

	return true;
}

bool LinkedList::RemoveFirst()
{
	if (listHead != nullptr)
	{
		ListNode* currentHead = listHead;
		listHead = listHead->GetNextNode();
		elementsCount--;
		delete currentHead;
		return true;
	}
	return false;
}
bool LinkedList::RemoveByData(int data)
{
	ListNode* listIterator = listHead;
	if (listIterator == nullptr)
		return false;
	else
		if (listIterator->GetData() == data)
		{
			RemoveFirst();
			return true;
		}
		else
		{
			while (listIterator->GetNextNode()->GetData() != data && listIterator->GetNextNode()->GetNextNode()!=nullptr)
			{
				listIterator = listIterator->GetNextNode();
			}
			if (listIterator->GetNextNode()->GetNextNode() == nullptr && listIterator->GetNextNode()->GetData()!=data)
			{
			
				return false;
			}
			else
			{
				ListNode* currentNode = listIterator->GetNextNode();
				listIterator->SetNext(currentNode->GetNextNode());
				elementsCount--;
				if (currentNode == lastListElement)
				{   
					listIterator->SetNext(nullptr);
					lastListElement = listIterator;
				}
				delete currentNode;
				return true;
			}
		}
	
	//to be implemented

	//return false;
}
bool LinkedList::RemoveAllByData(int data)
{
	int ok = 0;
	if (listHead == nullptr)
		return false;
	else
	{
		while (listHead->GetData() == data && listHead!=nullptr)
		{
			RemoveFirst();
			ok++;
		}
		if (elementsCount > 1)
		{
			ListNode* listIterator = listHead;
			while  (listIterator->GetNextNode()->GetNextNode() != nullptr)
			{
				if (listIterator->GetNextNode()->GetData() == data)
				{
					ListNode* current_node = listIterator->GetNextNode();
					listIterator->SetNext(current_node->GetNextNode());
					delete current_node;
					elementsCount--;
					ok++;
				}
				else listIterator = listIterator->GetNextNode();
				
			}
			if ( listIterator->GetNextNode()->GetData() == data)
			{
				ListNode* current_node = listIterator->GetNextNode();
				listIterator->SetNext(nullptr);
				lastListElement = listIterator;
				elementsCount--;
				delete current_node;
				ok++;
			}
		}
		if (ok > 0)return true;
		else
			return false;
		
	}
}
void LinkedList::ClearList()
{
	while (elementsCount > 0)
		RemoveFirst();

}
bool LinkedList::Update(unsigned int position, int newData)
{
	//to be implemented
	int current_position = 0;
	if (position > elementsCount)
		return false;
	else
	{   
		ListNode* listIterator = listHead;
		while (current_position < position)
		{
			listIterator = listIterator->GetNextNode();
			current_position++;
		}
		listIterator->SetData(newData);
		return true;
	}
}

bool LinkedList::UpdateByData(int currentData, int newData)
{
	//to be implemented

	ListNode* listIterator = listHead;
	while (listIterator->GetData() != currentData && listIterator->GetNextNode()!=nullptr)
	{
		listIterator = listIterator->GetNextNode();
	}
	if (listIterator->GetData() == currentData)
	{
		listIterator->SetData(newData);
		return true;
	}
	else return false;
}