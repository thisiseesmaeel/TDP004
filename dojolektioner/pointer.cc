//INTE IDEAL LÖSNING, BORDE HA ANVÄNT NEW OCH ->

//Uppgift 1
//utgår från att objektet har medlemsvariablerna i public

struct Object {
	Element* next = nullptr;
	int value = 5;
};

int main() {
	Object o1{};
	
	int* first{&o1};
	o1.next = &o1;
	
	return 0;
}

//Uppgift 3

class Element {
	private:
		Element* next = nullptr;
		int value = 0;
	
	public:
		Element(Element* n, int v) {
			next = n;
			value = v;
		}
}

int main() {
	Element e2{nullptr, 9};
	Element e1{&e2, 5};
	
	int* first{&e1};
	
	return 0;
}

//Uppgift 4
//antar att det är ok att omdefiniera, annars behöver vi en setter

class Element {
	private:
		Element* next = nullptr;
		int value = 0;
	
	public:
		Element(Element* n, int v) {
			next = n;
			value = v;
		}
}

int main() {
	Element e2{nullptr, 9};
	Element e3{&e2, 8};
	Element e1{&e3, 5};
	
	int* first{&e1};
	
	return 0;
}

//Uppgift 5
//assuming next is in public, otherwise use a getter aka e.get_next()

Element e = *first;

while (next == nullptr) {
	Element* next = e.next;
	e = *next;
}

Element* last_address = &e; //save current address







