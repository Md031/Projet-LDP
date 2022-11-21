#include "board.hpp"


Board::Board(const string levelFile) : levelFile{levelFile} {init();}


void Board::init()
{
	createMatrix();
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
				cases = new Wall({column*50+150, row*50+150});
			}
			else if (fileContent[column] == '1')  // murs vide pour se déplacer
			{
				cases = new Cell({column*50+150, row*50+150});
			}
			else if (fileContent[column] == '2')  // joueur
			{
				cases = new Cell({column*50+150, row*50+150});
				player = new Player({column, row});
			}
			//else if (fileContent[column] == '3')  // boites qu'on peut bouger
			//{
			//	cases = new Cell({column*50+150, row*50+150});
			//}
			tempContent.push_back(cases);
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
	for (auto &v : boardMatrix)
	{
		for (auto &c : v)
		{
			cout << "problème" << endl;
			delete c;
		}
	}
	cout << "plus de problème" << endl;
}

void Board::keyPressed(int key)
{
	player->keyPressed(Fl::event_key());
}