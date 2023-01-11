
#ifndef BOX_HPP
#define BOX_HPP

#include "cell.hpp"

class Box : public Cell
{
public:
	Box(Point pos, Fl_Color cellColor = fl_rgb_color(153, 76, 0), Fl_Color frameColor = FL_BLACK, 
		bool canBeMoved = true, bool canMoveInside = false, bool isATarget = false);
	Box();
	~Box() override = default;
};


#endif