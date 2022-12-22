
#include "player.hpp"


Player::Player(Point currentPos) : currentPos{Point(currentPos)} {}


Player::Player() {}


Point Player::getPos() 
{
	return currentPos;
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
    }
}


void Player::draw()
{

	Point posDessin{currentPos.x*60+35, currentPos.y*60+35};
	fl_draw_box(FL_FLAT_BOX, posDessin.x, posDessin.y, 30, 30, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, posDessin.x, posDessin.y, 30, 30, frameColor);
}


void Player::moveAnim()
{
	for (int i = 0; i < 60; i++)
	{
		Point posDessin{currentPos.x*60+i, currentPos.y*60+i};
		fl_draw_box(FL_FLAT_BOX, posDessin.x, posDessin.y, 30, 30, FL_GREEN);
  		fl_draw_box(FL_BORDER_FRAME, posDessin.x, posDessin.y, 30, 30, frameColor);
  	}
}