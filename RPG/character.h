/*  Tom O'Donnell
    ECGR 2104-001
    Project 1 RPG Assignment
    February 14, 2021
*/   

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character{
    private:
    string name;
    int health;
    int speed;
    int attack;
    int defense;
    int power; //random value to determine hit multiplier.
    
    public:
    Character(); //default constructor
    Character(string n, int hp, int sp, int att, int def);
   
    bool isAlive() const;
    string getName() const;
    int getSpeed() const;
    int takeDamage(int oppAtt);
    int getAttack() const;
    int getHealth() const;
    int coffeeBreak();
    
};

#endif