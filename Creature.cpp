#include "Creature.h"
#include "Race.h"
#include "Profession.h"

//constructor
Creature::Creature(Race* race, Profession* profession) : race(race), profession(profession)
{
    strength = race->getBaseStrength() + profession->getStrengthBonus();
    dexterity = race->getBaseDexterity() + profession->getDexterityBonus();
    maxHealth = race->getBaseHealth() + profession->getHealthBonus();
    health = maxHealth;
}

Creature::~Creature()  //destructor
{
    delete race;
    delete profession;
}

//helping functions in implementing racial and professional abilities
void Creature::increaseHealth(int amount)
{
    health += amount;
}

void Creature::decreaseHealth(int amount)
{
    health -= amount;
    if (health < 0)
    {
        health = 0;
    }
}

void Creature::increaseStrength(int amount)
{
    strength += amount;
}

void Creature::action(Creature* target)       //Method action to choose between racial/professional/basic attack
{
    race->decreaseCooldownTimer();
    profession->decreaseCooldownTimer();

    if (race->getCooldownTimer() == 0)
    {
        race->racialAbility(this, target);
        return;
    }
    else if (profession->getCooldownTimer() == 0)
    {
        profession->professionalAbility(this, target);
        return;
    }
    else
    {
        basicAttack(target);
    }
}

void Creature::basicAttack(Creature* target)
{
    int damage = 0;
    if (strength > dexterity)
    {
        damage = strength;
    }
    else
    {
        damage = dexterity;
    }

    target->decreaseHealth(damage);
}

//getters
int Creature::getHealth() const
{
    return health;
}

int Creature::getStrength() const
{
    return strength;
}

int Creature::getDexterity() const
{
    return dexterity;
}

Race* Creature::getRace() const
{
    return race;
}

Profession* Creature::getProfession() const
{
    return profession;
}

// Function to create a creature based on user input
Creature* createCreature()
{
    int raceChoice, professionChoice;

    cout << "Choose a race:" << endl;
    cout << "\t1. Ogre\t2. Sprite\t3. Ghoul" << endl;
    cin >> raceChoice;

    cout << "Choose a profession:" << endl;
    cout << "1. Gladiator\t2. Thug\t3. Brute" << endl;
    cin >> professionChoice;

    Race* race = nullptr;
    Profession* profession = nullptr;

    switch (raceChoice)
    {
    case 1:
        race = new Ogre();
        break;
    case 2:
        race = new Sprite();
        break;
    case 3:
        race = new Ghoul();
        break;
    default:
        cout << "Invalid race choice. Defaulting to Ogre." << endl;
        race = new Ogre();
        break;
    }

    switch (professionChoice)
    {
    case 1:
        profession = new Gladiator();
        break;
    case 2:
        profession = new Thug();
        break;
    case 3:
        profession = new Brute();
        break;
    default:
        cout << "Invalid profession choice. Defaulting to Gladiator." << endl;
        profession = new Gladiator();
        break;
    }

    return new Creature(race, profession);
}

// Function to print creature status
void printStatus(const Creature* creature)
{
    cout << "Health: " << creature->getHealth() << endl;
    cout << "Strength: " << creature->getStrength() << endl;
    cout << "Dexterity: " << creature->getDexterity() << endl;

    Race* race = creature->getRace();
    if (race)
    {
        cout << "Race Cooldown Timer: " << race->getCooldownTimer() << endl;
    }

    Profession* profession = creature->getProfession();
    if (profession)
    {
        cout << "Profession Cooldown Timer: " << profession->getCooldownTimer() << endl;
    }
}