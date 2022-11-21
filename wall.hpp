#ifndef WALL_HPP
#define WALL_HPP

#include "cell.hpp"


class Wall : public Cell
{
private:
	Point pos;
	Fl_Color cellColor;
	Fl_Color frameColor;
	bool canBeMoved;
public:
	Wall(Point pos, Fl_Color cellColor = FL_BLUE, Fl_Color frameColor = FL_BLACK, bool canBeMoved = false);
	~Wall();
	void draw() override;
	int getPosX() const override;
	int getPosY() const override;
};

#endif