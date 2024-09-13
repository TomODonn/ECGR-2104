#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include "lands.h"
#include "player.h"

using namespace std;

enum PlayerChoice {NORTH, SOUTH, EAST, WEST, MAP};

void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice){
    // 0 = North, 1 = South, 2 = East, 3 = West
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cout << "To look at your map, enter M" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if(input == "n")
        playerChoice = NORTH;
    else if(input == "s")
        playerChoice = SOUTH;
    else if(input == "e")
        playerChoice = EAST;
    else if(input == "w")
        playerChoice = WEST;
    else if(input == "m")
        playerChoice = MAP; //Added in map for testing, liked the feature so it was kept
    else{
        cout << "Invalid input." << endl;
        return false;
    }
    
    return true;
}


int main(){
    
    srand(time(0)); //Seeds random number
    
    int counter = 1;
    bool isMap = false;
    const int MAP_SIZE = 20;
    int START_X = rand() % MAP_SIZE; //Random starting x position
    int START_Y = rand() % MAP_SIZE; //Randon starting y position
    Player player(Player::DEFAULT_HEALTH, 
                  Player::DEFAULT_HUNGER, 
                  Player::DEFAULT_THIRST, 
                  MAP_SIZE/START_X, MAP_SIZE/START_Y);
    
    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    bool beenHere[MAP_SIZE][MAP_SIZE]; //Array to determine if map space has ben explored
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            map[i][j] = getRandomLand();
            beenHere[i][j] = false; //Initializes all map spaces as hidden.
        }
    }
    
    cout << "You wake up in a " << 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << endl;
        
    while(player.isAlive()){
        //clearTerminal();
        player.newTurn();
        
        //Builds map of explored areas
        beenHere[player.getX()][player.getY()] = true;
        if(player.getX() == MAP_SIZE - 1){
            beenHere[0][player.getY()] = true; //East from right edge
            beenHere[player.getX() - 1][player.getY()] = true; //West from right edge
        }
        else if(player.getX() == 0){
            beenHere[player.getX() + 1][player.getY()] = true; //East from left edge
            beenHere[MAP_SIZE - 1][player.getY()] = true; //West from left edge
        }
        else{
            beenHere[player.getX() + 1][player.getY()] = true; //East from non-edge
            beenHere[player.getX() - 1][player.getY()] = true; //West from non-edge
        }
        if(player.getY() == MAP_SIZE - 1){
            beenHere[player.getX()][player.getY() - 1] = true; //North from bottom edge
            beenHere[player.getX()][0] = true; //South from bottom edge 
        }
        else if(player.getY() == 0){
            beenHere[player.getX()][MAP_SIZE - 1] = true; //North from top edge
            beenHere[player.getX()][player.getY() + 1] = true; //South from top edge
        }
        else{
            beenHere[player.getX()][player.getY() - 1] = true; //North from non-edge
            beenHere[player.getX()][player.getY() + 1] = true; //South from non-edge
        }
        // Give description of surroundings
        int x = player.getX();
        int y = player.getY();
        
        if(counter > 1 || !isMap){
            cout << endl << map[x][y]->getLongDescription() << endl << endl;
            cout << map[x][y]->visit(player) << endl << endl;
            cout << player.printStats() << endl << endl;
            isMap = false;
        }
        
        //North from top edge is bottom edge
        if(player.getY() == (0)) 
            cout << "To the north you see a " << map[x][MAP_SIZE - 1]->getShortDescription() << endl;
        else
            cout << "To the north you see a " << map[x][y - 1]->getShortDescription() << endl;
        //South from bottom edge is top edge    
        if(player.getY() == (MAP_SIZE - 1)) 
            cout << "To the south you see a " << map[x][0]->getShortDescription() << endl;
        else
            cout << "To the south you see a " << map[x][y + 1]->getShortDescription() << endl;
        //East from right edge is left edge    
        if(player.getX() == (MAP_SIZE - 1))
            cout << "To the east you see a " << map[0][y]->getShortDescription() << endl;
        else
            cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl;
        //West from left edge is right edge
        if(player.getX() == (0))
            cout << "To the west you see a " << map[MAP_SIZE - 1][y]->getShortDescription() << endl;
        else
            cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl;
        
        PlayerChoice playerChoice;
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice){
            case NORTH:
                if(player.getY() == 0){
                    player.setY(MAP_SIZE - 1);
                    break;
                }
                else{
                    player.setY(player.getY() - 1);
                    break;
                }
            case SOUTH:
                if(player.getY() == (MAP_SIZE - 1)){
                    player.setY(0);
                    break;
                }
                else{
                    player.setY(player.getY() + 1);
                    break;
                }
            case EAST:
                if(player.getX() == (MAP_SIZE - 1)){
                    player.setX(0);
                    break;
                }
                else{
                    player.setX(player.getX() + 1);
                    break;
                }
            case WEST:
                if(player.getX() == (0)){
                    player.setX(MAP_SIZE - 1);
                    break;
                }
                else{
                    player.setX(player.getX() - 1);
                    break;
                }
            case MAP:
                //Loop through y axis
                for(int i = 0; i < MAP_SIZE; i++){
                    //Draws top border
                    for(int k = 0; k < MAP_SIZE * 4; k++){
                        cout << "-";
                    }
                        cout << endl;
                        cout << "| "; //Left edge
                        //Loop through x axis
                        for(int j = 0; j < MAP_SIZE; j++){
                            if(map[j][i] == map[player.getX()][player.getY()]){
                                cout << "\033[0;31m" << "X"; //Marks players current position with red X
                                cout << "\033[0m" << " | "; //Resets color to white
                                beenHere[j][i] = true;
                            }
                            else if(beenHere[j][i] == true){ //Shows visited areas
                                cout << map[j][i]->getShortDescription().at(0) << " | ";
                            }
                            else{ //Leaves unexplored areas blank
                                cout << "  | ";
                            }
                        }
                        cout << endl;
                }
                    //Loop to draw bottom edge
                    for(int k = 0; k < MAP_SIZE * 4; k++){
                        cout << "-";
                    }
                    cout << endl;
                counter--; //To exclude checking the map from moves.
                isMap = true;
                break;
            default:
                cout << "Invalid input found: " << playerChoice << endl;
                break;
        }
        
        if(!player.isAlive()){
            cout << "Game Over! You survived for " << (counter - 1) << " moves."<< endl; //To account for last input.
            return 0;
        }
        
    counter++; //Track number of moves   
    }
    return 0;
}