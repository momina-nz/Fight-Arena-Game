#include "Profession.h"
#include "Creature.h"

//constructor
Profession::Profession(int strengthBonus, int dexterityBonus, int healthBonus, int cooldownTimer)
{
    this->strengthBonus = strengthBonus;
    this->dexterityBonus = dexterityBonus;
    this->healthBonus = healthBonus;
    this->cooldownTimer = cooldownTimer;
}

//function for handling cooldowns
 void Profession::decreaseCooldownTimer()
{
    cooldownTimer = (cooldownTimer > 0) ? cooldownTimer - 1 : 0;
}

 //getters / setters
int Profession::getStrengthBonus() const
{
    return strengthBonus;
}

int Profession::getDexterityBonus() const
{
    return dexterityBonus;
}

int Profession::getHealthBonus() const
{
    return healthBonus;
}

int Profession::getCooldownTimer() const
{
    return cooldownTimer;
}

void Profession ::setCooldownTimer(int cooldownTimer)
{
    this->cooldownTimer = cooldownTimer;
}


// Subclasses of Profession with their constructors and professional alilities

Gladiator:: Gladiator() : Profession(5, 5, 150, 3)
    {
    }

void Gladiator::professionalAbility(Creature* self, Creature* target)
    {
        int damage = self->getStrength() + self->getDexterity();
        target->decreaseHealth(damage);
        setCooldownTimer(3);
    }



Thug::Thug() : Profession(2, 10, 80, 4)
    {
    }

void Thug::professionalAbility(Creature* self, Creature* target)
    {
        int damage = 2 * self->getDexterity();
        target->decreaseHealth(damage);
        setCooldownTimer(4);
    }


Brute::Brute() : Profession(10, 2, 150, 4)
    {
    }

void Brute::professionalAbility(Creature* self, Creature* target)
    {
        int damage = 2 * self->getStrength();
        target->decreaseHealth(damage);
        setCooldownTimer(4);
    }