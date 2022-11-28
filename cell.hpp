#ifndef CELLS_HPP
#define CELLS_HPP

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <array>
#include <iostream>

using namespace std;

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
	bool isATarget;
	int cellSize = 60;
public:
	Cell(Point pos, Fl_Color cellColor = fl_rgb_color(0, 153, 0), Fl_Color frameColor = FL_BLACK, 
		bool canBeMoved = false, bool canMoveInside = true, bool isATarget = false);
	Cell();
	virtual ~Cell() = default;
	virtual void draw();
	virtual Point getPos() const;
	virtual void setPos(const Point &newPos);
	virtual bool getMoveInside() const;
	virtual bool getCanBeMoved() const;
	virtual bool getIsTarget() const;
	virtual Cell &operator=(const Cell &other);
};

#endif