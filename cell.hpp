#ifndef CELLS_HPP
#define CELLS_HPP

#include <FL/Fl.H>
#include <FL/fl_draw.H>

struct Point
{
	int x, y;
};


class Cell
{
protected:
	Point pos;
	Fl_Color cellColor;
	Fl_Color frameColor;
	bool canBeMoved;
public:
	Cell(Point pos, Fl_Color cellColor = FL_RED, Fl_Color frameColor = FL_BLACK, bool canBeMoved = false);
	Cell();
	virtual ~Cell();
	virtual void draw();
	virtual int getPosX() const;
	virtual int getPosY() const;
};

#endif