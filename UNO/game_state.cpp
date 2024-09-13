#include "game_state.h"
#include <iostream>

using namespace std;

GameState::GameState(int n){
    numPlayers = n;
    currentPlayerIndex = 0;
    numCardsToPlay = 1;
    numCardsToDraw = 0;
    turnDirection = LEFT;
}

void GameState::nextTurn(){
    if(turnDirection == LEFT){
        currentPlayerIndex++;
        if(currentPlayerIndex >= numPlayers){
            currentPlayerIndex = 0;
        }
    } else {
        currentPlayerIndex--;
        if(currentPlayerIndex < 0)
            currentPlayerIndex = numPlayers - 1;
    }
}

//Used to control reverse cards played.
void GameState::swapDirection(){
    if(turnDirection == LEFT) turnDirection = RIGHT;
    else if(turnDirection == RIGHT) turnDirection = LEFT;
}

//Used to force next player to draw two cards.
void GameState::draw2(){
    
    numCardsToPlay = 0;
    numCardsToDraw = 2;
    skipTurn = true;

}

//Used to set players choice for wild card played.
int GameState::wild(){
    int input;
    
    cout << "Choose a color:" << endl;
    cout << "1: RED" << endl;
    cout << "2: BLUE" << endl;
    cout << "3: GREEN" << endl;
    cout << "4: YELLOW" << endl;
    
    cin >> input;
    return (input - 1);
    
}