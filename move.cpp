
#include "move.hpp"
#include "cell.hpp"
#include <iostream>
using namespace std;

Move::Move(Board *board, Point currentPos, int keyDepl) : board{board}, currentPos{currentPos}, keyDepl{keyDepl} {}


Move::Move() {}


bool Move::checkMove()  // faire tous les if
{
	convertMove();
	int test = 1;
	if (!isInBoard(test)) return false;
	if (!(board->getCell(wishedDepl)->getMoveInside())) return false;
	return true;
}


bool Move::isInBoard(int test)
{
	// si il est inférieur à 0 ou supérieur à la taille du vecteur on n'autorise pas le déplacement
	if (wishedDepl.x < 0) return false;
	if (wishedDepl.y < 0) return false;
	if (wishedDepl.x >= board->getSize().x) return false;
	if (wishedDepl.y >= board->getSize().y) return false;
	if (test == 1)  // pour éviter les appels reccursif avec l'appel de canItMove()
	{
		if (!canItMove()) return false;	
 	}
	return true;
}


bool Move::canItMove()  // si le déplacement de la box est possible on doit changer box avec la cell où elle atterit
{
	if (board->getCell(wishedDepl)->getCanBeMoved())  // si elle peut pas être bougé vérifier que derrière elle s'est possible aussi
	{
		wishedDepl.x += senseMovement.x;  // on verifie la case derrière la box qu'on veut bouger
		wishedDepl.y += senseMovement.y;
		if (isInBoard(2) && board->getCell(wishedDepl)->getMoveInside())
		{
			Cell *tempCell = board->getCell(wishedDepl);
			Cell *tempBox = board->getCell({wishedDepl.x - senseMovement.x, wishedDepl.y - senseMovement.y});
			board->setCell(wishedDepl, tempBox);
			tempBox->setPos(wishedDepl);
			wishedDepl.x -= senseMovement.x;					// reset du mouvement
			wishedDepl.y -= senseMovement.y;
			board->setCell(wishedDepl, tempCell);
			tempCell->setPos(wishedDepl);
			return true;
		}
		else
		{
			wishedDepl.x -= senseMovement.x; 						// reset du mouvement
			wishedDepl.y -= senseMovement.y;
		}
		return false;
	}
	return true;   // si elle peut pas être bougé return true
}


void Move::convertMove()
{
	senseMovement = Point{0,0};
	switch (keyDepl)
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
	default:
		break;
    }
    wishedDepl.x = currentPos.y + senseMovement.x;
    wishedDepl.y = currentPos.x + senseMovement.y;
}


//Cell Move::findCell(Point &pos)
//{
//	return board->boardMatrix[pos.x/60].at(pos.y/60);
//}