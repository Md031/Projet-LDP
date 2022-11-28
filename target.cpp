
#include "target.hpp"

Target::Target(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved, bool canMoveInside, bool isATarget) 
{
	this->pos = pos;
	this->cellColor = cellColor;
	this->frameColor = frameColor;
	this->canBeMoved = canBeMoved;
	this->canMoveInside = canMoveInside;
	this->isATarget = isATarget;
}


Target::Target() {}