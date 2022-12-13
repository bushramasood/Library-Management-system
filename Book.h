#pragma once
#include <iostream>
#include<conio.h>
#include <string>
using namespace std;

class Book
{
public:
	string title;
	string author;
	string domain;
	int ISBN;
	Book();
	Book(string, string, string, int);
};
