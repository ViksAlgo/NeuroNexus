/*
TASK 3 - TIC-TAC-TOE GAME
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Function to display the game board
void displayBoard()
{
    cout << "  |  |  " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        if (i < 2)
        {
            cout << "-----+-----+-----" << endl;
        }
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // Empty space found, not a draw
            }
        }
    }
    return true; // Board is full, it's a draw
}

int main()
{
    char currentPlayer = 'X';
    int moveCount = 0;

    while (true)
    {
        displayBoard();

        // Get player input
        int row, col;
        cout << currentPlayer << "'s turn, enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        row--; // Adjust for 0-based indexing
        col--;

        // Check if the position is already filled or invalid
        if (board[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2)
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update board and check for win or draw
        board[row][col] = currentPlayer;
        moveCount++;

        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << currentPlayer << " wins!" << endl;
            break;
        }
        else if (isDraw())
        {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask to play again
    char choice;
    cout << "Do you want to play again (y/n)? ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        // Reset game for new round
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        moveCount = 0;
        main(); // Start a new game
    }
    else
    {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}
