
#include "wall.hpp"

Wall::Wall(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved, bool canMoveInside) 
{
	this->pos = pos;
	this->cellColor = cellColor;
	this->frameColor = frameColor;
	this->canBeMoved = canBeMoved;
	this->canMoveInside = canMoveInside;
}


Wall::Wall() {}