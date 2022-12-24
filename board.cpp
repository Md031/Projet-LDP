#include "board.hpp"


Board::Board(const string levelFile) : levelFile{levelFile} {init();}


void Board::init()
{
	createMatrix();
}


void Board::createMatrix()
{
	fstream readFile;
	string fileContent;
	readFile.open(levelFile, ios::in);
	vector<Cell*> tempContent;
	int row = 0;
	Cell* cases;
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
	}
	delete move;
}


string Board::getLvlFile() { return levelFile; }


Cell*  Board::getCell(const Point &pos) { return boardMatrix[pos.x][pos.y]; }


Point Board::getSize()
{ 
	return Point{(int)boardMatrix.size(), (int)boardMatrix[0].size()}; 
}


void Board::setCell(Point pos, Cell *newCell)
{
	 boardMatrix[pos.x][pos.y] = newCell;
}


bool Board::checkWin()
{
	return targetCount == 0;
}


void Board::updateTargetCount(int updt)
{
	targetCount += updt;
}
int Board::getTargetCount(){return targetCount;}