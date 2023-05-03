#include <iostream>
#include <vector>
#include "ttt_functions.hpp"
#include <stdlib.h>


int main(){

    // A vector that will hold vectors that contain characters
    std::vector< std::vector<char> > ttt_board = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};

    // Write code to display the board
    display_board(ttt_board);

    // Initial Game State
    std::string game_state = "Playing";
    int current_player = 0;
    char current_player_letter;
    int turns_played = 1;

    while (game_state == "Playing"){
        /* 
        Setting the Current Player & Current Player Letter Variables
        Even number = Player 1's turn, Odd number = Player 2's turn
        */
        turns_played % 2 == 0 ? current_player = 2 : current_player = 1;
        current_player == 1 ? current_player_letter = 'X' : current_player_letter = 'O';

        std::cout << "\nCurrent Player: Player #" << current_player << " (" << current_player_letter << ")\n";

        bool turn_played = false;
        while (!turn_played){

            // Taking the raw input to make sure the user is entering an integer between 1 and 9
            std::string raw_user_input;
            bool is_valid_input = false;
            while (!is_valid_input){
                std::cout << "Enter a spot! (1-9): ";
                std::cin >> raw_user_input;
                std::cout << "\n";

                if (isNumber(raw_user_input)){
                    is_valid_input = true;
                } else {
                    std::cout << "Sorry! That is not a valid spot option!\n";
                }
            }

            // Converting the proven numeric string into a intger
            int user_input = std::stoi(raw_user_input);
            
            // check to see if that specific spot on the board has been taken or not.
            char player_sign;
            if (1 <= user_input && user_input <= 3){
                // reformatting user_input to fit a 0, 1, 2 index format
                user_input -= 1;

                if (ttt_board[0][user_input] == '_'){
                    current_player == 1 ? ttt_board[0][user_input] = 'X' : ttt_board[0][user_input] = 'O';
                    turn_played = true;
                } else {
                    std::cout << "Sorry! There is already a marking placed there!\n";
                }
            } else if (4 <= user_input && user_input <= 6){
                // reformatting user_input to fit a 0, 1, 2 index format
                user_input -= 4;

                if (ttt_board[1][user_input] == '_'){

                    current_player == 1 ? ttt_board[1][user_input] = 'X' : ttt_board[1][user_input] = 'O';
                    turn_played = true;
                } else {
                    std::cout << "Sorry! There is already a marking placed there!\n";
                }
            } else if (7 <= user_input && user_input <= 9){
                // reformatting user_input to fit a 0, 1, 2 index format
                user_input -= 7;

                if (ttt_board[2][user_input] == '_'){
                    current_player == 1 ? ttt_board[2][user_input] = 'X' : ttt_board[2][user_input] = 'O';
                    turn_played = true;
                } else {
                    std::cout << "Sorry! There is already a marking placed there!\n";
                }
            } else {
                std::cout << "Sorry! That is not a valid spot option!\n";
            }

        };

        display_board(ttt_board);

        // checking to see if the game has been won
        std::vector<std::string> game_status_data = game_status(ttt_board);
        game_state = game_status_data[0];

        if (game_status_data[0] == "Done"){
            std::cout << game_status_data[1] << "\n";
        }

        // Switch over to the next player
        turns_played++;
    }
}
