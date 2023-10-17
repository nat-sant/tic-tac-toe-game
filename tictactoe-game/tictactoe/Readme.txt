---
Paola Santiago
Lily Spiniolas
---

Errors + Warnings:
------------------

1. Mismatched Type: Resolved by changing the type of a value to unsigned int, where unsigned ints were being compared against ints.

2. "*this": Needed to use a pointer to "this" instead of just "this" when printing out the game board; otherwise, nothing would print out.

3. Error LNK1168: Cannot open C:\Users\admin\Desktop\Desktop2\CSE332\Lab 3\lab3-pk\Debug\lab3-pk.exe for writing. This error appeared whenever I tried to build my solution while the program was still running in the command window. It was resolved by using Ctrl+C to end the program in cmd, then re-building.

4. Vector Out of Bounds Warning in Command Line Prompt: Resolved by considering ASCII characters and using an istringstream to convert input values into properly formatted integers.

Cases Ran:
-----------

1. Input Out of Bounds Coordinate Set, such as 0,0 or 4,1: Would reprompt the user to enter "quit" or a coordinate.

2. Input Random Unformatted Numbers, such as 1111 or 0: Would reprompt the user to enter "quit" or a coordinate.

3. Input Coordinates for One Player That Would Create a Row Win, e.g., 1,1 2,1 3,1: Would print out the board, history of moves, and then the winning player.

4. Input Coordinates for One Player That Would Create a Column Win, e.g., 1,1 1,2 1,3: Would print out the board, history of moves, and then the winning player.

5. Input Coordinates for One Player That Would Create a Left-to-Right Diagonal Win, e.g., 1,1 2,2 3,3: Would print out the board, history of moves, and then the winning player.

6. Input Coordinates for One Player That Would Create a Right-to-Left Diagonal Win, e.g., 1,3 2,2 3,1: Would print out the board, history of moves, and then the winning player.

7. Input "quit": Would print out the number of turns played and a message that the user quit. Prints zero if you quit immediately; otherwise, prints a non-zero number of turns.

8. Input Coordinates That Filled the Entire Board Without a Win: Using x:1-3 and y:1-3 to create combinations that filled the entire board. Would print out the final board completely filled, the number of turns played, and a message that the game ended in a draw with no winning moves remaining.
