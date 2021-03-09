//Uppgift 3

//Element e = Element *first;
//first -> nullptr;

//while (next != nullptr) {
//	Element* pointer = pointer.next; //assuming it's in public
//	pointer.next -> nullptr;
//	pointer = Element *pointer;
//}

//basic List and Node
class List {
	private:
		Node *first;
	
	public:
		List() {
			first = nullptr;
		}
};

struct Node { 
	int data;
	Node* next;
};

//while-loop
int main() {
	Node *walker = new Node;
	walker = first;
	*first = nullptr;
	
	while(walker != nullptr) {
		Node* next = *walker -> next;
		(*walker).next = nullptr;
		walker = next;
	}
	
}




//Uppgift 4

//main
Element e = Element *first;
first -> nullptr;

recursion(e);

//...
int recursion(Element next_element) {
	if (pointer.next == nullptr) {}
	else {
		Element* pointer = pointer.next; //assuming it's in public
		pointer.next -> nullptr;
		pointer = Element *pointer;
		
		recursion(pointer):
	}
}


