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
	bool canMoveInside;
public:
	Cell(Point pos, Fl_Color cellColor = FL_RED, Fl_Color frameColor = FL_BLACK, bool canBeMoved = false, bool canMoveInside = true);
	Cell();
	virtual ~Cell() = default;
	virtual void draw();
	virtual int getPosX() const;
	virtual int getPosY() const;
	virtual bool getMoveInside() const;
	virtual bool getCanBeMoved() const;
	virtual Cell &operator=(const Cell &other);
};

#endif