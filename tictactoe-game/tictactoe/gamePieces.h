#pragma once
#include <string>

using namespace std;

// Enumeration to represent piece colors.
enum struct piece_color
{
    invalidColor = 0,  // Invalid color code.
    noColor = 1,       // No color.
    red = 2,           // Red color.
    black = 3,         // Black color.
    white = 4          // White color.
};

// Function to return a string representation of a piece_color enumeration.
string returnPieceColor(piece_color color);

// Function to return a piece_color enumeration based on a color string.
piece_color returnPieceColorElement(string colorString);

// Function to convert a string to lowercase.
void convertLowercase(string cppStyleStrings);

// Struct to represent a game piece.
struct game_piece
{
    piece_color pieceColorC;    // The color of the game piece.
    string pieceNameN;          // The name of the game piece.
    string pieceDisplayD;       // The display character of the game piece.
};
