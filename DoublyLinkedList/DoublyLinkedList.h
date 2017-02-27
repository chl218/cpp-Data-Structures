#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


struct Node {
	int val;
	Node *prev;
	Node *next;
};


class DoublyLinkedList {
	private:
		Node *head, *tail;
		unsigned size;

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		Node * removeFront();
		Node * removeBack();

		void insertFront(int i);
		void insertBack(int i);

		Node * remove(int i);
		void insert(int i);

		bool isEmpty();
		bool contains(int i);

		unsigned length();
		void clear();
};

#endif
