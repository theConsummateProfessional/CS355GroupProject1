#include <iostream>
#include "stackList.h"

using namespace std;

void printMenu();
void insert()

int main()
{
	Stack<int> stack;
	char choice = ' ';
	int value = 0;

	printMenu();
	
	cin >> choice;
	cout << endl;
	do
	{
		switch(choice){
		case '+':
			cout << "Enter a value to be added: ";
			cin >> value;
			stack.push(value);
			break;

		case '-':
			stack.pop();
			break;

		case '?': 

			break;

		case 'P' ||  'p':

			break;

		case '@':

			break;

		case '1':

			break;

		case '2':

			break;

		case '3':

			break;

		case 'M' || 'm':
			printMenu();
			break;

		case 'Q' || 'q':
			cout << "Goodbye..." << endl;
			break;

		default: 
			cout << "Incorrect input of a choice from the menu. Try again..." << endl;
			break;
		}
		
	} while(choice != 'Q' || choice != 'q');

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
		<< "Q  End this program" << endl << endl
		<< "Make a choice from the characters above: ";
}

void insert()
{

}
