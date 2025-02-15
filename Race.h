#pragma once
#include <iostream>
#include "Profession.h"

using namespace std;

//Forward Declaration
class Creature;

//Abstract Race class
class Race     
{
protected:  //Attributes
    int baseStrength;
    int baseDexterity;
    int baseHealth;
    int cooldownTimer;

public:
    Race(int baseStrength, int baseDexterity, int baseHealth, int cooldownTimer); //constructor

    virtual void racialAbility(Creature* self, Creature* target) = 0;

    //function for handling cooldowns
    virtual void decreaseCooldownTimer();

    //getters / setters
    int getBaseStrength() const;

    int getBaseDexterity() const;

    int getBaseHealth() const;

    int getCooldownTimer() const;

    void setCooldownTimer(int cooldownTimer);
};

// Subclasses of Race with their constructor and racialAbilities
class Ogre : public Race
{
public:
    Ogre()  ;

    void racialAbility(Creature* self, Creature* target);
};

class Sprite : public Race
{
public:
    Sprite() ;

    void racialAbility(Creature* self, Creature* target);
};

class Ghoul : public Race
{
public:
    Ghoul()  ;

    void racialAbility(Creature* self, Creature* target);
};