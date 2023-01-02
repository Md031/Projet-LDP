
#ifndef BOARD_HPP
#define BOARD_HPP


#include "wall.hpp"
#include "cell.hpp"
#include "box.hpp"
#include "target.hpp"
#include "player.hpp"
#include "move.hpp"
#include "teleportation.hpp"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Move;

class Board
{
private:
	string levelFile;
	vector<string> levelContent = {};
	vector<vector<Cell*>> boardMatrix = {};
	vector<Target*> targetGoal = {};  // vecteur qui contient toutes les target
	vector<Teleportation*> tpVector = {};
	string dirDepl;  	// déplacement désiré
	Player* player;  	// le player 
	Point playerPos;	// pour que le board puisse faire des simulations de déplacements
	Move* move;		 	// le mouvement fait par le player
	int targetCount = 0;
	int currentStep = 0;
	int maxStep = 0;
	int bestScore = 0;
	string printFinal = "You win";
public:
	Board(string levelFile);
	~Board();
	
	void keyPressed(int key);
	void draw();

	void createMatrix();
	string getLvlFile();
	Cell* getCell(const Point &pos);
	Point getSize();
	void setCell(Point pos, Cell *newCell);
	bool checkWin();
	void updateTargetCount(int updt);
	int getTargetCount();
	void printStepInfo();
	vector<Teleportation*> getTpVector();
	void simulationMove(Point& simulate, int key);
	void movement(int key, Point& senseMovement);  // permet de déterminer le sens du mouvement
};


#endif