#include "board.h"

using std::vector;

//vector<vector<Cell>> loadedBoard;
vector<vector<Cell>> loadedBoard = //this is an empty board that will be used as a non const base for other boards to be layered onto it
    {
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
    }; //no i dont like this solution either

Board::Board() {
}

Board::~Board() {
    
}

void Board::load(int boardSize, float blockAmount) {
        this->boardSize = boardSize;
        //create empty board with a min of 10x10 dimensions
        std::vector<Cell> x(10);
        std::vector<std::vector<Cell>> displayBoard(10,x);
        if(boardSize < 10) { //less than 10, so create board of 10x10 for display purpose only
            for (int y = -1; y < DEFAULT_BOARD_DIMENSION; ++y) {
                for (int x = -1; x < DEFAULT_BOARD_DIMENSION; ++x) { //navigating through two dimensional vector array with two for loops
                    if ( y == -1 && x == -1) { //if it is the first part of both arrays, print "| |"
                        std::cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
                    }
                    else if (y == -1) { //if it is the first part of the first array, print the number out eg; "|1|"
                        std::cout << std::to_string(x) + LINE_OUTPUT;
                    }
                    else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                        std::cout << LINE_OUTPUT + std::to_string(y) + LINE_OUTPUT;
                    }
                    else { //if it is within the play area, check the user selected board for empty or blocked segments then apply them to loadedBoard and print
                        std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                    }
                }
                std::cout << std::endl;
            }
        }
        else { //create empty board of given dimensions
            int blockedCellsAmount = (boardSize*boardSize) * blockAmount; //select which cells will be blocked
            std::vector<std::string> blockedCellPositions(blockedCellsAmount);
            int i = 0;
            bool cellBlocked = false;
            while (i != blockedCellsAmount) {
                std::string xValue = std::to_string(rand() % boardSize + 1); //getting two rand ints of desired value
                std::string yValue = std::to_string(rand() % boardSize);
                std::string positionString = xValue + "," + yValue;
                if (i == 0) {
                    blockedCellPositions[i] = positionString;
                    i++;
                }
                else {
                    for (unsigned int j = 0; j == blockedCellPositions.size(); j++) {
                        std::cout << blockedCellPositions[j];
                        if (blockedCellPositions[j] == positionString) {
                            cellBlocked = true;
                        }
                    }
                    if(!cellBlocked) {
                        blockedCellPositions[i] = positionString;
                        i++;
                    }
                }
                
            }


            for (int y = -2; y < boardSize; ++y) {
                for (int x = -1; x < boardSize; ++x) { //navigating through two dimensional vector array with two for loops
                    if ( y == -2 && x == -1) { //if it is the first part of both arrays, print "   "
                        std::cout << EMPTY_OUTPUT << EMPTY_OUTPUT << EMPTY_OUTPUT;
                        
                    }
                    else if (y == -1 && x == -1) { //second blank area, print "   "
                        std::cout << EMPTY_OUTPUT << EMPTY_OUTPUT << EMPTY_OUTPUT;
                    }
                    else if (y == -2) { //if it is the first part of the first array, print the number out eg; "|1|"
                        if (x < 10) {
                            std::cout << "0" << LINE_OUTPUT;
                        }
                        else {
                            std::cout << "1" << LINE_OUTPUT;
                        }
                    }
                    else if (y == -1) { //second line, second digit print
                        std::cout << x % 10 << LINE_OUTPUT;
                    }
                    else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                        if (y < 10) { // y less than 10, so add zero
                            std::cout << "0" << std::to_string(y) + LINE_OUTPUT;
                        }
                        else {
                            std::cout << std::to_string(y) + LINE_OUTPUT;
                        }
                    }
                    else { //if it is within the play area, check for if the position is blocked or not
                        cellBlocked = false;
                        unsigned int k = 0;
                        while (k != blockedCellPositions.size()) {
                            if (blockedCellPositions[k] == std::to_string(x+1) + "," + std::to_string(y)) {
                                cellBlocked = true;
                            }
                            k++;
                        }
                            
                        // }
                        if (cellBlocked) {
                            std::cout << BLOCKED_OUTPUT << LINE_OUTPUT;
                            loadedBoard[y][x] = BLOCKED;
                        }
                        else {
                            std::cout << EMPTY_OUTPUT << LINE_OUTPUT;
                            loadedBoard[y][x] = EMPTY;
                        }
                        
                    }
                }
                std::cout << std::endl;
            }
        }
}

bool Board::placePlayer(Position position) { // note that there are two return types as the header (board.h) explicitly says to use both true and false return statements in this function

    // use position value to check for empty space in loaded board and, if empty, update to player cell
    if (loadedBoard[position.x][position.y] == EMPTY) {
        loadedBoard[position.x][position.y] = PLAYER;
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
        if (currentPositionX < 2 && player->direction == NORTH) { //position is invalid
            playerMove = OUTSIDE_BOUNDS;
        }
        else if (currentPositionY < 1 && player->direction == WEST) {
            playerMove = OUTSIDE_BOUNDS;
        }
        else if (currentPositionX > boardSize-2 && player->direction == SOUTH)
        {
            playerMove = OUTSIDE_BOUNDS;
        }
        else if (currentPositionY > boardSize-2 && player->direction == EAST) {
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
    for(int y = -2; y < boardSize; ++y) {
            for(int x = -1; x < boardSize; ++x) { //navigating through two dimensional vector array with two for loops
                if ( y == -2 && x == -1) { //if it is the first part of both arrays, print "   "
                        std::cout << EMPTY_OUTPUT << EMPTY_OUTPUT << EMPTY_OUTPUT;
                        
                    }
                    else if (y == -1 && x == -1) { //second blank area, print "   "
                        std::cout << EMPTY_OUTPUT << EMPTY_OUTPUT << EMPTY_OUTPUT;
                    }
                    else if (y == -2) { //if it is the first part of the first array, print the number out eg; "|1|"
                        if (x < 10) {
                            std::cout << "0" << LINE_OUTPUT;
                        }
                        else {
                            std::cout << "1" << LINE_OUTPUT;
                        }
                    }
                    else if (y == -1) { //second line, second digit print
                        std::cout << x % 10 << LINE_OUTPUT;
                    }
                    else if (x == -1) { //if it is the first part of the second array, print the number out eg; "|5|"
                        if (y < 10) { // y less than 10, so add zero
                            std::cout << "0" << std::to_string(y) + LINE_OUTPUT;
                        }
                        else {
                            std::cout << std::to_string(y) + LINE_OUTPUT;
                        }
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