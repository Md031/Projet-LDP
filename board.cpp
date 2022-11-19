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
	vector<Cells*> tempContent;
	int line = 0;
	Cells* cases;
	while (getline(readFile, fileContent))  // on récupère le design du niveau
	{
		tempContent = {};
		for (int cut = 0; cut < (int)fileContent.length(); cut++)
		{
			if (fileContent[cut] == '0')
			{
				cases = new Cells{Point{cut*50+250, line*50+250}, FL_BLACK, FL_BLACK};
			}
			else if (fileContent[cut] == '1')
			{
				cases = new Cells{Point{cut*50+250, line*50+250}, FL_BLACK, FL_BLUE};
			}
			else if (fileContent[cut] == '2')
			{
				cases = new Cells{Point{cut*50+250, line*50+250}, FL_BLACK, FL_RED};
				playerPosX = line;
				playerPosY = cut;
			}
			tempContent.push_back(cases);
		}
		boardMatrix.push_back(tempContent);
		line++;  // passer à la ligne suivante de la matrice
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
}

Board::~Board()
{
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
	Cells* caseTemp;
	switch (key)
	{
	case FL_Left:
		caseTemp = boardMatrix[playerPosX].at(playerPosY-1); 
		boardMatrix[playerPosX].at(playerPosY-1) = boardMatrix[playerPosX].at(playerPosY);
		boardMatrix[playerPosX].at(playerPosY) = caseTemp;
		playerPosY -= 1;
		break;
	case FL_Right:
		caseTemp = boardMatrix[playerPosX].at(playerPosY+1); 
		boardMatrix[playerPosX].at(playerPosY+1) = boardMatrix[playerPosX].at(playerPosY);
		boardMatrix[playerPosX].at(playerPosY) = caseTemp;
		playerPosY += 1;		
		break;
	case FL_Up:
		caseTemp = boardMatrix[playerPosX-1].at(playerPosY); 
		boardMatrix[playerPosX-1].at(playerPosY) = boardMatrix[playerPosX].at(playerPosY);
		boardMatrix[playerPosX].at(playerPosY) = caseTemp;
		playerPosX -= 1;
		break;
	case FL_Down:
		caseTemp = boardMatrix[playerPosX+1].at(playerPosY); 
		boardMatrix[playerPosX+1].at(playerPosY) = boardMatrix[playerPosX].at(playerPosY);
		boardMatrix[playerPosX].at(playerPosY) = caseTemp;
		playerPosX += 1;
		break;
	case 'q':
		exit(0);
    }
    cout << playerPosX  << " " << playerPosY << endl;
}
