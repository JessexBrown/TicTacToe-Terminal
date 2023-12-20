
#pragma once
#include <iostream>
#include <stdexcept>


class TicTacToe {
    public:
        // Default Constructor
        TicTacToe();

        // Print current state of the board
        void PrintBoard() const;

        // Advances the board for the next recorded player
        void UseTurn(char move);

        // Get next player's character for board insertion
        char NextPlayerCharacter();



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
};