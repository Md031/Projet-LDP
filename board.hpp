
#ifndef BOARD_HPP
#define BOARD_HPP


#include "wall.hpp"
#include "cell.hpp"
#include "box.hpp"
#include "player.hpp"
#include "move.hpp"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Move;

class Board
{
private:
	string levelFile;
	vector<vector<Cell*>> boardMatrix = {};
	string dirDepl;
	Player* player;
	Move* move;
public:
	Board(string levelFile);
	~Board();
	
	void keyPressed(int key);
	void init();
	void draw();

	void createMatrix();
	
	string getLvlFile();
	Cell* getCell(const Point &pos);
	Point getSize();
	void setCell(Point pos, Cell *newCell);
};


#endif