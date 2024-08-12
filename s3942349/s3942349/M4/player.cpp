#include "player.h"

Position::Position() {

}

Position::Position(int x, int y) {
    this->x = x; //store position varibles in position class
    this->y = y;
}

Player::Player() {
    this->position = position; //store player varibles in player class
    this->direction = direction;
    this->moves = moves;
}

void Player::initialisePlayer(Position* position) {
    this->moves = 0; //sets up player to be init with 0 moves, defualt direction and desired position
    this->position = *position;
    this->direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection) {
    if(turnDirection == TURN_RIGHT) { //turn right
        //update direction depending on current direction
        if(direction == NORTH) {
            direction = EAST;
        }
        else if (direction == EAST)
        {
            direction = SOUTH;
        }
        else if (direction == SOUTH)
        {
            direction = WEST;
        }
        else { //west
            direction = NORTH;
        }
    }

    if(turnDirection == TURN_LEFT) { //turn left
        //update direction depending on current direction
        if(direction == NORTH) {
            direction = WEST;
        }
        else if (direction == EAST)
        {
            direction = NORTH;
        }
        else if (direction == SOUTH)
        {
            direction = EAST;
        }
        else { //west
            direction = SOUTH;
        }
        
    }
}

Position Player::getNextForwardPosition() {
    int xPos = position.x; //get current position and store in x and y variables then create a position object with current variables so that it can be altered later
    int yPos = position.y;
    Position nextForwardPosition = Position(xPos,yPos);
    
    //if statements for all four directions (E=+y, S=+x, W=-y, N=-x)
    //statements will move the player one space toward the direction that they are facing
    
    if (direction == NORTH) {
        nextForwardPosition = Position(xPos-1,yPos);
    }
    else if (direction == EAST) {
        nextForwardPosition = Position(xPos,yPos+1);
    }
    else if (direction == SOUTH) {
        nextForwardPosition = Position(xPos+1,yPos);
    }
    else { //west
        nextForwardPosition = Position(xPos,yPos-1);
    }
    return nextForwardPosition;
}

void Player::updatePosition(Position position) {
    this->position = position; //update player object with new position and then add 1 to moves int
    this->moves = moves + 1;
}

void Player::displayDirection() {
    // depending on player object orientation, print corresponding arrow
    if (direction == NORTH)
    {
       std::cout << DIRECTION_ARROW_OUTPUT_NORTH;
    }
    else if (direction == EAST)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_EAST;
    }
    else if (direction == SOUTH)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_SOUTH;
    }
    else { //west
        std::cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
}
