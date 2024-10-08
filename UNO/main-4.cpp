#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "game_state.h"
#include "card.h"

using namespace std;

/**
 * Function to clear the terminal by inserting many new line characters.
 */
//void clearTerminal();

/**
 * Function to populate the deck with cards.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
void buildDeck(vector<Card*>& deck);

/**
 * Function to shuffle the deck.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
 void shuffleDeck(vector<Card*>&);

/**
 * Function to draw a card from the deck to either the hand or discard pile.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param target A vector representing the structure that the card being drawn 
 * from the deck is being drawn to. This can be either a hand or the discard
 * pile
 */
void drawCards(vector<Card*>& deck, vector<Card*>& target, int);

/**
 * Function to draw 7 cards to each player's hand at the beginning of the game.
 * 
 * @param deck A vector reference of Card pointers representing the deck.
 * @param hands A vector of vector of Card pointers representing each player 
 * and their hands. The indicies of the first vector represents a player, and 
 * the indicies of the vector at that index is each individual card within the
 * player's hand.
 */
void populateHands(vector<Card*>& deck, vector<vector<Card*>>& hands);

/** 
 * Renders the cards in he hand vector passed.
 * 
 * @param hand A vector containing Card pointers
 */
void renderHand(vector<Card*> hand);

/**
 * Renders the top card of the passed discard vector.
 * 
 * @param hand A vector containing Card pointers
 */
void renderDiscard(vector<Card*>);

/**
 * Passed references to the deck, hand, and discard vectors and a reference to 
 * the game state. This function will resolve the turn for the current player
 * (whose index is stored in the game state). TakeTurn will query the user for
 * input, draw cards if the previous card was a draw 2 card, or skip the current
 * players turn (see numCardsToPlay in GameState).
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param hand A vector reference of Card pointers representing a single player's hand
 * @param discard A vector reference of Card pointers representing the discard pile
 * @param gameState A reference of the game state object
 */
void takeTurn(vector<Card*>& deck, vector<Card*>& hand, vector<Card*>& discard, GameState& gameState);

bool winner = false;
 
int main(){
    srand(time(0));
    const int NUM_PLAYERS = 3;
    GameState gameState(NUM_PLAYERS);
    
    vector<Card*> deck;
    vector<Card*> discard;
    
    vector<vector<Card*>> hands(NUM_PLAYERS);
    
    buildDeck(deck);
    shuffleDeck(deck);
    populateHands(deck, hands);
    drawCards(deck, discard, 1);
    
    while(!winner/* TODO: Check for winner (no cards in hand)*/){
        takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState);
    }
    
    return 0;
}

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

void buildDeck(vector<Card*> &deck){
    // Create Number Cards
    for(int c = RED; c < NUM_COLORS; c++){
        for(int n = 0; n < 10; n++){
            Card* temp = new NumberCard((Color)c, n);
            deck.push_back(temp);
            deck.push_back(temp);
        }
    }
    //Create Special Cards
    for(int c = RED; c < NUM_COLORS; c++){
        Card* temp;
        //Uses Specila enumeration to cycle through special cards.
        for(int i = REVERSE; i < NUM_SPECIAL; i++){
            switch(i){
                case REVERSE:
                temp = new Reverse((Color)c, 11);
                break;
                case SKIP:
                temp = new Skip((Color)c, 12);
                break;
                case DRAW_TWO:
                temp = new DrawTwo((Color)c, 13);
                break;
                case WILD:
                temp = new Wild(NUM_COLORS, 14);
                break;
                default:
                break;
            }
            
            deck.push_back(temp);
            deck.push_back(temp);
        }
        
    }
}

void shuffleDeck(vector<Card*> &deck){
    for(int i = 0; i < 1000; i++){
        int idx1 = rand() % deck.size();
        int idx2 = rand() % deck.size();
        Card* temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}

void drawCards(vector<Card*> &deck, vector<Card*> &target, int numToDraw){
    for(int i = 0; i < numToDraw; i++){
        if(deck.size() > 0){
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back();
        } else {
            cout << "WARNING: Deck out of cards" << endl;
        }
    }
}

void populateHands(vector<Card*> &deck, vector<vector<Card*>> &hands){
    for(int i = 0; i < hands.size(); i++){
        drawCards(deck, hands.at(i), 7);
    }
}

void renderHand(vector<Card*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand.at(j)->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void renderDiscard(vector<Card*> discard){
    for(int i = 0; i <= 7; i++){
        cout << discard.at(discard.size() - 1)->render(i) << endl;
    }
}

void takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameState &gameState){
    clearTerminal();
    renderDiscard(discard);
    cout << "Player " << gameState.currentPlayerIndex + 1 << "'s turn." << endl;
    
    // TODO: Draw cards if necessary (draw 2 card)
    drawCards(deck, hand, gameState.numCardsToDraw);
    gameState.numCardsToDraw = 0; // reset cards to draw back to 0
    
    renderHand(hand);
    
    // loop for number of cards to play (0 if previously played card was a "skip" or "draw 2")
    if(!gameState.skipTurn){
        // Collect user input
        cout << "What would you like to do?" << endl;
        int i;
        for(i = 0; i < hand.size(); i++){
            cout << i + 1 << ": Play Card" << endl;
        }
        cout << i + 1 << ": Draw a Card" << endl;
        int input;
        cin >> input;
        
        
        // Evaluate user input
        if(input < i + 1){
            // Play card at index input
            if(hand.at(input - 1)->play(discard.at(discard.size()-1), gameState)){
                Card* temp;
                temp = hand.at(input - 1);
                //Switch to control special cards.
                switch(temp->getNumber()){
                    case 11: gameState.swapDirection();//Call for reverse card played.
                    break;
                    case 12: gameState.skipTurn = true;//Sets skip turn to true when skip card played.
                    break;
                    case 13: gameState.draw2();//Call for draw two card played.
                    break;
                    case 14: temp->setColor((Color) gameState.wild());//Call for wild card to set color.
                    break;
                    default:
                    break;
                }
                discard.push_back(temp);
                hand.erase(hand.begin() + input - 1); // Remove card in hand at position "input"
                if(hand.size() == 0){
                    winner = true;
                }
            } else {
                cout << "Improper choice" << endl;
                takeTurn(deck, hand, discard, gameState);
                return;
            }
        }else if(input == i + 1){
            drawCards(deck, hand, 1);
        }
    }else{
        gameState.skipTurn = false;
    }
    
    // update variables for next turn
    gameState.nextTurn();
}