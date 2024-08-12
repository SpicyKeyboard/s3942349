#include "game.h"

Game::Game() {
    Board* board = new Board; //creates new board and player objects and saves them to game classes private variable in the heap
    this->board = board;
    Player* player = new Player;
    this->player = player;
}

Game::~Game() {

}

void Game::start() {
    std::cout << "You can use the following commands to play the game:\n" << std::endl; //prints instructions to the user
    std::cout << "generate <d><p>" << std::endl;
    std::cout << "    d: the dimension of the game board to be generated (between 10 and 20)" << std::endl;
    std::cout << "    p: the probability of the blocks on the board to be generated randomly (between 0 and 0.8)" << std::endl;
    std::cout << "init <x>,<y>,<direction>" << std::endl;
    std::cout << "    x: horizontal position of the vacuum cleaner in the room (between 0 & 9)" << std::endl;
    std::cout << "    y: vertical position of the vacuum cleaner in the room (between 0 & 9)" << std::endl;
    std::cout << "    direction: direction of the vacuum cleaner's movement (north, east, south, west)" << std::endl;
    std::cout << "forward (or f)" << std::endl;
    std::cout << "turn_left (or l)" << std::endl;
    std::cout << "turn_right (or r)" << std::endl;
    std::cout << "quit" << std::endl;
    std::cout<< std::endl;

    loadBoard(); //calls load board to begin program logic and user input
    }

bool Game::loadBoard() {
    board->load(0, 0.0); //displays an empty board
    std::string userInput;
    std::vector<std::string> userVector;
    int boardSize;
    float blockAmount;
    bool quitUserInput = false;
    bool boardUserInput = false;

    while(!quitUserInput && !boardUserInput && std::cin.good()) { //while the user has not quit, successfully loaded a board or managed to set negative flags on the cin stream

        std::cout << std::endl << "At this stage of the program, only two commands are acceptable:" << std::endl; //prints instructions
        std::cout << "generate <d><p>" << std::endl;
        std::cout << "quit" << std::endl;
        std::cout << std::endl << "Please enter your choice: \n";

        userInput = Helper::readInput(); //read input

        if(!std::cin.good()) { //if the input is raising negative flags leave loop and return negative
            std::cout << "Something went wrong with the stream (probably ^D), exiting loop to prevent infinite loop.";
        }
        else { //validate user input is either a quit or generate command
            Helper::splitString(userInput, userVector, " "); // using helper function splitString to split the userInput string
            std::string firstWord = userVector[0];
            if(firstWord == COMMAND_GENERATE_RANDOM && userVector.size() > 1) { // generate
                std::string secondWord = userVector[1];
                Helper::splitString(secondWord, userVector, ",");
                if (userVector.size() > 2) {
                    Helper::printInvalidInput();
                }
                else {
                    if (Helper::isNumber(userVector[0]) && Helper::isNumber(userVector[1])) { //checking if both d/p are numbers
                        boardSize = stoi(userVector[0]);
                        blockAmount = stof(userVector[1]);
                        if (boardSize >= 10 && boardSize <=21) { //if boardSize is within size
                            if (blockAmount >=0 && blockAmount <= 0.9) { //if blockAmount is within range
                                board->load(boardSize, blockAmount);
                                boardUserInput = true; //set loop exit condition to true
                            }
                            else { // p are too large or small
                                Helper::printInvalidInput();
                            }
                        }
                        else { // d are too large or small
                            Helper::printInvalidInput();
                        }
                    }
                    else { //d/p are not numbers
                        Helper::printInvalidInput();
                    }
                }
            }
            else if(firstWord == COMMAND_QUIT) {
                quitUserInput = true; //set loop exit condition to true
            }
            else {
                Helper::printInvalidInput();
            }
            if (boardUserInput) { //if user selected a board, call function initializePlayer()
                initializePlayer();
            }
        }
    }  
    return false; //returns false
}

bool Game::loadBoard(int boardSize, float blockAmount) { // for changing boards after already selecting a board, this overload exists
    bool boardUserInput = false;

    while(!boardUserInput && std::cin.good()) {//while the user has not quit, successfully loaded a board or managed to set negative flags on the cin stream
        
        if(! std::cin.good()) { //if the input is raising negative flags leave loop and return negative
            std::cout << "Something went wrong with the stream (probably ^D), exiting loop to prevent infinite loop.";
        }
        else {
            if (boardSize >= 10 && boardSize <=21) { //if boardSize is within size
                if (blockAmount >= 0 && blockAmount <= 0.9) { //if blockAmount is within range
                    board->load(boardSize, blockAmount);
                    boardUserInput = true; //set loop exit condition to true
                }
            }
            else {
                Helper::printInvalidInput();
                loadBoard();
            }
        }
        if (boardUserInput) { //if correct board was input, initializePlayer()
        initializePlayer();
        }
    }      
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer() {
    std::string userInput;
    bool quitUserInput = false;
    bool initUserInput = false;
    std::vector<std::string> userVector;
    int xPos;
    int yPos;
    std::string directionInput;


    while(!quitUserInput && !initUserInput && std::cin.good()) { //while user input is not quit, successful init or did not raise any negative flags for cin stream

        std::cout << std::endl << "At this stage of the program, only three commands are acceptable:" << std::endl; //print instructions
        std::cout << "generate <d><p>" << std::endl;
        std::cout << "init <x>,<y>,<direction>" << std::endl;
        std::cout << "quit" << std::endl;
        std::cout << std::endl << "Please enter your choice: \n";
        
        userInput = Helper::readInput(); //get user input

        if(!std::cin.good()) { //if user input raised negative flags in cin stream
            std::cout << "Something went wrong with the stream (probably ^D), exiting loop to prevent infinite loop.";
        }
        else {
            Helper::splitString(userInput, userVector, " "); //split user input into userVector
            std::string firstWord = userVector[0];

            if(firstWord == COMMAND_GENERATE_RANDOM && userVector.size() > 1) { // load
                std::string secondWord = userVector[1];
                Helper::splitString(secondWord, userVector, ",");
                int boardSize = stoi(userVector[0]);
                float blockAmount = stof(userVector[1]);
                initUserInput = true;
                loadBoard(boardSize, blockAmount); //run loadBoard() using the desired user input
            }
            else if(firstWord == COMMAND_INIT && userVector.size() > 1) { // init
                std::string secondWord = userVector[1];
                initUserInput = true;
                
                // error handling and further logic
                Helper::splitString(userInput.substr(5, userInput.size()), userVector, ","); // using helper function splitString to split the userInput string, except the "init " part, to store the x, y and direction variables
                if (userVector.size() == 3) { //if init command has enough varibles (3)
                    if (Helper::isNumber(userVector[0]) && Helper::isNumber(userVector[1])) { //if the first two variables are numbers
                        xPos = stoi(userVector[0]);
                        yPos = stoi(userVector[1]);
                        if (xPos < board->boardSize && yPos < board->boardSize) { // error handling for x and y to make sure that they are within bounds
                            directionInput = userVector[2];
                            if (directionInput == DIRECTION_NORTH || directionInput == DIRECTION_EAST || directionInput == DIRECTION_SOUTH || directionInput == DIRECTION_WEST) { // error handling direction, making sure that the direction is valid
                                // create position object and set position
                                player->position = Position(xPos, yPos); // set boundaries for board size, error handling
                                // set direction of player and pass to init player
                                if (directionInput == DIRECTION_NORTH) {
                                    // give variables to player class initPlayer
                                    player->initialisePlayer(&player->position);
                                }
                                else if (directionInput == DIRECTION_EAST) {
                                    // give variables to player class initPlayer
                                    player->initialisePlayer(&player->position);
                                }
                                else if (directionInput == DIRECTION_SOUTH) {
                                    // give variables to player class initPlayer
                                    player->initialisePlayer(&player->position);
                                }
                                else { //west
                                    // give variables to player class initPlayer
                                    player->initialisePlayer(&player->position);
                                }
                                // give player position to board class place player
                                if(board->placePlayer(player->position)) { //player placed succesfully
                                    player->moves = 0; //setting moves to zero for newly init player
                                    if (directionInput == DIRECTION_NORTH) { //below if/else if/else statemnt/s set player objects direction to the user input direction
                                        player->direction = NORTH;
                                    }
                                    else if (directionInput == DIRECTION_EAST) {
                                        player->direction = EAST;
                                    }
                                    else if (directionInput == DIRECTION_SOUTH) {
                                        player->direction = SOUTH;
                                    }
                                    else {
                                        player->direction = WEST;
                                    }
                                    play();
                                }
                                else { // player is not placed, run again
                                    initializePlayer();
                                }
                            }
                            else { //direction input was not valid, run again
                                Helper::printInvalidInput();
                                initializePlayer();
                            }
                        }
                        else { //x and or y were not in bounds, run again
                        Helper::printInvalidInput();
                        initializePlayer();
                        }
                    }
                    else { //one or both of the first two variables were not numbers, run again
                        Helper::printInvalidInput();
                        initializePlayer();
                    } 
                }
                else { //input did not have enough variables, run again
                    Helper::printInvalidInput();
                    initializePlayer();
                }
            }
            else if(firstWord == COMMAND_QUIT) { //user input was quit
                quitUserInput = true;
            }
            else { //user input is invalid, run again
                Helper::printInvalidInput();
                initializePlayer();
            }
        }
    }
    return false; //returns false
}

void Game::play() {
    bool quitUserInput = false;

    while(!quitUserInput && std::cin.good()) {//while the user has not quit or managed to set negative flags on the cin stream

        board->display(player); //display the board with the player cell too

        std::cout << "\nAt this stage of the program, only four commands are acceptable:" << std::endl; //print instructions
        std::cout << "forward (or f)" << std::endl;
        std::cout << "turn_left (or l)" << std::endl;
        std::cout << "turn_right (or r)" << std::endl;
        std::cout << "quit\n" << std::endl;
        std::cout << "Please enter your choice:\n" << std::endl;

        std::string userInput = Helper::readInput(); //get user input

        if(!std::cin.good()) {//makes sure the user has not managed to set negative flags on the cin stream
            std::cout << "Something went wrong with the stream (probably ^D), exiting loop to prevent infinite loop.";
        }
        else {
            if (userInput == COMMAND_FORWARD || userInput == COMMAND_FORWARD_SHORTCUT) { //if user input is forward
                PlayerMove moveResult = board->movePlayerForward(player);
                if (moveResult == CELL_BLOCKED) { //check if the movement is toward a blocked cell, if it is print error
                    std::cout << "Error: Unable to move - cell is blocked.\n\n";
                }
                else if(moveResult == OUTSIDE_BOUNDS) { //check if the movement is toward a cell that is out of bounds, if it is print error
                    std::cout << "Error: Unable to move - cell is out of bounds.\n\n";
                }
            }
            else if (userInput == COMMAND_TURN_LEFT || userInput == COMMAND_TURN_LEFT_SHORTCUT) { //if user input is left
                player->turnDirection(TURN_LEFT);
            }
            else if (userInput == COMMAND_TURN_RIGHT || userInput == COMMAND_TURN_RIGHT_SHORTCUT) { //if user input is right
                player->turnDirection(TURN_RIGHT);
            }
            else if (userInput == COMMAND_QUIT) { //if user input is quit
                quitUserInput = true; //set loop exit condition to true
            }
            else { //input was invalid
                Helper::printInvalidInput();
            }
        }
    }
    std::cout << "\nTotal Player Moves: " << player->moves << std::endl << std::endl; //prints out total successfull moves for the game on exit

    delete player; //delete created player object
    delete board; //delete created board object
}