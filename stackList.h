using namespace std;

template <class Type>
class typeNode
{
	private:
		Type data;
		Type* ptr;
	public:
		typeNode(Type theData, Type* theLink);
		void setData(Type theData);
		void setLink(Type* theLink);
		Type getData() const;
		Type* getLink() const;
};

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

