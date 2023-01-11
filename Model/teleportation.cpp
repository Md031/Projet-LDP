#include "teleportation.hpp"


Teleportation::Teleportation(Point pos) : pos{pos} {}


Teleportation::Teleportation() {}


void Teleportation::draw()
{
	fl_draw_box(FL_FLAT_BOX, 	 pos.x*60+15, pos.y*60+115, 30, 30, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x*60+15, pos.y*60+115, 30, 30, frameColor);
}


Point Teleportation::getPos() { return pos; }