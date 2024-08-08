#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));
    int number, guess, attempts = 0, maxAttempts;
    int range;
    int difficulty;

    cout << "Select difficulty level (1- Easy, 2- Medium, 3- Hard): ";
    cin >> difficulty;

    switch(difficulty) {
        case 1: range = 10; break;
        case 2: range = 50; break;
        case 3: range = 100; break;
        default:
            cout << "Invalid difficulty level. Defaulting to Easy." << endl;
            range = 10;
    }

    number = rand() % range + 1;
    maxAttempts = (difficulty == 1) ? 5 : (difficulty == 2) ? 10 : 15;

    cout << "Guess the number (between 1 and " << range << "): ";

    do {
        cin >> guess;
        attempts++;

        if (guess > number)
            cout << "Too high! Try again: ";
        else if (guess < number)
            cout << "Too low! Try again: ";
        else
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;

        if (attempts >= maxAttempts) {
            cout << "You've reached the maximum number of attempts. The number was " << number << "." << endl;
            break;
        }

    } while (guess != number);

    return 0;
}
