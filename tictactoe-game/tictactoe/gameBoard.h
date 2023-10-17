#pragma once
#include <string>
#include <vector>
#include "gamePieces.h"
using namespace std;

// Function to read the dimensions of the game board from an input stream.
// Updates colCount and rowCount with the read values.
int readBoardDimensions(ifstream& input, unsigned int& colCount, unsigned int& rowCount);

// Function to read game pieces from an input stream and populate the gamePieces vector.
// Takes the dimensions colWidthDim and rowHeightDim as parameters.
int readGamePiece(ifstream& input, vector<game_piece>& gamePieces, unsigned int& colWidthDim, unsigned int& rowHeightDim);

// Function to print the game board using the provided game pieces and dimensions.
// Outputs the game board to the specified output stream (out).
int printGameBoardPieces(const vector<game_piece>& gamePieces, unsigned int colWidthDim, unsigned int rowHeightDim, ostream& out);
