
#include "cell.hpp"


Cell::Cell(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved, bool canMoveInside) : pos{Point(pos)}, cellColor{cellColor}, frameColor{frameColor}, canBeMoved{canBeMoved}, canMoveInside{canMoveInside} {}


Cell::Cell() {}


void Cell::draw()
{
	fl_draw_box(FL_FLAT_BOX, pos.x, pos.y, 60, 60, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x, pos.y, 60, 60, frameColor);
	//{
	// 	array<Point, 5> points
	// 	{
	// 		Point{pos.x - w / 2, pos.y - h / 2},
	// 		Point{pos.x - w / 2, pos.y + h / 2},
	// 		Point{pos.x + w / 2, pos.y + h / 2},
	// 		Point{pos.x + w / 2, pos.y - h / 2},
	// 		Point{pos.x - w / 2, pos.y - h / 2}
	// 	};
	// 	fl_color(cellColor);
	// 	fl_begin_polygon();
	// 	for (auto &point : points) 
	// 	{
	// 		fl_vertex(point.x, point.y);
	// 	}
	// 	fl_end_polygon();
	// 	fl_color(frameColor);
	// 	fl_begin_line();
	// 	for (auto &point : points) 
	// 	{
	// 		fl_vertex(point.x, point.y);
	// 	}
	// 	fl_end_line();
}


int Cell::getPosX() const
{
	return pos.x;
}


int Cell::getPosY() const
{
	return pos.y;
}


bool Cell::getMoveInside() const
{
	return canMoveInside;
}


bool Cell::getCanBeMoved() const
{
	return canBeMoved;
}


Cell &Cell::operator=(const Cell &other)
{
	if (this != &other) 
	{
		pos = other.pos;
		cellColor = other.cellColor;
		frameColor = other.frameColor;
	}
	return *this;
}


void Cell::setPos(const Point &newPos) { pos = newPos; }