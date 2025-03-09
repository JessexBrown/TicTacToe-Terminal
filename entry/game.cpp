#include "../includes/tictactoe.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>


// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main() {

    TicTacToe test_game; 
    test_game.PrintInstructions();

    std::cout << GREEN << "Are you ready to play? (Y/N): " << RESET;
    char game_start_char;
    std::cin >> game_start_char;
    std::cout << std::endl;

    if (tolower(game_start_char) != 'y')
        return 0;

    const std::vector<std::string> kValidMoves = {"1", "2", "3",
                                                "4", "5", "6",
                                                "7", "8", "9"};

    // Game loop //
    while (test_game.GameValid()) {
        test_game.PrintBoard();


        // Get current player info
        char curr_player_char = test_game.NextPlayerCharacter(); 
        std::string curr_player_name = (curr_player_char == 'X') ? "Player 1" : "Player 2";

        // Get valid move info
        std::vector<std::string> valid_moves_vect = test_game.GetValidMoves();
        std::string valid_move_string;
        for (const std::string& valid_move : valid_moves_vect) {
            // Add element to string and comma until last element
            valid_move_string += valid_move;
            if (valid_move == valid_moves_vect[valid_moves_vect.size() - 1])
                break;
            valid_move_string += ",";
        }


        /*
            Recieve player input about the next turn
                - Check for the valid positions [1,9]
        */ 
        std::cout << YELLOW << "Please enter one of the valid move positions: " << valid_move_string << RESET << std::endl;

        // Prompt input from current player
        std::string player_move_input;
        std::cout << curr_player_name << "'s move: "; 
        std::cin >> player_move_input;

        // Valid character input check (Enter if bad input and leave if Good input is recieved)
        while (std::find(kValidMoves.begin(), kValidMoves.end(), player_move_input) == kValidMoves.end()) {
            test_game.PrintErrorMessage("INVALID");
            std::cout << YELLOW << "Please enter one of the valid move positions: " << valid_move_string << RESET << std::endl;

            // Reprompt player 
            std::cout << curr_player_name << "'s move: "; 
            std::cin >> player_move_input;

        }

        // Initiate a turn with gathered info 
        while (!test_game.UseTurn(player_move_input, curr_player_char)) {
            std::cout << YELLOW << "Please enter one of the valid move positions: " << valid_move_string << RESET << std::endl;

            // Reprompt player 
            std::cout << curr_player_name << "'s move: "; 
            std::cin >> player_move_input;
        }




        std::cout << "Recorded input from player: " << player_move_input << std::endl; 


    }

    // Display final board
    test_game.PrintBoard();

    // Display winning moves
    test_game.PrintWinningMoves();

    // Notify termination of game due to win 
    std::cout << GREEN << "Your game has finished" << RESET << std::endl;



    return 0;
}

