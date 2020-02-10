#include "stackList.h"
#include <iostream>

template <class Type>
typeNode<Type>::typeNode(Type theData, Type* theLink)
{
	data = theData;
	ptr = theLink;
	current = false;
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

template <class Type>
void setCurrent(bool cur)
{
	current = cur;
}

template <class Type>
Type typeNode<Type>::getData() const
{
	return data;
}

template <class Type>
Type* typeNode<Type>::getLink() const
{
	return ptr;
}

template <class Type>
bool typeNode<Type>::isCurrent() const
{
	return current;
}

template <class Type>
Stack<Type>::Stack()
{
	top = NULL;
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
	if(!full())
	{
		Type* temp = new typeNode<Type>(inData, top);
		top = temp;
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
		Type* temp = top;
		value = temp -> getData();
		top = temp -> getLink();
		top->isCurrent(true);
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

