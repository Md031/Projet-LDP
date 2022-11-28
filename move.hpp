
#ifndef MOVE_HPP
#define MOVE_HPP

#include <vector>
#include "board.hpp"

using namespace std;

class Board;

class Move
{
private:
	Board *board;
	Point currentPos;  		// position du joueur
	Point wishedDepl;  		// position où le joueur veut aller
	Point senseMovement; 	// direct dans laquelle il se déplace
	int keyDepl;			// le keycode du déplacement
public:
	Move(Board *board, Point currentPos, int keyDepl);
	Move();
	~Move() = default;

	bool checkMove();
	bool isInBoard(int test);
	bool canItMove();
	void convertMove();
	Cell findCell(Point &pos);
};

#endif