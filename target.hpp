
#ifndef TARGET_HPP
#define TARGET_HPP

#include "cell.hpp"

class Target
{
private:
	Point pos;
	Fl_Color cellColor = fl_rgb_color(204, 0, 0);
	Fl_Color frameColor = FL_BLACK;
	bool isFull = false;
public:
	Target(Point pos);
	Target();
	~Target() = default;
	void draw();
	void reverseFullness();
	bool getFullness();
	Point getPos();
};

#endif