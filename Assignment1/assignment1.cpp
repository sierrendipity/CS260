#include <cstdio>
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

using namespace std;

int main() {
    srand(time(0)); // Random number generation for die removal

    int DiceInBag[6] = {0}; // For D4, D6, D8, D10, D12, D20
    int DiceSides[] = {4, 6, 8, 10, 12, 20}; // Sides that are allowed
    int TotalDiceInBag = 0; // Total number of dice in the bag
    const int MaxCapacity = 100; // Max capacity of the bag

    char choice;
    bool quit = false;

    while (!quit) {
        cout << "Would you like to add (+) dice to the bag, remove a (-) die from the bag, or quit (q)? ";
        cin >> choice;

        switch (choice) {
            case '+': {
                int quantity;
                cout << "Please enter quantity of dice to add (up to 10): ";
                cin >> quantity;

                // Check if adding this quantity will exceed the limit
                if (TotalDiceInBag + quantity > MaxCapacity) {
                    cout << "Adding these dice will exceed the bag's capacity. Please try again." << endl;
                    break; // Continue the loop without adding dice
                }

                // Continue the loop without adding dice
                if (quantity <= 0 || quantity > 10) {
                    cout << "Invalid quantity. Dice not added. Please try again." << endl;
                    break;
                }

                // Add dice to the bag
                for (int i = 0; i < quantity; ++i) {
                    int sides;
                    bool ValidSides = false;

                    while (!ValidSides) {
                        cout << "Enter number of sides for dice " << (i + 1) << " (4, 6, 8, 10, 12, or 20): ";
                        cin >> sides;

                        // Validate sides
                        for (int j = 0; j < 6; ++j) {
                            if (sides == DiceSides[j]) {
                                ValidSides = true;
                                DiceInBag[j]++;
                                TotalDiceInBag++; // Increment total dice count
                                break;
                            }
                        }

                        if (!ValidSides) {
                            cout << "Invalid number of sides. Please try again." << endl;
                        }
                    }
                }
                break;
            }
            case '-': {
                // Remove a dice from the bag
                int TotalDice = 0;
                for (int i = 0; i < 6; ++i)
                    TotalDice += DiceInBag[i];

                if (TotalDice == 0) {
                    cout << "The bag is empty" << endl;
                    break; // Continue the loop without removing dice
                }

                // Randomly select a dice from the bag
                int RandomDiceIndex = rand() % TotalDice; // Random index within total dice count
                int ChosenDice = 0;
                for (int i = 0; i < 6; ++i) {
                    ChosenDice += DiceInBag[i];
                    if (RandomDiceIndex < ChosenDice) {
                        cout << "You drew a D" << DiceSides[i] << "." << endl;
                        DiceInBag[i]--; // Decrement the count of the selected dice
                        TotalDiceInBag--; // Decrement total dice count
                        break;
                    }
                }
                break;
            }
            case 'q':
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please choose '+' to add, '-' to remove, or 'q' to quit." << endl;
        }

        // Outputs the bags contents.
        cout << "Contents of bag: ";
        bool isEmpty = true;
        for (int i = 0; i < 6; ++i) {
            if (DiceInBag[i] > 0) {
                cout << DiceInBag[i] << " D" << DiceSides[i] << " ";
                isEmpty = false;
            }
        }
        if (isEmpty)
            cout << "The bag is empty.";
        cout << endl;
    }

    return 0;
}
