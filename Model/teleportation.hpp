
#ifndef TELEPORTATION_HPP
#define TELEPORTATION_HPP

#include "cell.hpp"

class Teleportation
{
private:
	Point pos;
	Fl_Color cellColor = fl_rgb_color(255, 128, 0);
	Fl_Color frameColor = FL_BLACK;
	bool isFull = false;
public:
	Teleportation(Point pos);
	Teleportation();
	~Teleportation() = default;
	Point getPos();
	void draw();
};


#endif