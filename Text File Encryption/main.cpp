 /*  Tom O'Donnell
    ECGR 2104-001
    Project 1 RPG Assignment
    February 14, 2021
*/    
    
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "character.h"

using namespace std;

int main(){      

srand(time(0)); //Seeds random number for hit multiplier. Done so fight will have different outcomes without changing user and cpu values.

bool coffee = true; //Boolean to allow user to take a coffee break once.

Character user("Intern",20,3,6,5); //Standard entry level go-fer
Character cpu("Middle Management", 32,2,5,6); //The bane of all existence

cout << "Welcome to the Corporate Ladder..." << endl; 
cout << "Prepare yourself for battle!" << endl;
cout << user.getName() << " vs. " << cpu.getName() << endl;

while (user.isAlive() && cpu.isAlive()){ //Checks to see if both characters are alive
    
    if(user.getHealth() <= 5 && coffee){ //Allows a coffee break if user falls below 5 health and hasn't already taken one.
        user.coffeeBreak();
        cout << user.getName() << " takes a coffee break." << endl;
        cout << user.getName() << " has " << user.getHealth() << " health now." << endl;
        coffee = false;
    }
    else{
    if(user.getSpeed() > cpu.getSpeed()){ //determines if user strikes first
        cout << user.getName() << " attacks." << endl;
        cpu.takeDamage(user.getAttack());
        cout << cpu.getName() << "'s health is " << cpu.getHealth() << "." << endl;
        
        if(cpu.isAlive()){ //lets cpu strike if still alive
        cout <<cpu.getName() << " attacks." << endl;
        user.takeDamage(cpu.getAttack());
        cout << user.getName() << "'s health is " << user.getHealth() << "." << endl;
        }
        else{
            break;
        }
    }
    else{ //conditon where cpu strikes first
        cout <<cpu.getName() << " attacks." << endl;
        user.takeDamage(cpu.getAttack());
        cout << user.getName() << "'s health is " << user.getHealth() << "." << endl;
        
        if(user.isAlive()){ //lets user strike if still alive
        cout << user.getName() << " attacks." << endl;
        cpu.takeDamage(user.getAttack());
        cout << cpu.getName() << "'s health is " << cpu.getHealth() << "." << endl;
        }
        
        else{
            break;
        }
    }
    }
}

if(user.getHealth() <= 0){ //cpu is the winner
    cout << cpu.getName() << " Wins!" << endl;
    
}
else{ //user is the winner
    cout << user.getName() << " Wins!" << endl;
}
return 0;
    
}
