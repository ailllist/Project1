#include <iostream>
#include <string>

using namespace std;

class Node {

private:
	string _item;
	Node* _next;

	friend class LinkedList;

public:
	Node();

	~Node();

	void addItem(const string& item) {
		_item = item;
	}

	void setNext(Node* next) {
		_next = next;
	}

	string getItem() {
		return _item;
	}

	Node* getNext() {
		return _next;
	}
};

class LinkedList {

private:
	Node* head;
	int numItems = 0;
 

public:

	LinkedList();

	~LinkedList();

	bool empty() const;
	const string& front() const;
	void addFront(const string& e);
	void removeFront();
	Node* find(int index) {
		Node* curr = head;
		for (int i = 0; i < index; i++) {
			curr = curr->getNext();
		}
		return curr;
	}

	const string& get(int index) {
		if (index >= 0 && index < numItems) {
			Node* curr = find(index);
			return curr->getItem();
		}
		else {
			cout << "error" << endl;
		}
	}
};

LinkedList::LinkedList() : head(NULL) { }

LinkedList::~LinkedList() { while (!empty()) removeFront(); }

bool LinkedList::empty() const { return head == NULL; }

const string& LinkedList::front() const {
	return head->getItem();
}

void LinkedList::addFront(const string& e) {
	Node* v = new Node;
	v->addItem(e);
	v->setNext(head);
	head = v;
	numItems++;
}

void LinkedList::removeFront() {
	Node* old = head;
	head = old->getNext();
	delete old;
	numItems--;
}

int main() {
	LinkedList* StringLL = new LinkedList();

}