# FightArena

## Overview
FightArena is a **C++-based** arena combat simulation where players can select two opponents who battle each other. The combatants have unique **races and professions**, affecting their **attributes and abilities**. The battle continues until one opponent runs out of health.

## Features
- 🏹 **Turn-based Combat** - Fighters take turns attacking each other.
- 🔥 **Races & Professions** - Choose from different races and professions, each with unique abilities.
- 💪 **Attributes** - Strength, Dexterity, and Health define the effectiveness of each fighter.
- 🎯 **Cooldown System** - Special abilities have cooldown timers before they can be reused.

## Files in the Repository
| File            | Description |
|----------------|-------------|
| `Creature.cpp` | Implements the Creature class handling combat logic. |
| `Creature.h` | Header file defining the Creature class. |
| `Main.cpp` | Main driver file that handles the game flow. |
| `Profession.cpp` | Implements different professions and their abilities. |
| `Profession.h` | Header file defining the Profession class and subclasses. |
| `Race.cpp` | Implements different races and their abilities. |
| `Race.h` | Header file defining the Race class and subclasses. |
| `FightArena.sln` | Visual Studio solution file for the project. |

## Installation and Compilation
### Prerequisites
- **C++ Compiler (g++ or MSVC)**

### Compilation
To compile using g++:
```sh
 g++ -o FightArena Main.cpp Creature.cpp Race.cpp Profession.cpp -std=c++11
```

To compile using Visual Studio:
- Open `FightArena.sln` in Visual Studio and **Build** the solution.

### Running the Program
```sh
 ./FightArena
```

## How to Play
1. **Choose two creatures**, each with a race and profession.
2. Creatures will take **turns attacking each other**.
3. They will use **racial or professional abilities** when available, otherwise perform a basic attack.
4. The battle ends when **one creature runs out of health**.

## Example Gameplay
```
Creature 1
Choose a race:
1. Ogre	2. Sprite	3. Ghoul
> 1
Choose a profession:
1. Gladiator	2. Thug	3. Brute
> 2

Creature 2
Choose a race:
1. Ogre	2. Sprite	3. Ghoul
> 3
Choose a profession:
1. Gladiator	2. Thug	3. Brute
> 1

Combat Begins!
Creature 1 attacks Creature 2! Creature 2 Status:
Health: 180
Strength: 6
Dexterity: 6

Creature 2 attacks Creature 1! Creature 1 Status:
Health: 200
Strength: 10
Dexterity: 2

...

Creature 1 wins!
```

## Races & Professions
### **Races**
| Race | Base Strength | Base Dexterity | Base Health | Racial Ability |
|------|--------------|---------------|-------------|----------------|
| **Ogre** | 10 | 2 | 200 | *Enrage* - Restores 20 health & increases strength by 1. Cooldown: 3 |
| **Sprite** | 2 | 10 | 150 | *Charm* - Increases opponent’s cooldowns by 2. Cooldown: 4 |
| **Ghoul** | 6 | 6 | 180 | *Drain* - Deals dexterity damage & regains half as health. Cooldown: 4 |

### **Professions**
| Profession | Strength Bonus | Dexterity Bonus | Health Bonus | Professional Ability |
|-----------|---------------|----------------|-------------|----------------|
| **Gladiator** | +5 | +5 | +150 | *Cleave* - Deals (Strength + Dexterity) damage. Cooldown: 3 |
| **Thug** | +2 | +10 | +80 | *Rush* - Deals (2 * Dexterity) damage. Cooldown: 4 |
| **Brute** | +10 | +2 | +150 | *Bash* - Deals (2 * Strength) damage. Cooldown: 4 |

## Key Classes & Functions
- **Creature Class** - Handles all attributes and combat logic.
- **Race Class** - Defines unique race-based abilities.
- **Profession Class** - Defines unique profession-based abilities.
- `action(Creature* target)` - Determines attack type (racial/professional/basic).
- `printStatus(Creature *c)` - Displays the health and attributes of a creature.
- `createCreature()` - Allows users to create a creature based on inputs.

## Notes
- The program **does not** require external libraries beyond standard C++.
- No unnecessary prompts—just raw combat simulation.
- Uses **OOP principles** with **inheritance (Race, Profession)** and **polymorphism**.
