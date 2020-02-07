using namespace std;

template <class Type>

class typeNode
{
	private:
		Type data;
		ptr link;
	public:
		typeNode(Type theData, ptr theLink);
		void setData(Type theData);
		void setLink(ptr theLink);
		Type getData() const;
		ptr getLink() const;
};