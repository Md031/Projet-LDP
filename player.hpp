
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "cell.hpp"


class Player
{
private:
	Point currentPos;
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