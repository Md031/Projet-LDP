#include "board.hpp"


Board::Board(const string levelFile) : levelFile{levelFile} {init();}


void Board::init()
{
	createMatrix();
	move = new Move(&boardMatrix);
}


string Board::getLvlFile() { return levelFile; }


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
				cases = new Wall({column*60+100, row*60+100});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '1')  // murs vide pour se déplacer
			{
				cases = new Cell({column*60+100, row*60+100});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '2')  // joueur
			{
				cases = new Cell({column*60+100, row*60+100});
				player = new Player({column, row});
				tempContent.push_back(cases);
			}
			else if (fileContent[column] == '3')  // boites qu'on peut bouger
			{
				cases = new Box({column*60+100, row*60+100});
				tempContent.push_back(cases);
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
}

Board::~Board()
{
	delete player;
	delete move;
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
	move->setCurrentPos({player->getPosY(), player->getPosX()});
	move->setKeyDepl(key);
	if (move->checkMove())
	{
		player->keyPressed(key);
	}
}
