#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {

    cout << "This bag can hold up to 40 dice with different sides." << endl;

    srand(time(0)); // Random number generation for die removal

    int DiceInBag[6] = {0}; // Count of each type of dice
    int DiceSides[] = {4, 6, 8, 10, 12, 20}; // Sides that are allowed
    int TotalDiceInBag = 0; // Initializing total number of dice in the bag
    const int MaxCapacity = 40; // Max capacity of the bag

    char choice;
    bool quit = false;

    while (!quit) {
        cout << "Would you like to add (+) dice to the bag, remove a (-) die from the bag, or quit (q)? " ;
        cin >> choice;

        switch (choice) {
            case '+': {
                int quantity;
                bool ValidQuantity = false;
                bool ExceedsCapacity = false;

                while (!ValidQuantity) {
                    cout << "Please enter quantity of dice to add (up to 10): ";
                    cin >> quantity;

                    if (quantity <= 0 || quantity > 10) {
                        cout << endl << "Invalid quantity. Please enter a quantity between 1 and 10." << endl << endl;
                    } else {
                        ValidQuantity = true;
                        // Check if adding this quantity will exceed the limit
                        if (TotalDiceInBag + quantity > MaxCapacity) {
                            cout << endl << "This exceeds the max capacity of the bag. Please try a different option." << endl;
                            ExceedsCapacity = true; // Flags this as true
                        }
                    }
                }

                if (ExceedsCapacity)
                    break; // Go to main choice

                // Adds dice to the bag
                for (int i = 0; i < quantity; ++i) {
                    int sides;
                    bool ValidSides = false;

                    while (!ValidSides) {
                        cout << "Enter number of sides for dice " << (i + 1) << " (4, 6, 8, 10, 12, or 20): ";
                        cin >> sides;

                        // Validates sides
                        for (int j = 0; j < 6; ++j) {
                            if (sides == DiceSides[j]) {
                                ValidSides = true;
                                DiceInBag[j]++; // Increments 
                                TotalDiceInBag++; // Increments total dice count
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

                // Randomly pull a dice from the bag
                int RandomDiceIndex = rand() % TotalDice; // Random index within total dice count
                int ChosenDice = 0;
                for (int i = 0; i < 6; ++i) {
                    ChosenDice += DiceInBag[i];
                    if (RandomDiceIndex < ChosenDice) {
                        cout << endl << "You drew a D" << DiceSides[i] << "." << endl;
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
        cout << endl << "Contents of bag: " << endl;
        bool isEmpty = true;
        for (int i = 0; i < 6; ++i) {
            if (DiceInBag[i] > 0) {
                cout << DiceInBag[i] << " D" << DiceSides[i] << " " << endl;
                isEmpty = false;
            }
        }
        if (isEmpty){
            cout << "The bag is empty." << endl << endl;
        }
        else{
            cout << "Total dice in bag:" << TotalDiceInBag << endl << endl;
        }
    }

    return 0;
}
