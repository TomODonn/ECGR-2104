/*  Tom O'Donnell
    ECGR 2104-001
    Project 1 RPG Assignment
    February 14, 2021
*/   

#include "character.h"
#include <string>
#include<iostream>

Character::Character(string n, int hp, int sp, int att, int def){        
    name = n;
    health = hp;
    speed = sp;
    attack = att;
    defense = def;
    
}

Character::Character(){ //default constructor
    name = "Default User";
    health = 15;
    speed = 1;
    attack = 1;
    defense = 1;
}

bool Character::isAlive() const{
    return health > 0;
}

string Character::getName() const{
    return name;
}

int Character::getSpeed() const{
    return speed;
}

int Character::takeDamage(int oppAtt){ //Brings in oppenent attack value to determine damage.
    
    power = rand() % 4; //Hit multiplier up to 3x, left 0-3 for missing as well.
    if(power ==0){
        cout << "Missed!" << endl; //missed hit
    }
    else{
    switch(power){
        case 1:
        cout << "Effective Hit!" << endl; // regular damage
        break;
        case 2:
        cout << "Super Effective Hit!" << endl; // 2x damage
        break;
        case 3:
        cout << "Ultra Effective Hit!" << endl; // 3x damage
        break;
    }
    if((oppAtt < defense) || (oppAtt==defense)){ //added to make minimum attack value 1 and not increase player health.
        health -= 1*power;
    }
    else{
    health -= ((oppAtt - defense)*power);
    }
    return health;
    }
}

int Character::getHealth() const{
    return health;
}

int Character::getAttack() const{
    return attack;
}

int Character::coffeeBreak(){ //Adds 10 health for coffee break.
    health +=10;
    return health;
}