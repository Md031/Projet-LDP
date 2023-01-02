
#include "player.hpp"


Player::Player(Point currentPos) : currentPos{Point(currentPos)} {}


Player::Player() {}


Point Player::getPos() { return currentPos; }


void Player::setX(int newX) { currentPos.x = newX; }


void Player::setY(int newY) { currentPos.y = newY; }


void Player::movePlayer(int key, Point newPos)
{	if (key == 0) currentPos = newPos;
	switch (key)
	{
	case FL_Left:
		currentPos.x -= 1;
		break;
	case FL_Right:
		currentPos.x += 1;
		break;
	case FL_Up:
		currentPos.y -= 1;
		break;
	case FL_Down:
		currentPos.y += 1;
		break;
    }
}


void Player::draw()
{
	fl_draw_box(FL_FLAT_BOX, 	 currentPos.x*60+15, currentPos.y*60+115, 30, 30, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, currentPos.x*60+15, currentPos.y*60+115, 30, 30, frameColor);
}