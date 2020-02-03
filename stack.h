#include <iostream>
#include "linkedList.h"
using namespace std;

class Stack
{
	private:
		ptr top;
	public:
		Stack();
		~Stack();
		void push(Type);
		Type pop();
		bool empty() const;
		bool full const;
};