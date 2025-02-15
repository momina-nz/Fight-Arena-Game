#include <iostream>
#include "Creature.h"

using namespace std;

int main()
{
    // Create two creatures
    cout << "Creature 1" << endl;
    Creature* creature1 = createCreature();
    cout << endl
        << "Creature 2" << endl;
    Creature* creature2 = createCreature();
    cout << endl;

    cout << "Creature 1 Status:" << endl;
    printStatus(creature1);
    cout << endl;

    cout << "Creature 2 Status:" << endl;
    printStatus(creature2);
    cout << endl;

    // Main loop
    while (creature1->getHealth() > 0 && creature2->getHealth() > 0)
    {
        creature1->action(creature2);
        cout << "Creature 1 attacks Creature 2!  Creature 2 Status:" << endl;
        printStatus(creature2);
        cout << endl;

        if (creature2->getHealth() <= 0)
        {
            break; // Creature 2 defeated
        }

        // Creature 2 attacks Creature 1
        creature2->action(creature1);
        cout << "Creature 2 attacks Creature 1!  Creature 1 Status:" << endl;
        printStatus(creature1);
        cout << endl;
    }

    // Print the winner
    cout << endl;
    cout << "Combat Result" << endl;
    cout << "-------------" << endl;
    if (creature1->getHealth() <= 0 && creature2->getHealth() <= 0)
    {
        cout << "It's a draw!" << endl;
    }
    else if (creature1->getHealth() <= 0)
    {
        cout << "Creature 2 wins!" << endl;
    }
    else
    {
        cout << "Creature 1 wins!" << endl;
    }

    // Clean up
    delete creature1;
    delete creature2;

    return 0;
}
