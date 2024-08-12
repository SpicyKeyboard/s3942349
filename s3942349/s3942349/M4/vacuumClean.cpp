#include "game.h"
#include "helper.h"

void showStudentInformation(std::string name, std::string id, std::string email) {
    std::cout << name << " " << id << " " << email << std::endl; //prints out three variables speratped by space
}

int main() {   
    std::string userInputMenu;

    while(userInputMenu != "3" && std::cin.good()) { // loops while input is not three (the quit command in this case) and while the cin stream has no negative flags

        std::cout << "Welcome to Vacuum Cleaning Game!" << std::endl; //prints out instructions to the user
        std::cout << "--------------------" << std::endl;
        std::cout << "1. Play Game" << std::endl;
        std::cout << "2. Show student information" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter your choice: ";

        userInputMenu = Helper::readInput(); //read user input
        if (Helper::isNumber(userInputMenu)) {
            if(userInputMenu == "1") { // play game
            Game game;
            game.start();
            }
            else if(userInputMenu == "2") { // student info
                showStudentInformation("Heath Yates", "S3942349", "S3942349@student.rmit.edu.au");
                std::cout << std::endl;
            }
            else if(userInputMenu != "3") { //invalid input
                Helper::printInvalidInput();
            }
        }
        else if(!std::cin.good()) { //prevent infintite loops via eof by terminating
            std::cout << "Something went wrong with the stream (probably ^D), exiting loop to prevent infinite loop.";
        }
        else { //input was not a number, invalid input
            Helper::printInvalidInput();
        }
        std::cout << std::endl;
    }
    // if three was input, quit
    return EXIT_SUCCESS;
}

// g++ -Wall -Werror -std=c++14 -O -o assign1 board.cpp vacuumClean.cpp game.cpp helper.cpp player.cpp
// ./assign1

// for each while loop, handle end of file character (5 loops) {kinda handled, just poorly}
// sometimes during init, if you init at 0,0 the player will delete the first row