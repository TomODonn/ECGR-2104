#include "lands.h"

using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case OASIS:
            return new Oasis;
            break;
        case MOUNTAIN:
            return new Mountain;
            break;
        case TUNDRA:
            return new Tundra;
            break;
        case WATERFALL:
            return new Waterfall;
            break;
        case VILLAGE:
            return new Village;
            break;
        default:
            return new Lake;
            break;
    }
    
}

string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    if(p.getThirst() > 0){
    p.setThirst(p.getThirst() - 1);
    }
    else
    p.setHealth(p.getHealth() - 1);

    return description;
}

string Oasis::getShortDescription(){
    
    return "oasis";
}

string Oasis::getLongDescription(){
    return "You arrive at a beautiful oasis.";
}

string Oasis::visit(Player& p){
    int chance = rand() % 5;
    string description = "The oasis has bananas to eat and water to quench your thirst.";
    
    p.setThirst(Player::DEFAULT_THIRST);
    
    if(chance <= 1){
        description += "\nA travelling caravan is stopped at the oasis too.";
        description += "\nThey feed you a warm meal and allow you to rest in their tents for the night.";
        description += "\nYou feel as good as you did at the beginning of your journey.";
        p.setHunger(Player::DEFAULT_HUNGER);
        p.setHealth(Player::DEFAULT_HEALTH);
    }
    
    else{
        description += " The bananas fill you up.";
        p.setHunger(Player::DEFAULT_HUNGER);
    }
    

    return description;
}

string Mountain::getShortDescription(){
    
    return "mountain";
}

string Mountain::getLongDescription(){
    return "You arrive at a tall and craggy mountain.";
}

string Mountain::visit(Player& p){
    int chance = rand() % 100;
    
    string description = "You notice a path up and follow it.";
    
    if(chance < 10){
    description += "\nWhile following the path, you fall and get badly injured in the crags.";
    description += "\nWith no one to help, you die.";
    p.setHealth(0);
    }
    else if(chance >= 10 || chance <= 35){
        description += "\nYou find some mushrooms growing next to a stream.";
        description += "\nYou drink and eat the mushrooms.";
        if(chance < 15){ 
            description += "\nThe mushrooms were poisonous and make you vomit.";
            p.setHunger(p.getHunger() - 2);
        }
        else{
            description +="\nThe mushrooms are tasty.";
            p.setHunger(p.getHunger() + 1);
        }
        p.setThirst(Player::DEFAULT_THIRST);
        
    }
    else if(chance >= 95){
        description += "\nThe path leads to the mountains peak.";
        description += "\nYou find a hot pool, just warm enough to soak and rest in.";
        description += "\nWhile enjoying the view, the soak revitalizes you.";
        description += "\nYou feel better than you did before the journey began.";
        p.setHealth(Player::DEFAULT_HEALTH * 2);
        p.setHunger(Player::DEFAULT_HUNGER * 2);
        p.setThirst(Player::DEFAULT_THIRST * 2);
    }

    return description;
}

string Tundra::getShortDescription(){
    return "tundra";
}

string Tundra::getLongDescription(){
    return "You arrive at a cold and barren tundra.";
}

string Tundra::visit(Player& p){
    int chance = rand() % 100;
    string description = "You see a ravine and decide to look into it.";
    if(chance < 10){
        description += "\nWhile staring down, a wolf attacks.";
        p.setHealth(p.getHealth() - 1);
    }
    else if(chance >= 10 || chance < 30){
        description += "\nA nest with eggs in it is easily within reach.";
        if(chance < 20){
            description += "\nYou try to grab the eggs but knock the nest down the ravine.";
            p.setHunger(p.getHunger() - 1);
        }
        else{
            description +="\nYou grab the eggs and enjoy them.";
            p.setHunger(p.getHunger() + 1);
        }
    }
    else{
        description += "\nThere isn't much of interest.";
    }
    return description;
}

string Waterfall::getShortDescription(){
    return "waterfall";
}

string Waterfall::getLongDescription(){
    return "You arrive at beautiful waterfall.";
}

string Waterfall::visit(Player& p){
    int chance = rand() % 10;
    string description = "The water is crystal clear and nice and cool";
    if(chance < 1){
        description += "\nYou found a canteen and fill it";
        p.setThirst(Player::DEFAULT_THIRST * 2);
    }
    else p.setThirst(Player::DEFAULT_THIRST);
    
    return description;
}

string Village::getShortDescription(){
    return "village";
}

string Village::getLongDescription(){
    return "You arrive at a small village.";
}

string Village::visit(Player& p){
    int chance = rand() % 20;
    string description = "No one is outside. You decide to knock on doors.";
    if(chance < 5){
        description += "\nA friendly villager opens the first door you knock on.";
        description += "\nYou are invited to spend the night after having a warm meal.";
        p.setHealth(Player::DEFAULT_HEALTH);
        p.setHunger(Player::DEFAULT_HUNGER);
        p.setThirst(Player::DEFAULT_THIRST);
    }
    else if(chance >= 18){
        description += "\nA person is screaming in a language you don't understand.";
        description += "\nThey open the door and point a gun at you.";
        if(chance = 18){
            description += "\nYou run away as fast as you can.";
            p.setHunger(p.getHunger() - 1);
            p.setThirst(p.getThirst() - 1);
        }
        else{
            description +="\nYou get shot and die.";
            p.setHealth(0);
        }
    }
    else{
        description += "\nThe village appears to be abandoned.";
        description += "\nYou find an unlocked home with canned fruit cups.";
        p.setHunger(p.getHunger() + 2);
    }
    return description;
}