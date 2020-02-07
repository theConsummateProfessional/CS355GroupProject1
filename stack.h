#include <iostream>
#include "linkedList.h"

template <class Type>
class Stack
{
	private:
		Type* top;
	public:
		Stack();
		~Stack();
		void push(Type);
		Type pop();
		bool empty() const;
		bool full() const;
};
