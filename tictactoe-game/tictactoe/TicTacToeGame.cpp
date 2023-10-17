#include "TicTacToeGame.h"

// Constructor for the TicTacToeGame class
TicTacToeGame::TicTacToeGame()
    : xColWidth(5), yRowHeight(5), turnCount(0), playerX(true)
{
    // Initialize the game board with empty squares
    int boardSquareCount = xColWidth * yRowHeight;
    for (int i = 0; i < boardSquareCount; i++)
    {
        string emptyName;
        game_piece emptyBoardSquare = { piece_color::noColor, emptyName, " " };
        gameBoard.push_back(emptyBoardSquare);
    }
}

// Check if the game is finished (win condition)
bool TicTacToeGame::done()
{
    unsigned int bottomLeftCoord = xColWidth + 1;
    unsigned int bottomRightCoord = 2 * xColWidth - 2;

    // Check X/O in horizontal line
    for (unsigned int i = bottomLeftCoord; i < gameBoard.size(); i += 5)
    {
        // Check if not empty and other constraints
        if (gameBoard[i].pieceDisplayD != " " &&
            (gameBoard[i].pieceDisplayD == gameBoard[i + 1].pieceDisplayD &&
                gameBoard[i].pieceDisplayD == gameBoard[i + 2].pieceDisplayD))
        {
            return true;
        }
    }

    // Check X/O in vertical line
    for (unsigned int i = bottomLeftCoord; i <= bottomRightCoord; i++)
    {
        // Check if not empty and other constraints
        if (gameBoard[i].pieceDisplayD != " " &&
            (gameBoard[i].pieceDisplayD == gameBoard[i + 5].pieceDisplayD &&
                gameBoard[i].pieceDisplayD == gameBoard[i + 10].pieceDisplayD))
        {
            return true;
        }
    }

    // Check diagonal lines (left to right, right to left)
    // Diagonal right to left increments by xColWidth - 1
    if (gameBoard[bottomLeftCoord].pieceDisplayD != " " &&
        (gameBoard[bottomLeftCoord].pieceDisplayD == gameBoard[bottomLeftCoord + 6].pieceDisplayD &&
            gameBoard[bottomLeftCoord].pieceDisplayD == gameBoard[bottomLeftCoord + 12].pieceDisplayD))
    {
        return true;
    }

    // Diagonal left to right increments by xColWidth + 1
    if (gameBoard[bottomRightCoord].pieceDisplayD != " " &&
        (gameBoard[bottomRightCoord].pieceDisplayD == gameBoard[bottomRightCoord + 4].pieceDisplayD &&
            gameBoard[bottomRightCoord].pieceDisplayD == gameBoard[bottomRightCoord + 8].pieceDisplayD))
    {
        return true;
    }

    return false;
}

// Check if the game is a draw
bool TicTacToeGame::draw()
{
    // Check if the game is a draw by counting the number of turns
    if (turnCount == 9 && done() != true) {
        return true;
    }
    return false;
}

// Prompt the current player for their move
int TicTacToeGame::prompt(unsigned int& a, unsigned int& b)
{
    string input;
    bool success = false;

    // Continue to prompt indefinitely until receiving a viable coordinate
    while (!success)
    {
        cout << "Enter 'quit' to end the game or a board square coordinate as a comma-separated pair of unsigned decimal integers, i.e. x,y" << endl;
        cin >> input;
        if (input == "quit")
        {
            return game_quit;
        }
        // Check for proper length
        else if (input.length() == 3)
        {
            // Check for proper formatting
            if (isdigit(input.at(0)) && (input.at(1) == ',' && isdigit(input.at(2)))
            {
                // Account for ASCII codes
                input[1] = ' ';
                    istringstream converter(input);
                    int xTemp;
                    int yTemp;
                    if (converter >> xTemp && converter >> yTemp) {
                        a = xTemp;
                            b = yTemp;
                            if ((a >= 1 && a < xBoardDim) && (b >= 1 && b < yBoardDim)) {
                                success = true;
                            }
                    }
            }
        }
    }
    if (success)
    {
        return prompt_enter_success;
    }
    else {
        return prompt_enter_fail;
    }
}

// Execute a player's turn
int TicTacToeGame::turn()
{
    unsigned int x;
    unsigned int y;
    bool success = false;

    if (playerX)
    {
        cout << "It's player X's turn." << endl;
    }
    if (!playerX)
    {
        cout << "It's player O's turn." << endl;
    }

    // Check whether user successfully entered a coordinate
    while (prompt(x, y) != game_quit)
    {
        cout << endl;
        unsigned int index = (xColWidth * y) + x;

        // Check whether the coordinate place entered is available and within appropriate dimensions
        if (gameBoard[index].pieceDisplayD == " " && ((x >= 0 && x < xBoardDim) && (y >= 0 && y < yBoardDim)))
        {
            if (playerX)
            {
                gameBoard[index].pieceColorC = piece_color::red;
                gameBoard[index].pieceDisplayD = "X";
                gameBoard[index].pieceNameN = "X";
                string xS = std::to_string(x);
                string yS = std::to_string(y);
                playerXMoves += xS + ", " + yS + "; ";
            }
            if (!playerX)
            {
                gameBoard[index].pieceColorC = piece_color::black;
                gameBoard[index].pieceDisplayD = "O";
                gameBoard[index].pieceNameN = "O";
                string xS = std::to_string(x);
                string yS = std::to_string(y);
                playerOMoves += xS + ", " + yS + "; ";
            }

            // Print board
            cout << *this << endl;

            // Print valid moves made
            if (playerX) {
                cout << playerXMoves << endl;
            }
            if (!playerX) {
                cout << playerOMoves << endl;
            }

            // Completed turn, switch player
            turnCount++;
            playerX = !playerX;
            return prompt_enter_success;
        }
    }
    return game_quit;
}

// Play the Tic-Tac-Toe game
int TicTacToeGame::play()
{
    // Print out the initial game board
    cout << *this;

    while (true)
    {
        // Check whether the user has entered "quit"
        if (turn() == game_quit) {
            cout << turnCount << " turns were played and the user quit." << endl;
            return game_quit;
        }

        // Check whether the game has been completed via WIN
        if (done() == true)
        {
            // Reverse these because the player is changed at the end of each turn
            if (playerX)
            {
                cout << "Player O won the game." << endl;
            }
            if (!playerX)
            {
                cout << "Player X won the game." << endl;
            }
            return game_win;
        }

        // Check whether the game has been completed via DRAW
        if (draw() == true)
        {
            cout << turnCount << " turns were played, this game ended in a draw and no winning moves remain." << endl;
            return game_draw;
        }
    }
}

// Overload the << operator to print the game board
ostream& operator << (ostream& out, const TicTacToeGame& game) {
    printGameBoardPieces(game.gameBoard, game.xColWidth, game.yRowHeight, out);
    return out;
}

