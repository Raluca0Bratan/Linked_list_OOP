// SampleLinkedList2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "LinkedList.h"
using namespace std;
void display(ListNode *listIterator)
{
	while (listIterator)
	{
		cout << listIterator->GetData() << " ";
		listIterator = listIterator->GetNextNode();
	}
	cout << endl;
}
int main()
{
	int listElements[] = { 1, 2, 4, 5, 6, 8};
	LinkedList list(listElements, _countof(listElements));
	ListNode* listIterator = list.FirstElement();
	cout << "LIST ELEMENTS" << endl;
	while (listIterator)
	{
		cout << listIterator->GetData() << " ";
		listIterator = listIterator->GetNextNode();
	}
	cout << endl << endl;
	list.Add(8);
	list.Add(8);
	list.Add(8);
	listIterator = list.FirstElement();
	display(listIterator);
	cout << endl;
	if (list.RemoveAllByData(13))
	{
		listIterator = list.FirstElement();
		display(listIterator);
	}
	else
		cout << "error";
	cout << endl<<endl;
	if (list.RemoveByData(1))
	{
		listIterator = list.FirstElement();
		display(listIterator);
	}
	else cout << "error";
	cout << endl;
	if (list.Update(0, 300))
	{
		listIterator = list.FirstElement();
		display(listIterator);
	}
	else cout << "error";
	cout << endl;
	if (list.UpdateByData(5, 777))
	{
		listIterator = list.FirstElement();
		display(listIterator);
	}
	else cout << "error"<< endl;
	cout << endl;
	if (list.RemoveAllByData(8))
	{
		listIterator = list.FirstElement();
		display(listIterator);
	}
	else
		cout << "error";
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
