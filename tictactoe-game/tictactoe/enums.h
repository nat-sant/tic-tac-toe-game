#pragma once

// Enumeration for indices used in command line arguments.
enum indices {
    programName = 0,   // Index for the program name.
    fileName = 1,      // Index for the file name (argv).
    argumentCount = 2  // Index for the argument count (usually argc).
};

// Enumeration for exit codes to represent various program outcomes.
enum exitCodes {
    success = 0,               // Successful program execution.
    file_open_fail = 1,        // Failed to open a file.
    wrong_args = 2,            // Invalid command line arguments.
    read_line_fail = 3,        // Failed to read a line from input.
    extraction_fail = 4,       // Failed to extract data from input.
    piece_read_success = 0,    // Successfully read a game piece.
    piece_read_fail = 6,       // Failed to read a game piece.
    game_board_print_success = 0,  // Successfully printed the game board.
    game_board_print_fail = 7,     // Failed to print the game board.
    dimension_match_fail = 8,     // Mismatch in game board dimensions.
    read_dimensions_success = 0,   // Successfully read game board dimensions.
    game_win = 0,                  // Game won.
    game_draw = 9,                 // Game resulted in a draw.
    game_quit = 10,                // User quit the game.
    prompt_enter_success = 0,      // Successfully entered a prompt.
    prompt_enter_fail = 11         // Failed to enter a prompt.
};
