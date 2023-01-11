
#include "wall.hpp"

Wall::Wall(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved, bool canMoveInside, bool isATarget)
	: Cell(pos, cellColor, frameColor, canBeMoved, canMoveInside, isATarget) {}


Wall::Wall() {}