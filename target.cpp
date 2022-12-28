
#include "target.hpp"


Target::Target(Point pos) : pos{pos} {}


Target::Target() {}


void Target::draw()
{
	fl_draw_box(FL_FLAT_BOX, 	 pos.x*60+15, pos.y*60+115, 30, 30, cellColor);
	fl_draw_box(FL_BORDER_FRAME, pos.x*60+15, pos.y*60+115, 30, 30, frameColor);
}


void Target::reverseFullness()
{
	if (isFull) isFull = false;
	else isFull = true;

}


bool Target::getFullness() { return isFull; }


Point Target::getPos() { return pos; }