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

	string maxStepCount;  // on récupère le nbr de pas max du niveau
	getline(readFile, maxStepCount);
	maxStep = stoi(maxStepCount);

	string bestScore_s;
	getline(readFile, bestScore_s);
	bestScore = stoi(bestScore_s);
	while (getline(readFile, fileContent))  // on récupère le design du niveau
	{
		levelContent.push_back(fileContent);
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
			else if (fileContent[column] == '1') // les cases pour les tp, chaque tp sera relié à une autre case avec le même numéro
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
	readFile.close();
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
		if (currentStep > maxStep && maxStep != 0) 
		{
			printFinal = "You lose";
		}
		else
		{
			fstream writingFile;
			writingFile.open(levelFile, ios::out);
			writingFile << to_string(maxStep) << endl;
			if (bestScore == 0) writingFile << to_string(currentStep) << endl;
			else if (currentStep <= bestScore) writingFile << to_string(currentStep) << endl;
			else writingFile << to_string(bestScore) << endl;
			for (auto &c : levelContent)
			{
				writingFile << c << endl;
			}
			writingFile.close();
		}
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
	playerPos = player->getPos();
	Point senseMov{0,0};
	movement(key, senseMov);
	if (key == 't')  // si le joueur essaye de se tp
	{
		if (move->checkTp(playerPos))
		{
			player->movePlayer(playerPos);
			currentStep++;
		}
		return;	
	}
	if (move->checkMove(playerPos, senseMov))  // check le move et dans playerPos on recup la nouvelle pos du player
	{
		player->movePlayer(playerPos);
		currentStep++;
		return;
	}
}


bool Board::checkWin() { return targetCount == 0; }


void Board::printStepInfo()
{
	string printStep = "Your current step : " + to_string(currentStep);
	string printMaxStep = "";
	string BestScoreLvl = "The best score for this level is : " + to_string(bestScore);
	if (bestScore == 0) BestScoreLvl = "This level has no best score yet";
	if (maxStep > 0) printMaxStep = "Max step for this level : " + to_string(maxStep);  // si on a un max step pour ce lvl
	fl_font(FL_HELVETICA,30);
	fl_color(fl_rgb_color(0,0,0));
	fl_draw(printStep.c_str(),160,20,0,0,FL_ALIGN_CENTER,nullptr,false);
	fl_draw(printMaxStep.c_str(),201,50,0,0,FL_ALIGN_CENTER,nullptr,false);
	fl_draw(BestScoreLvl.c_str(),255,80,0,0,FL_ALIGN_CENTER,nullptr,false);
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


string Board::getLvlFile() { return levelFile; }


Cell*  Board::getCell(const Point &pos) { return boardMatrix[pos.x][pos.y]; }


Point Board::getSize() { return Point{(int)boardMatrix.size(), (int)boardMatrix[0].size()}; }


void Board::setCell(Point pos, Cell *newCell) { boardMatrix[pos.x][pos.y] = newCell; }


void Board::updateTargetCount(int updt) { targetCount += updt; }


int Board::getTargetCount() { return targetCount; }


vector<Teleportation*> Board::getTpVector() { return tpVector; }


void Board::resetBestScore()
{
	fstream writingFile;
	writingFile.open(levelFile, ios::out);
	writingFile << to_string(maxStep) << endl;
	writingFile << '0' << endl;
	for (auto &c : levelContent)
	{
		writingFile << c << endl;
	}
	writingFile.close();
}