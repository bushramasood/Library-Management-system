#pragma once
#include <iostream>
#include <conio.h>
#include "Book.h"
#include <string>

using namespace std;
class Node
{
public:
	Book b;
	Node* left;
	Node* right;
	Node* next;
	Node();
	Node(Book b);
};
#pragma once
#include<string>
using namespace std;
class node
{
public:
	string data;
	node* next;
	node();
};


