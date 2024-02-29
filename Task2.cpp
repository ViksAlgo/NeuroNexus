/*
TASK 1 - NUMBER GUESSING GAME
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double num1, num2;
    char operation;

    cout << "Welcome to the Fun-tastic Calculator!" << endl;

    // Get two numbers from the user
    cout << "Enter the first magical number: ";
    cin >> num1;

    cout << "Enter the second mystical number: ";
    cin >> num2;

    // Get the operation from the user
    cout << "Choose a spell (+, -, *, /): ";
    cin >> operation;

    // Perform the operation based on the chosen spell
    switch (operation)
    {
    case '+':
        cout << "Abracadabra! The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Voila! The enchanting result of " << num1 << " minus " << num2 << " is " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Presto! The magical product of " << num1 << " and " << num2 << " is " << num1 * num2 << endl;
        break;
    case '/':
        // Handle division by zero
        if (num2 == 0)
        {
            cout << "Oops! You've summoned an error. Division by zero is not allowed in this magical realm." << endl;
        }
        else
        {
            cout << "Hocus Pocus! The mystical result of " << num1 << " divided by " << num2 << " is " << num1 / num2 << endl;
        }
        break;
    default:
        cout << "Oh no! The magic is confused. Please choose a valid spell." << endl;
    }

    return 0;
}
