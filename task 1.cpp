#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int randomNum = rand() % 100 + 1;
    int userGuess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have generated a random number between 1 to 100." << endl;
    cout << "Can you guess what it is ?" << endl;

    while (true) {
        cout << "Enter your guess : ";
        cin >> userGuess;

        if (userGuess > randomNum) {
            cout << "Your guess is too high. Try again!" << endl;
        } else if (userGuess < randomNum) {
            cout << "Your guess is too low. Try again!" << endl;
        } else {
            cout << "Congratulations! You guessed the correct number : " << randomNum << endl;
            break;
        }
    }
    return 0;
}

