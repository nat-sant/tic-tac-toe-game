#include <iostream>
#include <fstream>
#include <sstream>
#include "gameBoard.h"
#include "gamePieces.h"
#include "enums.h"
using namespace std;

// Function to read the dimensions of the game board from an input stream.
int readBoardDimensions(ifstream& input, unsigned int& colCount, unsigned int& rowCount) {
    string lineContent;

    // Attempt to read a line from the input stream.
    if (getline(input, lineContent)) {
        istringstream iss(lineContent);

        // Try to extract colCount and rowCount from the line.
        if (iss >> colCount && iss >> rowCount) {
            return read_dimensions_success; // Dimensions read successfully.
        }
        else {
            return extraction_fail; // Failed to extract dimensions.
        }
    }
    else {
        return read_line_fail; // Failed to read a line from the input stream.
    }
}

// Function to read game pieces from an input stream and populate the gamePieces vector.
int readGamePiece(ifstream& input, vector<game_piece>& gamePieces, unsigned int& colWidthDim, unsigned int& rowHeightDim) {
    string lineContent;
    string pieceColor;
    string pieceName;
    string pieceDisplay;
    unsigned int xColCount;
    unsigned int yRowCount;
    bool success = false;

    // Iterate over lines in the input stream.
    while (getline(input, lineContent)) {
        istringstream iss(lineContent);

        // Attempt to extract game piece properties from the line.
        if (iss >> pieceColor && iss >> pieceName && iss >> pieceDisplay && iss >> yRowCount && iss >> xColCount) {
            piece_color tempColor = returnPieceColorElement(pieceColor);

            // Check if the color is valid.
            if (tempColor != piece_color::invalidColor) {
                // Check if the coordinates are within bounds.
                if (xColCount >= 0 && xColCount < colWidthDim && yRowCount >= 0 && yRowCount < rowHeightDim) {
                    success = true;
                    int index = (colWidthDim * yRowCount) + xColCount;

                    // Update the game piece in the vector.
                    gamePieces[index].pieceColorC = tempColor;
                    gamePieces[index].pieceDisplayD = pieceDisplay;
                    gamePieces[index].pieceNameN = pieceName;
                }
            }
        }
    }

    if (success) {
        return piece_read_success; // Game pieces read successfully.
    }
    else {
        return piece_read_fail; // Failed to read game pieces.
    }
}

// Function to print the game board using gamePieces and specified dimensions.
int printGameBoardPieces(const vector<game_piece>& gamePieces, unsigned int colWidthDim, unsigned int rowHeightDim, ostream& out) {
    bool dimension_match = false;

    // Check that the board dimensions match the gamePieces vector size.
    if (gamePieces.size() == colWidthDim * rowHeightDim) {
        dimension_match = true;
    }
    else {
        return dimension_match_fail; // Dimensions do not match.
    }

    // Print the game board.
    for (int verticalDimension = rowHeightDim - 1; verticalDimension >= 0; verticalDimension--) {
        out << verticalDimension;
        for (int horizontalDimension = 0; horizontalDimension < colWidthDim; horizontalDimension++) {
            int index = colWidthDim * verticalDimension + horizontalDimension;
            out << gamePieces[index].pieceDisplayD;
        }
        out << endl;
    }

    out << " ";
    for (int i = 0; i < colWidthDim; i++) {
        out << i;
    }
    out << endl;

    return game_board_print_success; // Game board printed successfully.
}
