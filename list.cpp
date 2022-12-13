#include "list.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

list::list() {}
list::~list() {}

node* head = NULL;
void list::insert_end(string y)
{
	if (head == NULL)
	{
		node* ptr = new node;
		ptr->data = y;
		ptr->next = NULL;
		head = ptr;
	}
	else
	{
		node* traverse;
		traverse = head;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		node* ptr = new node;
		ptr->data = y;
		ptr->next = NULL;
		traverse->next = ptr;
	}
}
void list::traverse()
{
	node* p = head;
	while (p != NULL)
	{
		cout << "Book available from this domain are: " << p->data << endl;
		p = p->next;
	}
}

bool list::logIn(node* h1, node* h2)
{
	node* p = h1;
	node* q = h2;
	while (p->next != NULL && q->next != NULL)
	{
		if (p->data == q->data)
		{
			return true;
		}
		else
			return false;

	}

}

void list::deleteNode(string data)
{
	node* ptr1, *ptr2;
	ptr2 = NULL;
	ptr1 = head;
	while (ptr1 != NULL && ptr1->data != data)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	if (ptr1 == NULL)
	{
		cout << "" << endl;
	}
	else if (ptr2 == NULL)
	{
		head = ptr1->next;
	}
	else
	{
		ptr2->next = ptr1->next;
	}
	delete ptr1;
}

int list::No_of_Books()
{
	node* ptr = head;
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}




