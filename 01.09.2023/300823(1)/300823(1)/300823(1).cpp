#include <iostream>
using namespace std;
#include "Node.h"

void putNodeToTail(Node* &head, int value) {

	Node* n = new Node(value);

	if (head == nullptr)
	{
		head = n;
		return;
	}
	Node* tmp = new Node();

	tmp = head;

	while (tmp->next != nullptr)
	{
		tmp = tmp->next;

	}
	n->prev = tmp;
	tmp->next = n;

}
void display(Node* &head) {

	Node* tmp = new Node();

	tmp = head;

	while (tmp != nullptr)
	{
		cout << tmp->value << " ";

		tmp = tmp->next;
	}
}

bool checkIncrease(Node* &head) {

	Node* tmp;

	tmp = head;

	while (tmp->next != nullptr)
	{
		if (tmp->value > tmp->next->value )
		{
			return false;
		}
		tmp = tmp->next;

	}
	return true;
}
bool checkSimilar(Node*& head) {
	Node* tmp = head;

	while (tmp->next != nullptr)
	{
		if (tmp->value == tmp->next->value )
		{
			return true;
		}
		tmp = tmp->next;
	}
	 return false;
}

void changeOrder(Node* &head) {
	Node* tmp = head;
	Node* third = new Node();

	while (tmp->next != nullptr) {

		third->value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = third->value;

		tmp = tmp->next->next;
	}

}
bool include(Node* &head, Node* &head2) {
	Node* tmp = head;
	Node* tmp2 = head2;

	int counter = 0;

	while (tmp->next != nullptr)
	{
		if (tmp->value == tmp2->value)
		{

			while (tmp2->next != nullptr)
			{
				tmp = tmp->next;
				tmp2 = tmp2->next;

				if (tmp2->next == nullptr)
				{
					return true;
				}

			}
		}
		tmp = tmp->next;
	}

}
int main()
{
	srand(time(NULL));

	Node* node = new Node(1);
	Node* node2 = new Node(1);

	for (int i = 2; i < 10; i++)
	{
		putNodeToTail(node,  i/*rand()% 10 +1*/);
	}
	for (int i = 2; i < 5; i++)
	{
		putNodeToTail(node2, i);
	}

	cout << "\nFirst list of numbers: " << endl;
	display(node); cout << endl;
	cout << "\nSecond list of numbers: " << endl;
	display(node2); cout << endl;

	checkIncrease(node);

	if (checkIncrease(node) == true)
	{
		cout << "\nList is increasing" << endl;
	}
	else
	{
		cout << "\nList is not increasing" << endl;
	}

	if (checkSimilar(node) == false)
	{
		cout << "\nNo same values found" << endl;
	}
	else
	{
		cout << "\nSame values found in list" << endl;
	}


	if (include(node, node2) == true)
	{
		cout << "\nList 2 is included" << endl;
	}
	else
	{
		cout << "\nList 2 is not included" << endl;
	}

	cout << "\nChanging order..." << endl;
	changeOrder(node);
	display(node); cout << endl;

	return 0;


}
