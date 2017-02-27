#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
   DoublyLinkedList list;

   cout << "Doubly Linked List Demo:\n";
   
   cout << "insert front: ";
   for(int i = 0; i < 10; i++) {
      cout << i << ' ';
      list.insertFront(i);
   }
   cout << '\n';

   cout << "insert back : ";
   for(int i = 100; i < 110; i++) {
      cout << i << ' ';
      list.insertBack(i);
   }
   cout << '\n';
   
   cout << "remove 100  : ";
   Node *n = list.remove(100);
   cout << n->val << '\n';
   delete n;

   cout << "remove back : ";
   n = list.removeBack();
   cout << n->val << '\n';
   delete n;

   cout << "remove front: ";
   while(list.length() > 0) {
      n = list.removeFront();
      cout << n->val << ' ';
      delete n;
   }
   cout << '\n';
}