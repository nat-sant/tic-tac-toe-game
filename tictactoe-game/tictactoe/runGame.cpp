// This file contains the 'main' function. Program execution begins and ends here.

#include <iostream>
#include <fstream>
#include <sstream>
#include "enums.h"
#include "gamePieces.h"
#include "gameBoard.h"
#include "TicTacToeGame.h"
using namespace std;

// Function to display usage instructions and return an error code.
int usageMessage(char* programName)
{
    cout << "To run the program, type: " << programName << ". To run a file, type: <fileName>.txt." << endl;
    return wrong_args;
}

// The code provides a simple command-line interface to play a Tic-Tac-Toe game.
// It checks the command-line argument and ensures it's "TicTacToe" to start the game.
int main(int argc, char* argv[])
{
    // Check for exactly one argument passed and whether that argument is "TicTacToe"
    if (argc != argumentCount || string(argv[fileName]) != "TicTacToe")
    {
        return usageMessage(argv[programName]);
    }

    // Create a TicTacToeGame object and start the game.
    TicTacToeGame test;
    return test.play();
}