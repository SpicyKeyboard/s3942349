#include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

vector<vector<Cell>> loadedBoard = //this is an empty board that will be used as a non const base for other boards to be layered onto it
    {
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
    };

Board::Board() {
    
}

Board::~Board() {
    
}

void Board::load(int boardId) {
    if (boardId == 1) { // set board to board_1 and print
        loadedBoard = BOARD_1;
        // print loaded board
        for(int y = -1; y < DEFAULT_BOARD_DIMENSION; ++y) {
            for(int x = -1; x < DEFAULT_BOARD_DIMENSION; ++x) { //navigating through two dimensional vector array with two for loops
                if( y == -1 && x == -1) { //if it is the first part of both arrays, print "| |"
                    std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
                }
                else if (y == -1) { //if it is the first part of the first array, print the number out eg; "|1|"
                    std::cout << std::to_string(x) + LINE_OUTPUT;
                }
                else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                    std::cout << LINE_OUTPUT + std::to_string(y) + LINE_OUTPUT;
                }
                else { //if it is within the play area, check the user selected board for empty or blocked segments then apply them to loadedBoard and print
                    if (BOARD_1[y][x] == 0) { // empty
                        std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                        loadedBoard[y][x] = EMPTY;
                    }
                    else if (BOARD_1[y][x] == 1) { // blocked
                        std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                        loadedBoard[y][x] = BLOCKED;
                    }
                }
            }
        std::cout << std::endl;
        }
    }
    else if (boardId == 2) { // set board to board_2 and print
        loadedBoard = BOARD_2;
        // print loaded board
        for(int y = -1; y < DEFAULT_BOARD_DIMENSION; ++y) {
            for(int x = -1; x < DEFAULT_BOARD_DIMENSION; ++x) { //navigating through two dimensional vector array with two for loops
                if( y == -1 && x == -1) { //if it is the first part of both arrays, print "| |"
                    std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
                }
                else if (y == -1) { //if it is the first part of the first array, print the number out eg; "|1|"
                    std::cout << std::to_string(x) + LINE_OUTPUT;
                }
                else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                    std::cout << LINE_OUTPUT + std::to_string(y) + LINE_OUTPUT;
                }
                else { //if it is within the play area, check the user selected board for empty or blocked segments then apply them to loadedBoard and print
                    if (BOARD_2[y][x] == 0) { // empty
                        std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                        loadedBoard[y][x] = EMPTY;
                    }
                    else if (BOARD_2[y][x] == 1) { // blocked
                        std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                        loadedBoard[y][x] = BLOCKED;
                    }
                }
            }
        std::cout << std::endl;
        }
    }
    else if (boardId == 0) { //empty board print called at the start of loadBoard() function to show an empty board
        // print loaded board
        for(int y = -1; y < DEFAULT_BOARD_DIMENSION; ++y) {
            for(int x = -1; x < DEFAULT_BOARD_DIMENSION; ++x) { //navigating through two dimensional vector array with two for loops
                if( y == -1 && x == -1) { //if it is the first part of both arrays, print "| |"
                    std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
                }
                else if (y == -1) { //if it is the first part of the first array, print the number out eg; "|1|"
                    std::cout << std::to_string(x) + LINE_OUTPUT;
                }
                else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                    std::cout << LINE_OUTPUT + std::to_string(y) + LINE_OUTPUT;
                }
                else { //as this board will be empty, simply print all empty cells
                    std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                }
            }
        std::cout << std::endl;
        }
    }
    else { // not any of the specified boards, print error message
        Helper::printInvalidInput();
    }
}

bool Board::placePlayer(Position position) { // note that there are two return types as the header (board.h) explicitly says to use both true and false return statements in this function

    // use position value to check for empty space in loaded board and, if empty, update to player cell
    if (loadedBoard[position.y][position.x] == EMPTY) {
        loadedBoard[position.y][position.x] = PLAYER;
        return true; //returns true when position is set to player
    }
    else {
        Helper::printInvalidInput();
        return false; //returns false if the position is blocked
    }
}

PlayerMove Board::movePlayerForward(Player* player) {
    PlayerMove playerMove = OUTSIDE_BOUNDS; //setting the deafult return value to be OUTSIDE_BOUNDS

    Position currentPosition = player->position; //retreiving current position and splitting it into x and y variables
    int currentPositionX = currentPosition.x;
    int currentPositionY = currentPosition.y;

        /*
        all if/else if statements here will check if the *next* move will put them in out of bounds, 
        due to the order of operations in how the code is structured, the less than and greater than (<,>) signs along with some board pos manipulation is required to find this pos/dir
        */
        //check for out of bounds before seg faults can occur
        if (currentPositionX < 1 && player->direction == NORTH) { //position is invalid
            playerMove = OUTSIDE_BOUNDS;
        }
        else if (currentPositionY < 1 && player->direction == WEST) {
            playerMove = OUTSIDE_BOUNDS;
        }
        else if (currentPositionX > DEFAULT_BOARD_DIMENSION-2 && player->direction == SOUTH)
        {
            playerMove = OUTSIDE_BOUNDS;
        }
        else if (currentPositionY > DEFAULT_BOARD_DIMENSION-2 && player->direction == EAST) {
            playerMove = OUTSIDE_BOUNDS;
        }
        else { // position is valid
            Position nextForwardPosition = player->getNextForwardPosition(); //call for the forward position object then save the forward position to variables
            int nextForwardPosX = nextForwardPosition.x;
            int nextForwardPosY = nextForwardPosition.y;
            if(loadedBoard[nextForwardPosX][nextForwardPosY] == EMPTY) { //empty check
                loadedBoard[currentPositionX][currentPositionY] = EMPTY; // if the position is empty, update current pos to empty and forward pos to player
                loadedBoard[nextForwardPosX][nextForwardPosY] = PLAYER;
                playerMove = PLAYER_MOVED; //set return value to PLAYER_MOVED
                player->updatePosition(nextForwardPosition); //update postion to new position
            }
            else if(loadedBoard[nextForwardPosX][nextForwardPosY] == BLOCKED) { //blocked check
                playerMove = CELL_BLOCKED; //if the forward position is a blocked cell, dont move player and set return value to CELL_BLOCKED
            }
        }
    //will return outside_bounds by default
    return playerMove;
}

void Board::display(Player* player) {
    for(int y = -1; y < DEFAULT_BOARD_DIMENSION; ++y) {
            for(int x = -1; x < DEFAULT_BOARD_DIMENSION; ++x) { //navigating through two dimensional vector array with two for loops
                if( y == -1 && x == -1) { //if it is the first part of both arrays, print "| |"
                    std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
                }
                else if (y == -1) { //if it is the first part of the first array, print the number out eg; "|1|"
                    std::cout << std::to_string(x) + LINE_OUTPUT;
                }
                else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                    std::cout << LINE_OUTPUT + std::to_string(y) + LINE_OUTPUT;
                }
                else { //if it is within the play area, check the user selected board for empty, blocked or player segment/s then apply them to loadedBoard and print
                    if (loadedBoard[y][x] == EMPTY) { // empty
                        std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                        loadedBoard[y][x] = EMPTY;
                    }
                    else if (loadedBoard[y][x] == BLOCKED) { // blocked
                        std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                        loadedBoard[y][x] = BLOCKED;
                    }
                    else if (loadedBoard[y][x] == PLAYER) { // player
                        player->displayDirection();
                        std::cout << LINE_OUTPUT;
                    }
                }
            }
        std::cout << std::endl;
        }
}
