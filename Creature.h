#pragma once
#include <iostream>

using namespace std;

//Forward Declaration
class Race;
class Profession;

class Creature
{
private: //Attributes
    Race * race;
    Profession * profession;
    int strength;
    int dexterity;
    int maxHealth;
    int health;

public:
    Creature(Race* race, Profession* profession)  ; //constructor

    ~Creature(); //destructor

    //helping functions in implementing racial and professional abilities
    void increaseHealth(int amount);

    void decreaseHealth(int amount);

    void increaseStrength(int amount);

    //Method action to choose between racial/professional/basic attack
    void action(Creature* target);

    void basicAttack(Creature* target);

    //getters
    int getHealth() const;

    int getStrength() const;

    int getDexterity() const;

    Race * getRace() const;

    Profession * getProfession() const;
};

// Function to create a creature based on user input
Creature* createCreature();

// Function to print creature status
void printStatus(const Creature* creature);