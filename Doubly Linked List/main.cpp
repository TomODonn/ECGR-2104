/* Tom O'Donnell
   ECGR 2104-001
   Project 2
   March 10, 2021
*/

#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main(){
    int input;
    int value;
    int point;
    
    DoubleLinkedList list;
    
    cout << "Welcome to double linked list. Enter your choice below." << endl;
    
    while(input != 7){
        
        cout << "1: Push onto end of list." << endl;
        cout << "2: Print list values." << endl;
        cout << "3: Show number of items on list." << endl;
        cout << "4: Pop the last item off the list." << endl;
        cout << "5: Insert into any point on list." << endl;
        cout << "6: Remove from any point on list." << endl;
        cout << "7: End program." << endl;
        
        cin >> input;
        
        switch(input){
            case 1:
                cout << "Enter next list item: ";
                cin >> value;
                list.push(value);
            break;
            case 2:
                list.print();
            break;
            case 3:
                cout << "Items on list: " << list.size() << endl;
            break;
            case 4:
                list.pop();
            break;
            case 5:
                cout << "Enter next list item: ";
                cin >> value;
                cout << "Enter position on list: ";
                cin >> point;
                list.insert(value,point - 1);
            break;
            case 6:
            cout << "Enter item position to remove: ";
            cin >> value;
            
            if(list.size() > value - 1){
                list.remove(value - 1);
                list.print();    
            }
            
            else{
                cout << "List is not that long." << endl;
                
            }
            break;
            
            
        }
        
    }
    
    return 0;
    
}