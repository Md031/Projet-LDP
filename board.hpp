#include <fstream>
#include <iostream>
#include <vector>

#include "cells.hpp"

using namespace std;


class Board
{
private:
	const string levelFile;
	vector<vector<Cells*>> boardMatrix = {};
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
