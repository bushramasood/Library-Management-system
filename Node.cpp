#include "Node.h"
Node::Node()
{
	left = NULL;
	right = NULL;
	next = NULL;
}
Node::Node(Book b)
{
	this->right = NULL;
	this->left = NULL;
	this->b.author = b.author;
	this->b.ISBN = b.ISBN;
	this->b.title = b.title;
	this->b.domain = b.domain;
}

node::node()
{

}
