# tictactoe-game

# Program Design and Implementation:
- Developed a C++ program with a game class.
- The game class encapsulates game data within a class.
- Prompted for and received user input for game moves.
- Checked the validity of each input move and updated the game state.
- Detected three conditions: successful game completion, no further valid moves possible, and remaining valid moves.

# Game Class overview:
The game board is 5x5 with coordinates ranging from 0,0 to 4,4.
Represented game pieces as 'X' and 'O'.
Maintained nine inner empty squares for user input and kept the outer squares empty.
Defined an insertion operator to display the game board.
Implemented a done() method to check for winning conditions.
Implemented a draw() method to check for game draws.
Implemented a prompt() method for user input, handling invalid input and 'quit' options.
Created a turn() method to manage player turns, validate moves, and update the game board.
Defined a play() method that loops through turns and game completion conditions.

# Main Function overview:
Checked for valid command-line arguments, specifically "TicTacToe."
Created an object of the Tic-Tac-Toe game class.
Called the play() method and used its result as the program's return value.
Returned unique non-zero values for different failure cases.

# Testing overview:
Tested the program with well-formed and badly formed command lines and user inputs.
Documented test cases, program behavior, and correctness in the ReadMe.txt file.
