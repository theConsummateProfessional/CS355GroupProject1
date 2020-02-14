using namespace std;

template <class Type>
class typeNode
{
	private:
		Type data;
		typeNode<Type>* ptr;
//		bool isCurrent;
	public:
		typeNode(Type theData, typeNode<Type>* theLink);
		void setData(Type theData);
		void setLink(Type* theLink);
//		void setCurrent(bool inCurrent);
		Type getData() const;
		typeNode<Type>* getLink() const;
//		bool getCurrent() const;
};

template <class Type>
class Stack
{
	private:
		typeNode<Type>* top;
		typeNode<Type>* cursor;
	public:
		Stack();
		Stack(const Stack<Type> &);
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

template <class Type>
typeNode<Type>::typeNode(Type theData, typeNode<Type>* theLink)
{
	data = theData;
	ptr = theLink;
//	isCurrent = false;
}

template <class Type>
void typeNode<Type>::setData(Type theData)
{
	data = theData;
}

template <class Type>
void typeNode<Type>::setLink(Type* theLink)
{
	ptr = theLink;
}

/*
template <class Type>
void typeNode<Type>::setCurrent(bool inCurrent)
{
	isCurrent = inCurrent;
}
*/

template <class Type>
Type typeNode<Type>::getData() const
{
	return data;
}

template <class Type>
typeNode<Type>* typeNode<Type>::getLink() const
{
	return ptr;
}

/*
template <class Type>
bool typeNode<Type>::getCurrent() const
{
	return isCurrent;
}
*/

template <class Type>
Stack<Type>::Stack()
{
	top = NULL;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type> &copy)
{
//	if(copy.top != NULL)
//		top = copy.top;
	
	temp = copy.top;
	while()
	{
		temp.push(copy.top -> getData());
	
}

template <class Type>
Stack<Type>::~Stack()
{
	while(!empty())
		cout << pop() << endl;
}

template <class Type>
void Stack<Type>::push(Type inData)
{
//	if(top != NULL)
//		top -> setCurrent(false);

	if(!full())
	{
		typeNode<Type>* temp = new typeNode<Type>(inData, top);
		top = temp;
		cursor = temp;
		//top -> setCurrent(true);
	}
}

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
		
//		if(top != NULL)
//			top -> setCurrent(true);

		delete temp;
	}
	return value;
}

template <class Type>
bool Stack<Type>::empty() const
{
	if (top == NULL)
		return true;
	return false;

}

template <class Type>
bool Stack<Type>::full() const
{
	return false;
}

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

template <class Type>
Type Stack<Type>::getCursor() const
{
	return cursor -> getData();
}


