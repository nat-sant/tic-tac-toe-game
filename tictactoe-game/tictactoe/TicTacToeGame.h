#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "gamePieces.h"
#include "enums.h"
#include "gameBoard.h"
using namespace std;

class TicTacToeGame {
private:
    int xColWidth;          // Width of the game board
    int yRowHeight;         // Height of the game board
    unsigned int xBoardDim; // Dimension of the board on the x-axis
    unsigned int yBoardDim; // Dimension of the board on the y-axis
    int turnCount;          // Number of turns taken in the game
    bool playerX;           // Indicates the current player (true for X, false for O)
    string playerXMoves;    // Stores the moves made by Player X
    string playerOMoves;    // Stores the moves made by Player O
    vector<game_piece> gameBoard; // Stores the game board state
public:
    TicTacToeGame();        // Constructor to initialize the game
    bool done();            // Checks if a player has won
    bool draw();            // Checks if the game has ended in a draw
    int prompt(unsigned int& a, unsigned int& b); // Prompts for player input
    int turn();             // Manages a player's turn
    int play();             // Main game loop
    friend std::ostream& operator << (std::ostream& out, const TicTacToeGame& game); // Overloaded output operator to print the game state
};
