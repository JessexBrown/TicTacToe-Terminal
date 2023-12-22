
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


class TicTacToe {
    public:
        // Default Constructor
        TicTacToe();

        // Print current state of the board
        void PrintBoard() const;

        // Printing error message function (Invalid move / Already occupied space)
        void PrintErrorMessage(const std::string& msg_type);

        // Advances the board for the next recorded player (returns false if space is already occupied)
        bool UseTurn(const std::string& move, char curr_player_char);

        // Get next player's character for board insertion and advances the next_player_ variable
        char NextPlayerCharacter();

        // Check if game has finihsed and is still valid
        bool GameValid() const;

        // Retrieve the valid spaces that can still be played by the current user
        std::vector<std::string> GetValidMoves() const;



    private:

        /*
            Tic-Tac-Toe Board Dimensions:
                width: 3    
                height: 3
        */

        /*
            Store the board as a 2d array of characters

            Character list:
                - Whitespace (' ') - ASCII 32: Empty Space
                - Player 1   ('X') - ASCII 88: Space occupied by Player 1
                - Player 2   ('O') - ASCII 79: Space occupied by Player 2 
        */
        char board_[3][3];


        /*
            Flag used to signify if the game is still ongoing or valid to
            be continued playing
            
            Invalid states:
                - Either player has won
                - Stalemate has occurred (Board is filled without winner)
        */
        bool valid_game_flag_ = true;


        /*
            Player states:
                - false (0) -> Player 1's turn
                - true  (1) -> Player 2's turn
        */
        bool next_player_ = false;



        /*
            Maps valid moves to the corresponding coordinates (stored in pair {row, col}) in the board_ 2d array
            
            ━━━━━━━━━━━━━
            ┃ 1 ┃ 2 ┃ 3 ┃
            ━━━━━━━━━━━━━
            ┃ 4 ┃ 5 ┃ 6 ┃
            ━━━━━━━━━━━━━
            ┃ 7 ┃ 8 ┃ 9 ┃
            ━━━━━━━━━━━━━
            Ex:
                "1" maps to row 0, col 0
                "6" maps to row 1, col 2
        
        */
       std::map<std::string, std::pair<unsigned int, unsigned int>> move_map_;


       /*
            ━━━━━━━━━━━━━
            ┃ 1 ┃ 2 ┃ 3 ┃
            ━━━━━━━━━━━━━
            ┃ 4 ┃ 5 ┃ 6 ┃
            ━━━━━━━━━━━━━
            ┃ 7 ┃ 8 ┃ 9 ┃
            ━━━━━━━━━━━━━

            Starts with all values [1,9] and removes respective spaces from vector when
            players move there
       
       */
       std::vector<std::string> valid_moves_;
};