
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
	/**
	 * Fonction qui cache la target si il y a une box
	 * sur elle et la décache si il n'y a plus de box sur elle
	 */
	if (isFull) isFull = false;
	else isFull = true;

}


bool Target::getFullness() { return isFull; }


Point Target::getPos() { return pos; }