
#include "player.hpp"


Player::Player(Point currentPos) : currentPos{Point(currentPos)} {}


Player::Player() {}


Point Player::getPos() { return currentPos; }


void Player::setX(int &newX) { currentPos.x = newX; }


void Player::setY(int &newY) { currentPos.y = newY; }


void Player::movePlayer(Point &newPos) 
{ 
	setX(newPos.x);
	setY(newPos.y);
}


void Player::draw()
{
	fl_draw_box(FL_FLAT_BOX, 	 currentPos.x*60+15, currentPos.y*60+115, 30, 30, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, currentPos.x*60+15, currentPos.y*60+115, 30, 30, frameColor);
}