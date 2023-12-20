// your code here
#include "../includes/tictactoe.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main() {

    TicTacToe test_game;
    // Make function for printing out instructions 
    // test_game.PrintBoard();

    const std::vector<std::string> kValidMoves = {"1", "2", "3",
                                                "4", "5", "6",
                                                "7", "8", "9"};

    // Game loop 
    while (test_game.GameValid()) {
        test_game.PrintBoard();


        // Get current player 
        char curr_player_char = test_game.NextPlayerCharacter(); 
        std::string curr_player_name = (curr_player_char == 'X') ? "Player 1" : "Player 2";


        /*
            Recieve player input about the next turn
                - Check for the valid positions [1,9]
        */ 
        std::cout << YELLOW << "Please enter one of the valid move positions: 1,2,3,4,5,6,7,8,9" << RESET << std::endl;

        // Prompt input from current player
        std::string player_move_input;
        std::cout << curr_player_name << "'s move: "; 
        std::cin >> player_move_input;

        // Valid character input check (Enter if bad input and leave if Good input is recieved)
        while (std::find(kValidMoves.begin(), kValidMoves.end(), player_move_input) == kValidMoves.end()) {
            std::cout << RED << "------INVALID MOVE RECIEVED------" << RESET << std::endl;
            std::cout << YELLOW << "Please enter one of the valid move positions: 1,2,3,4,5,6,7,8,9" << RESET << std::endl;

            // Reprompt player 
            std::cout << curr_player_name << "'s move: "; 
            std::cin >> player_move_input;

        }

        // Initiate a turn with gathered info 
        while (!test_game.UseTurn(player_move_input, curr_player_char)) {
            std::cout << RED << "------SPACE ALREADY OCCUPIED------" << RESET << std::endl;
            std::cout << YELLOW << "Please enter one of the valid move positions: 1,2,3,4,5,6,7,8,9" << RESET << std::endl;

            // Reprompt player 
            std::cout << curr_player_name << "'s move: "; 
            std::cin >> player_move_input;
        }




        std::cout << "Recorded input from player: " << player_move_input << std::endl; 


    }

    return 0;
}

