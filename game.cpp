#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get random computer input between 1 and 6
int getComputerInput() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(0)); // Seed the random number generator
    
    int playerScore = 0, computerScore = 0;
    int playerInput, computerInput;
    char choice;

    cout << "Welcome to Hand Cricket Game!\n";
    cout << "Choose batting (1) or bowling (2): ";
    cin >> choice;

    if (choice == '1') {  // Player chooses to bat first
        cout << "\nYou are batting first.\n";
        // Player's batting phase
        while (true) {
            cout << "\nEnter a number between 1 and 6: ";
            cin >> playerInput;

            computerInput = getComputerInput();
            cout << "Computer played: " << computerInput << endl;

            if (playerInput == computerInput) {
                cout << "You're out!\n";
                break;
            } else {
                playerScore += playerInput;
                cout << "Your score: " << playerScore << endl;
            }
        }

        // Computer's batting phase
        cout << "\nComputer is batting now.\n";
        while (computerScore <= playerScore) {
            cout << "\nEnter a number between 1 and 6 (for bowling): ";
            cin >> playerInput;

            computerInput = getComputerInput();
            cout << "Computer played: " << computerInput << endl;

            if (playerInput == computerInput) {
                cout << "Computer is out!\n";
                break;
            } else {
                computerScore += computerInput;
                cout << "Computer score: " << computerScore << endl;
            }
        }

    } else if (choice == '2') {  // Player chooses to bowl first
        cout << "\nYou are bowling first.\n";
        // Computer's batting phase
        while (true) {
            cout << "\nEnter a number between 1 and 6 (for bowling): ";
            cin >> playerInput;

            computerInput = getComputerInput();
            cout << "Computer played: " << computerInput << endl;

            if (playerInput == computerInput) {
                cout << "Computer is out!\n";
                break;
            } else {
                computerScore += computerInput;
                cout << "Computer score: " << computerScore << endl;
            }
        }

        // Player's batting phase
        cout << "\nYou are batting now.\n";
        while (playerScore <= computerScore) {
            cout << "\nEnter a number between 1 and 6: ";
            cin >> playerInput;

            computerInput = getComputerInput();
            cout << "Computer played: " << computerInput << endl;

            if (playerInput == computerInput) {
                cout << "You're out!\n";
                break;
            } else {
                playerScore += playerInput;
                cout << "Your score: " << playerScore << endl;
            }
        }
    }

    // Determining the winner
    if (playerScore > computerScore) {
        cout << "\nCongratulations! You win with a score of " << playerScore << " against " << computerScore << "!\n";
    } else if (computerScore > playerScore) {
        cout << "\nComputer wins with a score of " << computerScore << " against " << playerScore << "!\n";
    } else {
        cout << "\nIt's a tie!\n";
    }

    return 0;
}
