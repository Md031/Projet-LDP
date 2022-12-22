
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "cell.hpp"


class Player
{
private:
	Point currentPos;
	Fl_Color cellColor = fl_rgb_color(0, 0, 204);
	Fl_Color frameColor = FL_BLACK;
public:
	Player(Point currentPos);
	Player();
	~Player() = default;
	void keyPressed(int key);
	void draw();
	Point getPos();
	void setX(int newX);
	void setY(int newY);
	void moveAnim();
};

#endif