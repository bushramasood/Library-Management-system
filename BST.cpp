#include "BST.h"

BST::BST()
{
	root = NULL;
}

bool BST::isEmpty()
{
	if (root == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void BST::insertBook(Node* data)
{
	if (root == NULL)
	{
		root = data;
	}
	else
	{
		Node* p = root;
		while (p != NULL)
		{
			if (data->b.title == p->b.title)
			{
				cout << "The book is already present in library!" << endl;
				return;
			}
			else if (data->b.title < p->b.title && p->left == NULL)
			{
				p->left = data;
				break;
			}
			else if (data->b.title < p->b.title)
			{
				p = p->left;
			}
			else if (data->b.title > p->b.title && p->right == NULL)
			{
				p->right = data;
				break;
			}
			else {
				p = p->right;
			}
		}
	}
}
Node* BST::searchBook(string s)
{
	if (root == NULL)
	{
		cout << "No Book available in library yet!" << endl;
		return NULL;
	}
	Node* temp = root;
	while (temp != NULL)
	{
		if (s == temp->b.title)
		{
			return temp;
		}
		else if (s < temp->b.title)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return NULL;
}

Node* BST::minNode(Node* c)//Minimum node is required in delete function
{
	Node* curr = c;
	while (curr && curr->left != NULL)
	{
		curr = curr->left;
		return curr;
	}
}

Node* BST::deleteBook(Node* root, string title)
{
	if (root == NULL)
	{
		return root;
	}
	if (title < root->b.title)
	{
		root->left = deleteBook(root->left, title);
	}
	else if (title > root->b.title)
	{
		root->right = deleteBook(root->right, title);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			return NULL;
		}
		else if (root->left == NULL)
		{
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* temp = minNode(root->right);
		root->b.title = temp->b.title;
		root->right = deleteBook(root->right, temp->b.title);
	}
	return root;
}

void BST::deleteNode(string s)
{
	if (isEmpty())
	{
		cout << "Empty Tree!\n";
		return;
	}
	root = deleteBook(root, s);
}

void BST::modifyData(string s)
{
	//This function will first delete the book and then it will add the book again with edited data
	deleteNode(s);
	string title, author, domain;
	int ISBN;
	cout << "\n---------------------------------------------\n";
	cout << "Change Title: ";
	getline(cin, title);
	cout << "Change Name: ";
	getline(cin, author);
	cout << "Change domain: ";
	getline(cin, domain);
	cout << "Change ISBN: ";
	cin >> ISBN;
	insertBook(new Node({ title, author, domain, ISBN }));
	cout << "Data modified successfully! ";
	cout << "\n---------------------------------------------\n";
}

void BST::displayBook(Node* trv)
{
	if (trv == NULL)
		return;
	displayBook(trv->left);
	cout << "\nBook Name: " << trv->b.title;
	cout << "\nAuthor: " << trv->b.author;
	cout << "\nDomain: " << trv->b.domain << endl;
	cout << "\nISBN: " << trv->b.ISBN << endl;
	displayBook(trv->right);
}
//record of issuing books
Node* BST::filing(Node* curr)
{
	string name;
	string date,date_r;
	ofstream f;
	f.open("file.text", ios::app | ios::out | ios::binary);
	cout << "Name of person issuing book: ";
	getline(cin, name);
	cout << "Date of issue: ";
	getline(cin, date);
	cout << "Date of return: ";
	getline(cin, date_r);
		cout << "Book Name: ";
		getline(cin, curr->b.title);
		cout << "Author Name: ";
		getline(cin, curr->b.author);
		cout << "Domain: ";
		getline(cin, curr->b.domain);
		cout << "Book unique id: ";
		cin >> curr->b.ISBN;
	
		f << "Person Name: " << name << endl;
		f << "Book issuing date: " << date << endl;
		f << "Last date to return book: " << date_r << endl;
		f << "Book Name: " << curr->b.title << endl;
		f << "Author Name: " << curr->b.author << endl;
		f << "Book unique id: " << curr->b.ISBN << endl;
		f << "Domain: " << curr->b.domain << endl;
		f << "----------------------------------" << endl;
	f.close();
	return 0;
}

void BST::readFile()
{
	cout << "====================================Record From File:======================================================== \n";
	string record;
	ifstream f;
	f.open("file.text", ios::binary);
	while (!f.eof())
	{
		getline(f, record);
		cout << record << endl;
	}
	f.close();
}
//read new record file
void BST::readFiledata()
{
	cout << "====================================Record From File:======================================================== \n";
	string record;
	ifstream f;
	f.open("data.text", ios::binary);
	while (!f.eof())
	{
		getline(f, record);
		cout << record << endl;
	}
	f.close();
}
int BST::count(Node* ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else
	{
		int n = 0;
		count(ptr->left);
		count(ptr->right);
		n += 2;
		return n;
	}
}
bool BST::login()
{
	string username;
	string password;
	char pw;
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	pw = _getch();
	while (pw != 13)
	{
		password.push_back(pw);
		cout << '*';
		pw = _getch();
	}
	cout << endl;
	cout << "\n\n--------------------------------------------------" << endl;
	if (username == "bushra" && password == "abc")
	{
		return true;
	}
	else
	{
		return false;
	}
}
