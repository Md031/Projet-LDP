#include "board.hpp"


Board::Board(const string levelFile) : levelFile{levelFile} { createMatrix();}


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
			if (isalpha(fileContent[column])) tempContent.push_back(cases);  // check isalnum pour ne pas push back le /n ou /0 du fichier
		}
		boardMatrix.push_back(tempContent);
		row++;  // passer à la ligne suivante de la matrice
	}
}


void Board::draw()
{
	for (auto &v: boardMatrix)
	{
    	for (auto &c: v)
    	{
 			c->draw();
		}
	}
	for (auto &v: targetGoal)
	{
		if (!v->getFullness()) v->draw();  // si la target n'est pas rempli on la dessine 
	}
	player->draw();
	printCurrentStep();
	if (maxStep != 0) printMaxStep();
	if (checkWin())
	{
		fl_font(FL_HELVETICA,75);
		fl_color(fl_rgb_color(0,0,255));
		fl_draw("GG",0,0,1000,700,FL_ALIGN_CENTER,nullptr,false);
	}
}

Board::~Board()
{
	delete player;
	for (auto &v: targetGoal) delete v;
	for (auto &v : boardMatrix)
	{
		for (auto &c : v)
		{
			delete c;
		}
	}
}


void Board::keyPressed(int key)
{
	move = new Move(this, player->getPos(), key, targetGoal);
	if (move->checkMove())
	{
		player->keyPressed(key);
		currentStep++;
	}
	delete move;
}


string Board::getLvlFile() { return levelFile; }


Cell*  Board::getCell(const Point &pos) { return boardMatrix[pos.x][pos.y]; }


Point Board::getSize() { return Point{(int)boardMatrix.size(), (int)boardMatrix[0].size()}; }


void Board::setCell(Point pos, Cell *newCell) { boardMatrix[pos.x][pos.y] = newCell; }


bool Board::checkWin() { return targetCount == 0; }


void Board::updateTargetCount(int updt) { targetCount += updt; }


int Board::getTargetCount(){return targetCount;}


void Board::printCurrentStep()
{
	string printStep = "Your current step : " + to_string(currentStep);
	fl_font(FL_HELVETICA,30);
	fl_color(fl_rgb_color(0,0,0));
	fl_draw(printStep.c_str(),0,0,350,50,FL_ALIGN_CENTER,nullptr,false);
}


void Board::printMaxStep()
{
	string printMax = "Max step for this level : " + to_string(maxStep);
	fl_font(FL_HELVETICA,30);
	fl_color(fl_rgb_color(0,0,0));
	fl_draw(printMax.c_str(),0,0,425,150,FL_ALIGN_CENTER,nullptr,false);
}