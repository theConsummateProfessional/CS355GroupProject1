/*
        Computer Science III
        Assignment #5

        This is the header file. It contains the member variables and the member functions along with implementation details.
        
        Due: Monday, February 17th, 2020 @ 7:30 AM
        Programmed By: Ethan Hood, Khoi Vo, & Paul Byars
*/

using namespace std;

template <class Type>
class typeNode
{
	private:
		Type data;
		typeNode<Type>* ptr;
	public:
		typeNode(Type theData, typeNode<Type>* theLink);
		void setData(Type theData);
		void setLink(Type* theLink);
		Type getData() const;
		typeNode<Type>* getLink() const;
};

template <class Type>
class Stack
{
	private:
		typeNode<Type>* top;
		typeNode<Type>* cursor;
	public:
		Stack();
		Stack(const Stack&);
		~Stack();
		void push(Type);
		Type pop();
		bool empty() const;
		bool full() const;
		void display();
		void search(Type);
		Type getCursor() const;
		void operator=(const Stack&);
};

// Function: typeNode
// Purpose: constructor for the template class
// Incoming: theData, theLink - Type, typeNode<Type>*
// Outgoing: none
// Return: none

template <class Type>
typeNode<Type>::typeNode(Type theData, typeNode<Type>* theLink)
{
	data = theData;
	ptr = theLink;
}

// Function: setData
// Purpose: set the data
// Incoming: theData - Type
// Outgoing: none
// Return: none

template <class Type>
void typeNode<Type>::setData(Type theData)
{
	data = theData;
}

// Function: setLink
// Purpose: set the link
// Incoming: theLink - Type*
// Outgoing: none
// Return: none

template <class Type>
void typeNode<Type>::setLink(Type* theLink)
{
	ptr = theLink;
}

// Function: getData
// Purpose: return the value of data
// Incoming: none
// Outgoing: none
// Return: data

template <class Type>
Type typeNode<Type>::getData() const
{
	return data;
}

// Function: getLink
// Purpose: return the value of the pointer
// Incoming: none
// Outgoing: none
// Return: ptr

template <class Type>
typeNode<Type>* typeNode<Type>::getLink() const
{
	return ptr;
}

// Function: Stack
// Purpose: contructor the stack class
// Incoming: none
// Outgoing: none
// Return: none

template <class Type>
Stack<Type>::Stack()
{
	top = NULL;
	cursor = top;
}

// Function: Stack
// Purpose: copy contructor
// Incoming: &copy - const Stack<Type>
// Outgoing: copy
// Return: none

template <class Type>
Stack<Type>::Stack(const Stack<Type> &copy)
{
	top = copy.top;
	cursor = copy.cursor;
}

// Function: ~Stack
// Purpose: destructor for the stack class
// Incoming: none
// Outgoing: none
// Return: none

template <class Type>
Stack<Type>::~Stack()
{
	while(!empty())
		cout << pop() << endl;
}

// Function: push
// Purpose: push an object onto the stack
// Incoming: inData - Type
// Outgoing: none
// Return: none

template <class Type>
void Stack<Type>::push(Type inData)
{

	if(!full())
	{
		typeNode<Type>* temp = new typeNode<Type>(inData, top);
		top = temp;
		cursor = temp;
	}
}

// Function: pop
// Purpose: pop an item off of the stack
// Incoming: none
// Outgoing: none
// Return: value

template <class Type>
Type Stack<Type>::pop()
{
	Type value;
	if(empty())
		cout << "Cannot pop from an empty list" << endl;
	else
	{
		typeNode<Type>* temp = top;
		value = temp -> getData();
		top = temp -> getLink();
		cursor = top;
		delete temp;
	}
	return value;
}

// Function: empty
// Purpose: check to see of the stack is empty
// Incoming: none
// Outgoing: none
// Return: boolean value

template <class Type>
bool Stack<Type>::empty() const
{
	if (top == NULL)
		return true;
	return false;

}

// Function: full
// Purpose: check to see if the stack is full
// Incoming: none
// Outgoing: none
// Return: boolean value

template <class Type>
bool Stack<Type>::full() const
{
	return false;
}

// Function: search
// Purpose: search through the list linearly
// Incoming: key - Type
// Outgoing: none
// Return: none

template <class Type>
void Stack<Type>::search(Type key)
{
	typeNode<Type>* temp = top;
	if(empty())
		cout << "No such stack exists..." << endl;
	else
	{
		while(temp != NULL)
		{
			if(temp -> getData() == key)
				cursor = temp;

			temp = temp -> getLink();
		}
	}
	
}

// Function: display
// Purpose: print out the contents of the stack
// Incoming: none
// Outgoing: none
// Return: none

template <class Type>
void Stack<Type>::display()
{
	Stack<Type> tempStack;
	typeNode<Type>* temp = top;
	Type data = cursor -> getData();
	cout << "[";
	while(temp != NULL)
	{
		Type data = temp -> getData();
		tempStack.push(data);
		temp = temp -> getLink();
	}

	while(!tempStack.empty())
	{
		Type popped = tempStack.pop();
		if(popped == data)
			cout << "[" << popped << "] ";
		else
			cout << popped << " ";
	}

	cout << "]" << endl;
}

// Function: getCursor
// Purpose: return the position of the cursor
// Incoming: none
// Outgoing: none
// Return: cursor position

template <class Type>
Type Stack<Type>::getCursor() const
{
	return cursor -> getData();
}

// Function: operator =
// Purpose: overload the = operator for the assignement contructor
// Incoming: &right - const Stack<Type>
// Outgoing: none
// Return: right

template<class Type>
void Stack<Type>::operator = (const Stack<Type>& right)
{
	top = right.top;
	cursor = right.cursor;
}
