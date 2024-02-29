/*
TASK 1 - NUMBER GUESSING GAME
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    srand(time(0));

    int lowerBound, upperBound;

    cout << "Welcome to the guessing game!" << endl;
    cout << "Enter the range for the number guessing game." << endl;

    // Get the lower and upper bounds from the user
    cout << "Enter the lower bound: ";
    cin >> lowerBound;
    cout << "Enter the upper bound: ";
    cin >> upperBound;

    // Validate the input
    if (lowerBound >= upperBound)
    {
        cout << "Invalid range. Please ensure the lower bound is less than the upper bound." << endl;
        return 1; // Exit
    }

    // random number within the specified range
    int secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;

    int guess;
    bool guessedCorrectly = false;

    cout << "I'm thinking of a number between " << lowerBound << " and " << upperBound << ". Can you guess it?" << endl;

    while (!guessedCorrectly)
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < secretNumber)
        {
            cout << "Your guess is too low. Try again." << endl;
        }
        else if (guess > secretNumber)
        {
            cout << "Your guess is too high. Try again." << endl;
        }
        else
        {
            guessedCorrectly = true;
            cout << "Congratulations! You guessed the number!" << endl;
        }
    }

    return 0;
}
