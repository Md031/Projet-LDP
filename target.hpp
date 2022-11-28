
#ifndef TARGET_HPP
#define TARGET_HPP

#include "cell.hpp"

class Target : public Cell
{
public:
	Target(Point pos, Fl_Color cellColor = fl_rgb_color(204, 0, 0), Fl_Color frameColor = FL_BLACK, 
		bool canBeMoved = false, bool canMoveInside = true, bool isATarget = true);
	Target();
	~Target() override = default;
};

#endif