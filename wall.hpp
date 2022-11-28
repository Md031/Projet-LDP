#ifndef WALL_HPP
#define WALL_HPP

#include "cell.hpp"


class Wall : public Cell
{
public:
	Wall(Point pos, Fl_Color cellColor = fl_rgb_color(102, 51, 0), Fl_Color frameColor = FL_BLACK, 
		bool canBeMoved = false, bool canMoveInside = false, bool isATarget = false);
	Wall();
	~Wall() override = default;
};

#endif