/* Tom O'Donnell
   ECGR 2104-001
   Project 2
   March 10, 2021
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

struct Node{
   
   int data;
   Node* next;
   Node* last;
 
};

class DoubleLinkedList{
   
   private:
   
   Node* head;
   Node* tail;
   int* copyArray;
   unsigned int top;
   
   public:
   
   DoubleLinkedList();
   DoubleLinkedList& operator=(const DoubleLinkedList& copyData);
   ~DoubleLinkedList();
   DoubleLinkedList(const DoubleLinkedList& copyData);
   void push(int newData);
   int pop();
   int size();
   void print();
   int insert(int newData, unsigned int pos);
   void remove(int pos);
   unsigned int listSize() const;
   int& at(unsigned int index);
   
};

#endif