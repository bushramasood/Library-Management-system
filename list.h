#pragma once
#include "node.h"
#include<string>
class list
{
public:
	node* head;
	list();
	~list();
	void insert_end(string y);
	void traverse();
	bool logIn(node* h1, node* h2);
	void deleteNode(string data);
	int No_of_Books();
};

 