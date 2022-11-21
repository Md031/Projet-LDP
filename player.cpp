
#include "player.hpp"
#include <array>
#include <math.h>


Player::Player(Point currentPos) : currentPos{Point(currentPos)} {}


Player::Player() {}


Player::~Player()
{
	delete this;
}

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
	Point posDessin{currentPos.x*50+163, currentPos.y*50+163};
	fl_draw_box(FL_FLAT_BOX, posDessin.x, posDessin.y, 25, 25, FL_GREEN);
  	fl_draw_box(FL_BORDER_FRAME, posDessin.x, posDessin.y, 25, 25, FL_BLACK);
}