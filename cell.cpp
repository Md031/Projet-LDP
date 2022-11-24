
#include "cell.hpp"


Cell::Cell(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved, bool canMoveInside) : pos{Point(pos)}, cellColor{cellColor}, frameColor{frameColor}, canBeMoved{canBeMoved}, canMoveInside{canMoveInside} {}


Cell::Cell() {}


void Cell::draw()
{
	fl_draw_box(FL_FLAT_BOX, pos.x, pos.y, 60, 60, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x, pos.y, 60, 60, frameColor);
}


int Cell::getPosX() const
{
	return pos.x;
}


int Cell::getPosY() const
{
	return pos.y;
}


bool Cell::getMoveInside() const
{
	return canMoveInside;
}


bool Cell::getCanBeMoved() const
{
	return canBeMoved;
}


Cell &Cell::operator=(const Cell &other)
{
	moussa est trop bg, zaid est 'dele'gay
}