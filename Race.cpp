#include "Race.h"
#include "Creature.h"

//constructor
Race::Race(int baseStrength, int baseDexterity, int baseHealth, int cooldownTimer)
{
    this->baseStrength = baseStrength;
    this->baseDexterity = baseDexterity;
    this->baseHealth = baseHealth;
    this->cooldownTimer = cooldownTimer;
}

//function for handling cooldowns
 void Race::decreaseCooldownTimer()
{
    cooldownTimer = (cooldownTimer > 0) ? cooldownTimer - 1 : 0;
}

 //getters / setters
int Race::getBaseStrength() const
{
    return baseStrength;
}

int Race::getBaseDexterity() const
{
    return baseDexterity;
}

int Race::getBaseHealth() const
{
    return baseHealth;
}

int Race::getCooldownTimer() const
{
    return cooldownTimer;
}

void Race::setCooldownTimer(int cooldownTimer)
{
    this->cooldownTimer = cooldownTimer;
}

// Subclasses of Race with their constructor and racialAbilities

Ogre::Ogre() : Race(10, 2, 200, 3)
{
}

void Ogre::racialAbility(Creature* self, Creature* target)
{
    self->increaseHealth(20);
    self->increaseStrength(1);
    setCooldownTimer(3);
}

Sprite::Sprite() : Race(2, 10, 150, 4) {}

void Sprite :: racialAbility(Creature* self, Creature* target)
{
    Race* race = target->getRace();
    Profession* profession = target->getProfession();

    race->setCooldownTimer(race->getCooldownTimer() + 2);
    profession->setCooldownTimer(profession->getCooldownTimer() + 2);
    setCooldownTimer(4);
}

Ghoul::Ghoul() : Race(6, 6, 180, 4) {}

void Ghoul::racialAbility(Creature* self, Creature* target)
{
    int damage = self->getDexterity();
    self->increaseHealth(damage / 2);
    target->decreaseHealth(damage);
    setCooldownTimer(4);
}