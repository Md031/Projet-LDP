#include "board.hpp"


Board::Board(const string levelFile) : levelFile{levelFile} 
{ 
	createMatrix();
	move = new Move(this, targetGoal);
}


void Board::createMatrix()
{
	fstream readFile;
	string fileContent;
	readFile.open(levelFile, ios::in);
	vector<Cell*> tempContent;
	int row = 0;
	Cell* cases;
	string maxStepCount;
	getline(readFile, maxStepCount);
	maxStep = stoi(maxStepCount);
	while (getline(readFile, fileContent))  // on récupère le design du niveau
	{
		tempContent = {};  // reset du vecteur tempContent
		for (int column = 0; column < (int)fileContent.length(); column++)
		{
			if (fileContent[column] == 'W') 	 cases = new Wall({column, row});  	// murs infranchissable 
			else if (fileContent[column] == 'E') cases = new Cell({column, row});  	// murs vide pour se déplacer
			else if (fileContent[column] == 'B') cases = new Box({column, row});  	// boites qu'on peut bouger 
			else if (fileContent[column] == 'P')  // la case du joueur
			{
				cases = new Cell({column, row});
				player = new Player({column, row});
			}
			else if (fileContent[column] == 'T')  // les cases des targets
			{
				cases = new Cell({column, row});
				Target* targetTemp = new Target({column, row});
				targetGoal.push_back(targetTemp);  // on récupère la position des targets
				targetCount += 1;
			}
			else if ( '1' == fileContent[column]) // les cases pour les tp, chaque tp sera relié à une autre case avec le même numéro
			{
				cases = new Cell({column, row});
				Teleportation* tpTemp = new Teleportation({column, row});
				tpVector.push_back(tpTemp);
			}
			if (isalnum(fileContent[column])) tempContent.push_back(cases);  // check isalnum pour ne pas push back le /n ou /0 du fichier
		}
		boardMatrix.push_back(tempContent);
		row++;  // passer à la ligne suivante de la matrice
	}
}


void Board::draw()
{
	for (auto &v: boardMatrix)
	{
    	for (auto &c: v) c->draw();
	}
	for (auto &v: tpVector) v->draw();
	for (auto &v: targetGoal)
	{
		if (!v->getFullness()) v->draw();  // si la target n'est pas rempli on la dessine 
	}
	player->draw();
	printStepInfo();
	if (checkWin())
	{
		if (currentStep > maxStep) printFinal = "You lose";
		fl_font(FL_HELVETICA, 50);
		fl_color(fl_rgb_color(0, 0, 255));
		fl_draw(printFinal.c_str(), 0, 0, 1200, 100, FL_ALIGN_CENTER, nullptr, false);
	}
}

Board::~Board()
{
	delete player;
	delete move;
	for (auto &v: targetGoal) delete v;
	for (auto &v: tpVector) delete v;
	for (auto &v: boardMatrix)
	{
		for (auto &c: v) delete c; 
	}
}


void Board::keyPressed(int key)
{
	// playerPos = player->getPos();
	// simulationMove(playerPos, key);
	// if (playerPos.comparePoint(tpVector.at(0)->getPos())) 
	// {
		// playerPos = tpVector.at(1)->getPos(); 
		// player->movePlayer(0, playerPos);
		// currentStep++;
		// return;
	// }
	// else if (playerPos.comparePoint(tpVector.at(1)->getPos())) 
	// { 
		// playerPos = tpVector.at(0)->getPos(); 
		// player->movePlayer(0, playerPos);
		// currentStep++;
		// return;
	// }
	playerPos = player->getPos();
	Point senseMov{0,0};
	movement(key, senseMov);
	if (move->checkMove(playerPos, senseMov))
	{
		playerPos += senseMov;
		player->movePlayer(key, playerPos);
		currentStep++;
	}
}


string Board::getLvlFile() { return levelFile; }


Cell*  Board::getCell(const Point &pos) { return boardMatrix[pos.x][pos.y]; }


Point Board::getSize() { return Point{(int)boardMatrix.size(), (int)boardMatrix[0].size()}; }


void Board::setCell(Point pos, Cell *newCell) { boardMatrix[pos.x][pos.y] = newCell; }


bool Board::checkWin() { return targetCount == 0; }


void Board::updateTargetCount(int updt) { targetCount += updt; }


int Board::getTargetCount() { return targetCount; }


vector<Teleportation*> Board::getTpVector() { return tpVector; }


void Board::printStepInfo()
{
	string printStep = "Your current step : " + to_string(currentStep);
	string printMaxStep = "";
	if (maxStep > 0) printMaxStep = "Max step for this level : " + to_string(maxStep);  // si on a un max step pour ce lvl
	fl_font(FL_HELVETICA,30);
	fl_color(fl_rgb_color(0,0,0));
	fl_draw(printStep.c_str(),0,0,350,50,FL_ALIGN_CENTER,nullptr,false);
	fl_draw(printMaxStep.c_str(),0,0,425,150,FL_ALIGN_CENTER,nullptr,false);
}


void Board::movement(int key, Point& senseMovement)
{
	switch (key)
	{
	case FL_Left:
		senseMovement.y -= 1;
		break;
	case FL_Right:
		senseMovement.y += 1;
		break;
	case FL_Up:
		senseMovement.x -= 1;
		break;
	case FL_Down:
		senseMovement.x += 1;
		break;
    }
}