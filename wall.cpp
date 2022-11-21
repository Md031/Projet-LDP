
#include "wall.hpp"

Wall::Wall(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved) : pos{Point(pos)}, cellColor{cellColor}, frameColor{frameColor}, canBeMoved{canBeMoved} {}


Wall::~Wall()
{
	delete this;
}

void Wall::draw()
{
	fl_draw_box(FL_FLAT_BOX, pos.x, pos.y, 50, 50, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x, pos.y, 50, 50, frameColor);
}


int Wall::getPosX() const 
{
	return pos.x;
}


int Wall::getPosY() const
{
	return pos.y;
}