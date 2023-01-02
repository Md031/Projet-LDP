
#include "cell.hpp"


bool Point::comparePoint(Point otherPoint)
{
	return (x == otherPoint.y) && (y == otherPoint.x);
}


bool Point::operator==(const Point &other)
{
	return (x == other.y) && (y == other.x);
}


Point &Point::operator+(const Point &other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Point &Point::operator+=(const Point &other)  // surcharge opérateur +
{
	x += other.x;
	y += other.y;
	return *this;
}


Point &Point::operator=(const Point &other)
{
	x = other.y;
	y = other.x;
	return *this;
}

Point &Point::operator-=(const Point &other)  // surcharge opérateur +
{
	x -= other.x;
	y -= other.y;
	return *this;
}


Cell::Cell(Point pos, Fl_Color cellColor, Fl_Color frameColor, bool canBeMoved, bool canMoveInside, bool isATarget) : 
	pos{Point(pos)}, cellColor{cellColor}, frameColor{frameColor}, canBeMoved{canBeMoved}, canMoveInside{canMoveInside}, isATarget{isATarget} {}


Cell::Cell() {}


void Cell::draw()
{
	fl_draw_box(FL_FLAT_BOX, 	 pos.x*60, pos.y*60+100, 60, 60, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x*60, pos.y*60+100, 60, 60, frameColor);
	// array<Point, 5> points
	// {
		// Point{pos.x*60 + 50 - cellSize/2, pos.y*60 + 50 - cellSize/2},  // haut gauche
		// Point{pos.x*60 + 50 - cellSize/2, pos.y*60 + 50 + cellSize/2},  // haut droit
		// Point{pos.x*60 + 50 + cellSize/2, pos.y*60 + 50 + cellSize/2},  // bas droit
		// Point{pos.x*60 + 50 + cellSize/2, pos.y*60 + 50 - cellSize/2}, 	// bas gauche
		// Point{pos.x*60 + 50 - cellSize/2, pos.y*60 + 50 - cellSize/2}  	// haut gauche
	// };
	// fl_color(cellColor);
	// fl_begin_polygon();
	// for (auto &point : points) 
	// {
		// fl_vertex(point.x, point.y);
	// }
	// fl_end_polygon();
	// fl_color(frameColor);
	// fl_begin_line();
	// for (auto &point : points) 
	// {
		// fl_vertex(point.x, point.y);
	// }
	// fl_end_line();
}


Point Cell::getPos() const
{
	return pos;
}



bool Cell::getMoveInside() const
{
	return canMoveInside;
}


bool Cell::getIsTarget() const
{
	return isATarget;
}


bool Cell::getCanBeMoved() const
{
	return canBeMoved;
}


Cell &Cell::operator=(const Cell &other)
{
	if (this != &other) 
	{
		pos.x = other.pos.y;
		pos.y = other.pos.x;
		cellColor = other.cellColor;
		frameColor = other.frameColor;
		canBeMoved = other.canBeMoved;
		canMoveInside = other.canMoveInside;
	}
	// Cell *tempCell = board->getCell(wishedDepl);
	// Cell *tempBox = board->getCell({wishedDepl.x - senseMovement.x, wishedDepl.y - senseMovement.y});
	// board->setCell(wishedDepl, tempBox);
	// tempBox->setPos(wishedDepl);
	return *this;
}


void Cell::setPos(const Point &newPos) { pos.x  = newPos.y; pos.y = newPos.x; }
