#ifndef WALL_HPP
#define WALL_HPP

#include "cell.hpp"


class Wall : public Cell
{
public:
	Wall(Point pos, Fl_Color cellColor = FL_BLUE, Fl_Color frameColor = FL_BLACK, bool canBeMoved = false, bool canMoveInside = false);
	Wall();
	~Wall() override = default;
};

#endif