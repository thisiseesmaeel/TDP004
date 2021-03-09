#include "List.h"

//IMPLERMENTATIONER

Sorted_List::Sorted_List()
{
	first = nullptr;
}

// ----------------------------------------------------------------------

void Sorted_List::insert_helper(int value, Node* temp)
{
	if ((first == nullptr) || (value <= temp->data)) //if list is empty or if you need to insert first, insert
	{
		Node* node_pointer = new Node;
		node_pointer->data = value;
		node_pointer->next = temp;
		
		first = node_pointer;
	}
	else if ((value >= temp->data && temp->next == nullptr) || (value >= temp->data && value <= temp->next->data)) //insert anywhere else
	{
		Node* node_pointer = new Node;
		node_pointer->data = value;
		node_pointer->next = temp->next;
		
		temp->next = node_pointer;
	}
	else //recursion
	{
		temp = temp->next;
		insert_helper(value, temp);
	}
}

// ----------------------------------------------------------------------

void Sorted_List::insert(int value)
{
	Node* first_temp = first;
	insert_helper(value, first_temp);
}

// ----------------------------------------------------------------------

void Sorted_List::remove(int value)
{
	if (first == nullptr) //if list is empty
	{
		return;
	}
	else if (first->data == value) //if the first is to be deleted
	{
		Node* temp = first->next;
		first->next = nullptr;
		delete first;
		first = temp;
		return;
	}
	else //else loop over the list and search for the node to delete
	{
		Node* temp = first;
		
		while(temp->next != nullptr)
		{
			if (temp->next->data == value)
			{
				Node* temp_ptr = temp->next->next;
				temp->next->next = nullptr;
				delete temp->next;
				temp->next = temp_ptr;
				return;
			}
			temp = temp->next;
		}
	}
}

// ----------------------------------------------------------------------

void Sorted_List::display()
{
	Node* temp = first;
	while(temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	
	std::cout << std::endl;
}

// ----------------------------------------------------------------------

Sorted_List::Sorted_List(const Sorted_List& l_copy)
{
	if (l_copy.first == nullptr) //if an empty list is copied, do nothing
	{
		return;
	}
	
	Node* temp = l_copy.first;
	
	first = new Node;
	first->data = temp->data;
	first->next = nullptr;
	Node* current = first;
	temp = temp->next;
	
	while (temp != nullptr)
	{
		current->next = new Node;
		current = current->next;
		current->data = temp->data;
		current->next = nullptr;
		temp = temp->next;
	}
}

// ----------------------------------------------------------------------

Sorted_List& Sorted_List::operator = (const Sorted_List& l_copy)
{
	Sorted_List temp{ l_copy };
	std::swap( first, temp.first );
	return *this;
}

// ----------------------------------------------------------------------

Sorted_List::Sorted_List(Sorted_List && other)
{
	std::swap( first, other.first);
}

// ----------------------------------------------------------------------

Sorted_List& Sorted_List::operator = (Sorted_List && other) 
{
	std::swap( first, other.first);
	return *this;
}

// ----------------------------------------------------------------------

Sorted_List::~Sorted_List()
{
	delete first;
}

// ----------------------------------------------------------------------

bool Sorted_List::is_empty()
{
	if (first == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ----------------------------------------------------------------------

int Sorted_List::size()
{
	Node* temp = first;
	int counter = 0;
	
	while(temp != nullptr)
	{
		counter = counter + 1;
		temp = temp->next;
	}
	
	return counter;
}

// ----------------------------------------------------------------------

int Sorted_List::get_value(int position)
{
	if (first == nullptr)
	{
		return 0;
	}
	else
	{
		Node* temp = first;
		int counter = 0;
		
		while(counter != position)
		{
			counter = counter + 1;
			
			if (counter == position)
			{
				return temp->data;
			}
			
			temp = temp->next;
		}
	}
}
	
// ----------------------------------------------------------------------

//main() i .cc
//g++ -Wall -Wextra -Weffc++ -Wold-style-cast -Woverloaded-virtual -std=c++17 -pedantic -Werror -g List.cc
//./a.out

//valgrind
//g++ -std=c++17 -g List.cc (eller test_main.cc)
//valgrind --tool=memcheck --leak-check=yes ./a.out

//test
//g++ -c test_main.cc
//g++ test_main.o List.cc list_test.cc

