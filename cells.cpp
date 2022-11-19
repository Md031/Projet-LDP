#include <fstream>

#include "cells.hpp"

Cells::Cells(Point pos, Fl_Color frameColor, Fl_Color cellColor) : pos{pos}, frameColor{frameColor}, cellColor{cellColor} {}

Cells::Cells() {}

Cells::Cells(const Cells &other) : Cells(other.pos, other.frameColor, other.cellColor) {}

Cells& Cells::operator=(const Cells &other)
{
	pos = other.pos;
	frameColor = other.frameColor;
	cellColor = other.cellColor;
	return *this;
}

Cells::~Cells() {delete this;}

void Cells::setFrameColor(Fl_Color newFColor) { frameColor = newFColor; }

void Cells::setCellColor(Fl_Color newCColor) { cellColor = newCColor; }

int Cells::getPosX() { return pos.x; }

int Cells::getPosY() { return pos.y; }

Fl_Color Cells::getCColor() { return cellColor; }

Fl_Color Cells::getFColor() { return frameColor; }

void Cells::draw() 
{ 
	fl_draw_box(FL_FLAT_BOX, pos.x, pos.y, 50, 50, cellColor);
  	fl_draw_box(FL_BORDER_FRAME, pos.x, pos.y, 50, 50, frameColor);
}
