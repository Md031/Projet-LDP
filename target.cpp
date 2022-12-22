
#include "target.hpp"

Target::Target(Point pos) : pos{pos} {}


Target::Target() {}


void Target::draw()
{
	Point posDessin{pos.x*60+35, pos.y*60+35};
	fl_draw_box(FL_FLAT_BOX, posDessin.x, posDessin.y, 30, 30, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, posDessin.x, posDessin.y, 30, 30, frameColor);
}


void Target::reverseFullness()
{
	if (isFull) isFull = false;
	else isFull = true;
}


bool Target::getFullness() { return isFull; }


Point Target::getPos() { return pos; }