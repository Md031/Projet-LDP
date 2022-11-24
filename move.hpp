
#ifndef MOVE_HPP
#define MOVE_HPP

#include <vector>
#include "cell.hpp"

using namespace std;

class Move
{
private:
	vector<vector<Cell*>> *board;
	Point currentPos;  		// position du joueur
	Point wishedDepl;  		// position où le joueur veut aller
	Point senseMovement; 	// direct dans laquelle il se déplace
	int keyDepl;
public:
	Move(vector<vector<Cell*>> *board);
	Move();
	~Move() = default;
	bool checkMove();
	bool isInBoard(int test);
	bool canItMove();
	void convertMove();
	void setCurrentPos(Point playerPos);
	void setKeyDepl(int key);
};

#endif