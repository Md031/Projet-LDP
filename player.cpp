
#include "player.hpp"


Player::Player(Point currentPos) : currentPos{Point(currentPos)} {}


Player::Player() {}


int Player::getPosX() 
{
	return currentPos.x;
}


int Player::getPosY()
{
	return currentPos.y;
}


void Player::setX(int newX)
{
	currentPos.x = newX;
}


void Player::setY(int newY)
{
	currentPos.y = newY;
}

void Player::keyPressed(int key)
{	
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
	case 'q':
		exit(0);
    }
}


void Player::draw()
{
	Point posDessin{currentPos.x*60+115, currentPos.y*60+115};
	fl_draw_box(FL_FLAT_BOX, posDessin.x, posDessin.y, 30, 30, FL_GREEN);
  	fl_draw_box(FL_BORDER_FRAME, posDessin.x, posDessin.y, 30, 30, FL_BLACK);
}