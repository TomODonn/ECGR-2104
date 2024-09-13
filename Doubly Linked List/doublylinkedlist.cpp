/* Tom O'Donnell
   ECGR 2104-001
   Project 2
   March 10, 2021
*/

#include <iostream>
#include "doublylinkedlist.h"

using namespace std;


DoubleLinkedList::DoubleLinkedList(){
 
    head = nullptr;
    tail = nullptr;
    
}

//Copy operator overide.    
DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& copyData){
    cout << "Copy operator override called." << endl;
    Node* temp = head;
    for(int i = 0; i < top + 1; i++){
        copyArray[i] = temp->data;
        temp = temp->next;
    }
    
    delete temp;
  
}

//Destructor.
DoubleLinkedList::~DoubleLinkedList(){
    cout << "destructor called." << endl;
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
        delete temp->last;
    }
    
    delete temp;
    delete head;
    delete tail;
    
}

//Copy constructor.
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& copyData){
    cout << "Copy constructor called." << endl;
    Node* temp = head;
    
    for(int i=0; i < top + 1; i ++){
        copyArray[i] = temp->data;
        temp = temp->next;
    }
    
    delete temp;
}
   
 // Adds a new node to the end of the list
 void DoubleLinkedList::push(int newData){
    
    if(head == nullptr){
        head = new Node;
        head->data = newData;
        head->next = nullptr;
        
    } 
        
    else { // Loop until the end of list
    
        Node* temp = head;
        
        while(temp->next != nullptr){
            
            temp = temp->next;
            
        }
        
        // Add new node to end of list
        temp->next = new Node;
        (temp->next)->data = newData;
        (temp->next)->next = nullptr;
        
    }
    
    top++;
    
}

//Removes the last node on the list.
int DoubleLinkedList::pop(){
        
        int returnVal;
        Node* temp = head;
        Node* prev = nullptr;
        
        if(top == 0){
         cout << "List is empty." << endl;
         return 0;
        }
        
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next;
            
        } 
        
        returnVal = temp->data;
        
        delete temp;
        prev->next = nullptr;
        
        return returnVal;
        
        top--;
    }
    
    //Returns the number of nodes of the list.
    int DoubleLinkedList::size(){
        
        int count = 1;
        Node* temp = head;
        Node* prev = nullptr;
        
        if(top == 0){
         return 0;
        }
        
        while( temp->next != nullptr){
            prev = temp;
            temp = temp->next;
            count++;
        }
        
        return count;
    }
    // Prints the double linked list contents.
    void DoubleLinkedList::print(){
        
        Node* temp = head;
        
        if(top == 0){
         cout << "List is empty." << endl;
        }
        else{
        while(temp->next != nullptr){
            
            cout << temp->data << " ";
            temp = temp->next;
            
        }
        
        cout << temp->data << " ";
        cout << endl;
        }
        
    }
    
    //Inserts data at given position
    int DoubleLinkedList::insert(int newData, unsigned int pos){
        
        Node* temp;
        Node* temp2;
        
        if(pos > top){
            cout <<"Out of Range." << endl;
            return 0;
        }
        
        if(pos == 0 && top == 0){
            
            temp = head;
            head = new Node;
            head->data = newData;
            head->next = temp;
            //cout << "called initial." << endl;
          
            top++;
            delete temp;
            return 0;  
        }
        
        temp = head;
        
        for(int i = 0; i < pos - 1; i++){
            temp = temp->next;
        }
        
        temp2 = temp->next;
        temp->next = new Node;
        temp->next->data = newData;
        temp->next->next = temp2;
        
        //cout << "called second." << endl;
        
        top++;
        
    }
    
    void DoubleLinkedList::remove(int pos){
        
        Node* temp = head;
        Node* temp2 = nullptr;
        
        if(pos > top){
            cout << "Out of range." << endl;
        }
        else{
            if(pos == 0){
            
                head = temp->next;
            
            
            }
            else{
            
                for(int i = 0; i < pos - 1; i++){
                
                    temp = temp->next;
                
                }
            
                temp2 = temp->next;
                temp->next = temp2->next;
            
                temp = nullptr;
            

            
            }
        }
        
        top--;
        
    }
    
    unsigned int DoubleLinkedList::listSize()const{
        return top;
    }
    int& DoubleLinkedList::at(unsigned int index){
        if(index >= top){
            return copyArray[0];
        }
        return copyArray[index];
    }