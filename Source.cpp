#include<iostream>
#include<conio.h>           
#include<string>                  
#include<string.h>
#include"Book.h"
#include"Node.h"                
#include "BST.h"     
#include"list.h"                     

using namespace std;
// objects of classes

int main()
{
	// objects of classes
	BST bst;
	Book B;
	int opt;
	string B_title, dom, S_dom;
	string password;
	string id;
	list presetLogin, userEntered, check;
	list C, Relegious, P;
	cout << "\n\n\n\t\t================================================================" << endl;
	cout << endl;
	cout << "\t\t\t  BACHELOUR OF COMPUTER SCIENCE" << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\tMADE BY USING DATA STRUCTURE CONCEPTS" << endl;
	cout << endl;
	cout << "\t\t\t  LIBRARY MANAGMENT SYSTEM" << endl;
	cout << endl;
	cout << "\t\t\t\t DESIGNED BY" << endl;
	cout << endl;
	cout << "\t\t\t\tBushra Masood";
	cout << "\n\n\t\t=================================================================" << endl;
	system("pause");
	system("cls");
	//Setting my id and password
	presetLogin.insert_end("bushra");
	presetLogin.insert_end("12345");
	//Enter login id and passward 
	char pw;
	cout << "\n\t\t\t\t     Please Enter your Login credentials\n";
	cout << "\n\t\t\t\t\t    => Enter user_ID : ";
	cin >> id;
	cout << "\n\t\t\t\t\t    => Enter Password : ";
	pw = _getch();
	while (pw != 13)
	{
		password.push_back(pw);
		cout << '*';
		pw = _getch();
	}
	cout << endl;
	userEntered.insert_end(id);
	userEntered.insert_end(password);
	//compared my login system using linked list
	{
		if (check.logIn(presetLogin.head, userEntered.head) == true)
		{
			system("CLS");
			cout << "Logged in successfully! \n\n";
			do {
				cout << "--------------------------------------------\n";
				cout << "Press 1 to Enter a Record\n";
				cout << "Press 2 to delete a Record\n";
				cout << "Press 3 to search a Record\n";
				cout << "Press 4 to display current Records\n";
				cout << "Press 5 to modify a Record\n";
				cout << "Press 6 to count total no of new books enters\n";
				cout << "Press 7 to find books of particular domains\n";
				cout << "Press 8 to display all current record from File\n";
				cout << "Press 9 to delete all current record from File\n";
				cout << "Press 10 to write book issuing data on File\n";
				cout << "Press 11 to display book issuing data from File\n";
				cout << "Press 12 to delete all book issuing data\n";
				cout << "--------------------------------------------\n";
				cout << "Enter option: ";
				cin >> opt;
				system("CLS");
				cin.ignore();
				switch (opt)
				{
				case 0:
					break;
					//Enter book
				case 1:
				{
					ofstream f;
					f.open("data.text", ios::app | ios::out | ios::binary);
					cout << "--------------Enter Book Information-------------\n\n";
					cout << "Enter name of Author : ";
					getline(cin, B.author);
					cout << "Enter Title of book : ";
					getline(cin, B.title);
					cout << "Enter domain of book(Hint: Course, Relegious, Poetry ) : ";
					getline(cin, B.domain);
					cout << "Enter ISBN of book : ";
					cin >> B.ISBN;

					Node* new_node = new Node(B);
					bst.insertBook(new_node);
					if (B.domain == "Relegious")
					{
						Relegious.insert_end(B.title);
					}
					else if (B.domain == "course")
					{
						C.insert_end(B.title);
					}
					else if (B.domain == "poetry")
					{
						P.insert_end(B.title);
					}
					f << "Book Name: " << B.title << endl;
					f << "Author Name: " << B.author << endl;
					f << "Book unique id: " << B.ISBN << endl;
					f << "Domain: " << B.domain << endl;
					f << "----------------------------------" << endl;
					f.close();
					break;
				}
				//delete book
				case 2:
				{
					cout << "Enter title of the book you want to delete : ";
					getline(cin, B_title);
					cout << "Enter Domain of the book you want to delete : ";
					getline(cin, dom);
					bst.deleteNode(B_title);
					if (dom == "Relegious")
					{
						Relegious.deleteNode(B_title);
					}
					else if (dom == "course")
					{
						C.deleteNode(B_title);
					}
					else if (dom == "poetry")
					{
						P.deleteNode(B_title);
					}
					break;
				}
				//search book
				case 3:
				{
					cout << "\n---------------------------------------------\n";
					cout << "Enter title of the book you want to search : ";
					getline(cin, B_title);
					Node* trv = bst.searchBook(B_title);
					if (trv != NULL) {
						cout << "\nRecord found\n";
						cout << "Name of the book is : " << trv->b.title;
						cout << "\nAuthor name is : " << trv->b.author;
						cout << "\nDomain of the book is : " << trv->b.domain;
						cout << "\nISBN of the book is : " << trv->b.ISBN;
						cout << endl;
						cout << "\n---------------------------------------------\n";
					}
					else
						cout << "\n\nRecord not found !!\n\n";
					break;
				}
				//display books
				case 4:
				{
					cout << "All current the records in the library system are : ";
					cout << "\n--------------------------------------------------" << endl;
					bst.displayBook(bst.root);
					cout << "\n--------------------------------------------------" << endl;
					break;
				}
				//modify book record
				case 5:
				{
					cout << "Enter title of the book you want to modify : ";
					getline(cin, B_title);
					bst.modifyData(B_title);
					P.deleteNode("B_title");
					C.deleteNode("B_title");
					Relegious.deleteNode("B_title");
					break;
				}
				//count books
				case 6:
				{
					cout << "No of books in libraray " << P.No_of_Books() + Relegious.No_of_Books() + C.No_of_Books() << endl << endl;
					break;
				}
				//display particular domain book
				case 7:
				{
					cout << "Enter domain name of which you want to find books: ";
					cin >> S_dom;
					cout << endl;
					if (S_dom == "Relegious")
					{
						cout << "No of books in this domain are: " << Relegious.No_of_Books() << endl;
						Relegious.traverse();
					}
					if (S_dom == "course")
					{
						cout << "No of books in this domain are: " << C.No_of_Books() << endl;
						C.traverse();
					}
					if (S_dom == "poetry")
					{
						cout << "No of books in this domain are: " << P.No_of_Books() << endl;
						P.traverse();
					}
					break;
				}
				//read new record in library
				case 8:
				{
					ifstream f;
					f.open("data.text", ios::in | ios::binary);
					cout << "All new records in the library system are : ";
					cout << "\n--------------------------------------------------" << endl;
					bst.readFiledata();
					cout << "\n--------------------------------------------------" << endl;
					f.close();
					break;
				}
				//delete new record
				case 9:
				{
					ofstream f;
					f.open("data.text", ios::trunc | ios::out | ios::binary);
					f.close();
					cout << "\n\n--------------------------------------------------" << endl;
					cout << "\t\tAll record deleted from file";
					cout << "\n\n--------------------------------------------------" << endl;
					break;
				}
				//data filing for book issuing
				case 10:
				{
					Node* new_node = new Node(B);
					bst.filing(new_node);
					break;
				}
				//read file
				case 11:
				{
					bst.login();
					bst.readFile();
					break;
				}
				//delete file record
				case 12:
				{
					ofstream f;
					f.open("file.text", ios::trunc | ios::out | ios::binary);
					f.close();
					cout << "\n\n--------------------------------------------------" << endl;
					cout << "\t\t\nAll record deleted from file";
					cout << "\n\n--------------------------------------------------" << endl;
					break;
				}
				default:
				{
					cout << "Please enter a valid value\n";
					break;
				}
				}
			} while (opt != 0);
		}
		else
		{
			cout << "Wrong Username and Password entry: \n";
		}
		_getch();
		return 0;
	}
}

