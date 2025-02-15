#pragma once
#include <iostream>
#include "Race.h"

using namespace std;

//Forward Declaration
class Creature;

//Abstract Profession class
class Profession
{
protected:  //Attributes
    int strengthBonus;
    int dexterityBonus;
    int healthBonus;
    int cooldownTimer;

public:
    Profession(int strengthBonus, int dexterityBonus, int healthBonus, int cooldownTimer); //constructor

    virtual void professionalAbility(Creature* self, Creature* target) = 0;

    //function for handling cooldowns
    virtual void decreaseCooldownTimer();

    //getters / setters
    int getStrengthBonus() const;

    int getDexterityBonus() const;

    int getHealthBonus() const;

    int getCooldownTimer() const;

    void setCooldownTimer(int cooldownTimer);
};

// Subclasses of Profession with their constructors and professional alilities

class Gladiator : public Profession
{
public:
    Gladiator() ;

    void professionalAbility(Creature* self, Creature* target);
};

class Thug : public Profession
{
public:
    Thug() ;

    void professionalAbility(Creature* self, Creature* target);
};

class Brute : public Profession
{
public:
    Brute() ;

    void professionalAbility(Creature* self, Creature* target);
};