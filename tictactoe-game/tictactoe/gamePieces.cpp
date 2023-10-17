#include <iostream>
#include <fstream>
#include "gamePieces.h"
using namespace std;

// Function to return a string representation of a piece_color enumeration.
string returnPieceColor(piece_color color) {
    if (color == piece_color::red) {
        return "red";
    }
    if (color == piece_color::white) {
        return "white";
    }
    if (color == piece_color::black) {
        return "black";
    }
    if (color == piece_color::noColor) {
        return "no color";
    }
    else {
        return "invalid color";
    }
}

// Function to return a piece_color enumeration based on a color string.
piece_color returnPieceColorElement(string colorString) {
    convertLowercase(colorString); // Convert the input string to lowercase.

    if (colorString == "red") {
        return piece_color::red;
    }
    if (colorString == "white") {
        return piece_color::white;
    }
    if (colorString == "black") {
        return piece_color::black;
    }
    if (colorString == " ") {
        return piece_color::noColor;
    }
    else {
        return piece_color::invalidColor;
    }
}

// Function to convert a string to lowercase.
void convertLowercase(string cppStyleStrings) {
    size_t length = cppStyleStrings.length();

    for (size_t i = 0; i < length; i++) {
        if (cppStyleStrings[i] >= 'A' && cppStyleStrings[i] <= 'Z') {
            cppStyleStrings[i] = cppStyleStrings[i] + 32;
        }
    }
}
