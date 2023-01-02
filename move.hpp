
#ifndef MOVE_HPP
#define MOVE_HPP

#include <vector>
#include "board.hpp"
#include "teleportation.hpp"

using namespace std;

class Board;


class Move
{
private:
	Board *board;
	vector<Target*> targetGoal;
	vector<Teleportation*> tpVector;
public:
	Move(Board *board, vector<Target*> targetGoal);
	Move();
	~Move() = default;

	bool checkMove(Point posPlayer, Point senseMovement);
	bool isInBoard(Point posPlayer);
	bool canItMove(Point posPlayer, Point senseMovement);
	bool moveBox(Point wishedDepl, Point senseMovement);
	Cell findCell(Point pos);
};

#endif