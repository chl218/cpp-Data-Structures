#include "DoublyLinkedList.h"


// Default constructor
DoublyLinkedList::DoublyLinkedList() {
	head = tail = nullptr;
	size = 0;
}

// Default destructor
DoublyLinkedList::~DoublyLinkedList() {
	clear();
}

// Remove all elements in linked list
void DoublyLinkedList::clear() {
	Node *p = head, *q;

	while(p != nullptr) {
		q = p;
		p = p->next;
		delete q;
	}
	size = 0;
}

// Is linked list empty
bool DoublyLinkedList::isEmpty() {
	return size == 0 ? true : false;
}

// Return size of linked list
unsigned DoublyLinkedList::length() {
	return size;
}

// Insert into front of list
void DoublyLinkedList::insertFront(int i) {
	
	Node *n = new Node();
	n->val = i;
	n->prev = n->next = nullptr;

	size++;

	if(head == nullptr) {
		head = tail = n;
		return;
	}

	n->next 	  = head;
	head->prev = n;
	head 		  = n;

}

// Insert into back of list
void DoublyLinkedList::insertBack(int i) {
	
	Node *n = new Node();
	n->val = i;
	n->prev = n->next = nullptr;

	size++;

	if(tail == nullptr) {
		head = tail = n;
		return;
	}

	n->prev 	  = tail;
	tail->next = n;
	tail 		  = n;

}

// Remove front of the list
Node * DoublyLinkedList::removeFront() {
	
	if(head == nullptr) {
		return nullptr;
	}

	size--;

	Node *n = head;
	
	if(head == tail) {
		head = tail = nullptr;
		return n;
	}
	
	head 				  = head->next;
	head->prev->next = nullptr;
	head->prev       = nullptr;
	
	return n;
}

// Remove back of the list
Node * DoublyLinkedList::removeBack() {
	
	if(tail == nullptr) {
		return nullptr;
	}

	size--;

	Node *n = tail;
	if(head == tail) {
		head = tail = nullptr;
		return n;
	}
	
	tail 				  = tail->prev;
	tail->next->prev = nullptr;
	tail->next		  = nullptr;
	return n;
}

// Insert an element into list
void DoublyLinkedList::insert(int i) {

	Node *p = head;
	while(p != nullptr) {
		if(p->val < i) {
			break;
		}
		p = p->next;
	}

	if(p == head) {
		insertFront(i);	
	}
	else if(p == nullptr) {
		insertBack(i);
	}
	else {	// insert middle
		Node *n = new Node();
		n->val = i;
		
		n->prev = p->prev;
		n->next = p;

		p->prev->next = n;
		p->prev		  = n;
		
		size++;
	}

}


// Remove an element from the list
Node * DoublyLinkedList::remove(int i) {

	if(size == 0) return nullptr;

	Node *p = head;

	while(p != nullptr) {
		if(p->val == i) break;
		p = p->next;
	}

	if(p == nullptr) return nullptr;

	if(p == head) {
		p = removeFront();
	}
	else if(p == tail) {
		p = removeBack();
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		size--;
	}

	p->next = nullptr;
	p->prev = nullptr;
	return p;
}


