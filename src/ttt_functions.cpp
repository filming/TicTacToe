#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

void display_board(std::vector<std::vector<char>> ttt_board){
    std::cout << "  " << ttt_board[0][0] << " | " << ttt_board[0][1] << " | " << ttt_board[0][2] << "  \n";
    std::cout << "-------------\n";
    std::cout << "  " << ttt_board[1][0] << " | " << ttt_board[1][1] << " | " << ttt_board[1][2] << "  \n";
    std::cout << "-------------\n";
    std::cout << "  " << ttt_board[2][0] << " | " << ttt_board[2][1] << " | " << ttt_board[2][2] << "  \n";
}

std::vector<std::string> game_status(std::vector<std::vector<char>> ttt_board){
    std::vector<std::string> game_status(2);

    // check top row
    if (ttt_board[0][0] == ttt_board[0][1] && ttt_board[0][1] == ttt_board[0][2] && ttt_board[0][2] == ttt_board[0][0] && ttt_board[0][0] != '_'){
        game_status[0] = "Done";
        ttt_board[0][0] == 'X' ? game_status[1] = "Player 1 Has Won" : game_status[1] = "Player 2 Has Won";
    }
    // check middle row
    else if (ttt_board[1][0] == ttt_board[1][1] && ttt_board[1][1] == ttt_board[1][2] && ttt_board[1][2] == ttt_board[1][0] && ttt_board[1][0] != '_'){
        game_status[0] = "Done";
        ttt_board[1][0] == 'X' ? game_status[1] = "Player 1 Has Won" : game_status[1] = "Player 2 Has Won";
    }
    // check bottom row
    else if (ttt_board[2][0] == ttt_board[2][1] && ttt_board[2][1] == ttt_board[2][2] && ttt_board[2][2] == ttt_board[2][0] && ttt_board[2][0] != '_'){
        game_status[0] = "Done";
        ttt_board[2][0] == 'X' ? game_status[1] = "Player 1 Has Won" : game_status[1] = "Player 2 Has Won";
    }
    // check left column
    else if (ttt_board[0][0] == ttt_board[1][0] && ttt_board[1][0] == ttt_board[2][0] && ttt_board[2][0] == ttt_board[0][0] && ttt_board[0][0] != '_'){
        game_status[0] = "Done";
        ttt_board[0][0] == 'X' ? game_status[1] = "Player 1 Has Won" : game_status[1] = "Player 2 Has Won";
    }
    // check middle column
    else if (ttt_board[0][1] == ttt_board[1][1] && ttt_board[1][1] == ttt_board[2][1] && ttt_board[2][1] == ttt_board[0][1] && ttt_board[0][1] != '_'){   
        game_status[0] = "Done";
        ttt_board[0][1] == 'X' ? game_status[1] = "Player 1 Has Won" : game_status[1] = "Player 2 Has Won";
    }
    // check right column
    else if (ttt_board[0][2] == ttt_board[1][2] && ttt_board[1][2] == ttt_board[2][2] && ttt_board[2][2] == ttt_board[0][2] && ttt_board[0][2] != '_'){   
        game_status[0] = "Done";
        ttt_board[0][2] == 'X' ? game_status[1] = "Player 1 Has Won" : game_status[1] = "Player 2 Has Won";
    } 
    // if nobody has won the game yet
    else {
        // check for draw
        std::string spots_str = "";
        for (std::vector<char> vec1 : ttt_board){
            for (char letter : vec1){
                spots_str += letter;
            }
        }

        // if after joining all the spots in the vectors and there is no '_' means all the spots are filled and there is no winner
        if (spots_str.find('_') != std::string::npos){
            game_status[0] = "Playing";
            game_status[1] = "Nobody Has Won Yet";
        } else {
            game_status[0] = "Done";
            game_status[1] = "The Game Has Ended In A Draw!";
        }
    }

    return game_status;
}

bool isNumber(const std::string& str){
    for (char const &c : str) {
        if (std::isdigit(c) == 0){
            return false;
        } 
    }
    return true;
}
