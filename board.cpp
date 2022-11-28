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
		tempContent = {};
		for (int column = 0; column < (int)fileContent.length(); column++)
		{
			if (fileContent[column] == '0')  // murs infranchissable 
			{
				cases = new Wall({column, row});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '1')  // murs vide pour se déplacer
			{
				cases = new Cell({column, row});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '2')  // joueur
			{
				cases = new Cell({column, row});
				player = new Player({column, row});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '3')  // boites qu'on peut bouger
			{
				cases = new Box({column, row});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '4')
			{
				cases = new Target({column, row});
				tempContent.push_back(cases);
				targetCount += 1;
			}
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
	move = new Move(this, player->getPos(), key);
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