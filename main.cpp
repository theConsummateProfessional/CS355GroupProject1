#include <iostream>
#include "stackList.h"

using namespace std;

void printMenu();
void insert();

int main()
{
	Stack<int> stack;
	char choice = ' ';
	int value = 0;
	int key = 0;
	printMenu();

	
	Stack<int> s;
	s.push(1);		
	s.push(2);		
	s.push(3);		
	s.push(4);		
	s.push(5);		
	s.push(6);

	Stack<int> s1(s);
	Stack<int> s2;

	do{
		cin >> choice;

		switch(choice){
		case '+':
			cin >> value;
			stack.push(value);
			break;

		case '-':
			stack.pop();
			break;

		case '?': 
			cin >> key;
			stack.search(key);
			cout << key << endl;	
			break;

		case 'P':
		case 'p':
			stack.display();
			break;

		case '@':
			cout << stack.getCursor() << endl;
			break;

		case '1':
			cout << "Here is stack s1 after copy from s:" << endl;
			s1.display();
			break;

		case '2':
			cout << "Here is stack s2 after assignment:" << endl;
			s2 = s1;
			s2.display();
			break;

		case '3':
			stack.~Stack<int>();
			cout << "Destructor called" << endl;
			break;

		case 'M':
		case 'm':
			printMenu();
			break;

		case 'Q':
		case 'q':
			cout << "Goodbye..." << endl;
			break;

		default: 
			cout << "Incorrect input of a choice from the menu. Try again..." << endl;
			break;
		}

	}while(choice != 'Q' && choice != 'q');

	return 0;
}

void printMenu()
{
	cout << "+  Insert an item" << endl
		<< "-  Remove an item" << endl
		<< "?  Search for an item" << endl
		<< "P  Print the list" << endl
		<< "@  Print the item at the cursor" << endl
		<< "1  Test copy constructor" << endl
		<< "2  Test assignment operator" << endl
		<< "3  Test destructor" << endl
		<< "M  Print this menu again" << endl
		<< "Q  End this program" << endl << endl;
}

