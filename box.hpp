#include "cell.hpp"

#ifndef BOX_HPP
#define BOX_HPP

class Box : public Cell
{
public:
	Box(Point pos, Fl_Color cellColor = FL_YELLOW, Fl_Color frameColor = FL_BLACK, bool canBeMoved = true, bool canMoveInside = false);
	Box();
	~Box() override = default;
};


#endif