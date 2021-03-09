#include <iostream>

struct Node
{
	int data;
	Node* next;
	
	//DESTRUCTOR
	~Node()
	{
		delete next;
	}
};

class Sorted_List
{
	private:
	Node* first = nullptr;
	
	public:
	Sorted_List();

	void insert_helper(int value, Node* temp);
	void insert(int value);

	void remove(int value);

	void display();

	Sorted_List(const Sorted_List& l_copy);
	Sorted_List& operator = (const Sorted_List& l_copy);

	Sorted_List(Sorted_List && other);
	Sorted_List& operator = (Sorted_List && other);

	~Sorted_List();

	bool is_empty();
	int size();
	int get_value(int position);
};


