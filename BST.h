#pragma once
#include "Node.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
class BST
{
public:
	Node* root;
	BST();
	bool isEmpty();
	void insertBook(Node* data);
	Node* searchBook(string s);
	Node* minNode(Node* c);
	Node* deleteBook(Node* root, string title);
	void deleteNode(string s);
	void modifyData(string s);
	void displayBook(Node* trv);
	Node* filing(Node* curr);
	void readFile();
	void readFiledata();
	int count(Node* ptr);
	bool login();
};
