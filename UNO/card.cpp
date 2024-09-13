#include "card.h"

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    \033[0;31mRED\033[0m    |";
                break;
            case BLUE:
                return "|    \033[0;34mBLUE\033[0m   |";
                break;
            case GREEN:
                return "|   \033[0;32mGREEN\033[0m   |";
                break;
            case YELLOW:
                return "|  \033[0;33mYELLOW\033[0m   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}

Reverse::Reverse(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string Reverse::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    \033[0;31mRED\033[0m    |";
                break;
            case BLUE:
                return "|    \033[0;34mBLUE\033[0m   |";
                break;
            case GREEN:
                return "|   \033[0;32mGREEN\033[0m   |";
                break;
            case YELLOW:
                return "|  \033[0;33mYELLOW\033[0m   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|  REVERSE  |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool Reverse::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        
        return true;
    } else {
        return false;
    }
}

Skip::Skip(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string Skip::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    \033[0;31mRED\033[0m    |";
                break;
            case BLUE:
                return "|    \033[0;34mBLUE\033[0m   |";
                break;
            case GREEN:
                return "|   \033[0;32mGREEN\033[0m   |";
                break;
            case YELLOW:
                return "|  \033[0;33mYELLOW\033[0m   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|    SKIP   |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool Skip::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}

DrawTwo::DrawTwo(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string DrawTwo::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    \033[0;31mRED\033[0m    |";
                break;
            case BLUE:
                return "|    \033[0;34mBLUE\033[0m   |";
                break;
            case GREEN:
                return "|   \033[0;32mGREEN\033[0m   |";
                break;
            case YELLOW:
                return "|  \033[0;33mYELLOW\033[0m   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3: return "|  DRAW TWO |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool DrawTwo::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}

Wild::Wild(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string Wild::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    \033[0;31mRED\033[0m    |";
                break;
            case BLUE:
                return "|    \033[0;34mBLUE\033[0m   |";
                break;
            case GREEN:
                return "|   \033[0;32mGREEN\033[0m   |";
                break;
            case YELLOW:
                return "|  \033[0;33mYELLOW\033[0m   |";
                break;
            case NUM_COLORS:
                return "|   \033[0;31mW\033[0;32mI\033[0;33mL\033[0;34mD\033[0m    |";
            default:
                return "|           |";
                break;
            break;
            }
        
        case 3: return "|    \033[0;31mW\033[0;32mI\033[0;33mL\033[0;34mD\033[0m   |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool Wild::play(Card* discard, GameState &gameState) {
    return true;
}