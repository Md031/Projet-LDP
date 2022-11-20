
#include "wall.hpp"
#include "cell.hpp"
#include <fstream>
#include <iostream>
#include <vector>

#ifndef BOARD_HPP
#define BOARD_HPP

using namespace std;


class Board
{
private:
	const string levelFile;
	vector<vector<Cell*>> boardMatrix = {};
	int playerPosX, playerPosY;
public:
	Board(const string levelFile);
	~Board();

	void init();
	void keyPressed(int key);
	void draw();

	void createMatrix();
	string getLvlFile();
};


#endif