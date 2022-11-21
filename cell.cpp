
#include "cell.hpp"


Cell::Cell(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved) : pos{Point(pos)}, cellColor{cellColor}, frameColor{frameColor}, canBeMoved{canBeMoved} {}


Cell::Cell() {}


Cell::~Cell() 
{
	delete this;
}


void Cell::draw()
{
	fl_draw_box(FL_FLAT_BOX, pos.x, pos.y, 50, 50, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x, pos.y, 50, 50, frameColor);
}


int Cell::getPosX() const
{
	return pos.x;
}


int Cell::getPosY() const
{
	return pos.y;
}