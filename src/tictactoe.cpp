
#include "../includes/tictactoe.h"

TicTacToe::TicTacToe() {
    // Initialize empty board with ' '
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < 3; ++j) {
            board_[i][j] = ' ';
        }
    }
}

// Standard board print that includes visual of the current board
void TicTacToe::PrintBoard() const {
    std::cout << "━━━━━━━━━━━━━" << std::endl;

    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned j = 0; j < 3; ++j) {
            if (j == 0)
                std::cout << "┃";
            std::cout << ' ' << board_[i][j] << ' ';
            std::cout << "┃";
        }
        std::cout << std::endl;
        std::cout << "━━━━━━━━━━━━━" << std::endl;
    }
}



void TicTacToe::UseTurn(char move) {                            // TODO
    /*
        Check which position is the desired move
        to make sure it is available
            - if not available we throw 
    */
    switch (move)
    {
    case '1':
        if (board_[0][0] != ' ') throw std::invalid_argument("");
        board_[0][0] = NextPlayerCharacter();
        break;
    
    default:
        break;
    }
}


char TicTacToe::NextPlayerCharacter() {
    if (next_player_) {
        // Player 2 case
        next_player_ = false;       // Switch
        return 'O';
    }
    // PLayer 1 case
    next_player_ = true;            // Switch
    return 'X';  
}
