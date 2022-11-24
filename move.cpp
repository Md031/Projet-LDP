
#include "move.hpp"
#include <iostream>
using namespace std;

Move::Move(Board *board) : board{board} {}


//Move::Move() {}


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
		cout << "fin erreur" << endl;
 	}
	return true;
}


bool Move::canItMove()  // si le déplacement de la box est possible on doit changer box avec la cell où elle atterit
{
	cout << "ici" << endl;
	cout << wishedDepl.x << " " << wishedDepl.y << endl;
	if (board->getCell(wishedDepl)->getCanBeMoved())  // si elle peut pas être bougé vérifier que derrière elle s'est possible aussi
	{
		wishedDepl.x += senseMovement.x;  // on verifie la case derrière la box qu'on veut bouger
		wishedDepl.y += senseMovement.y;
		cout << "ici" << endl;
		if (isInBoard(2) && board->getCell(wishedDepl)->getMoveInside())
		{
			cout << "changement des coordonnées" << endl;
			board->getCell(wishedDepl)->setPos({wishedDepl.x*60+100, wishedDepl.y*60+100});
			wishedDepl.x -= senseMovement.x; 						// reset du mouvement
			wishedDepl.y -= senseMovement.y;
			board->getCell(wishedDepl)->setPos({wishedDepl.x*60+100, wishedDepl.y*60+100});
			cout << "fin des changements des coordonnées" << endl;
			return true;
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
    wishedDepl.x = currentPos.x + senseMovement.x;
    wishedDepl.y = currentPos.y + senseMovement.y;
}


void Move::setCurrentPos(Point playerPos)
{
	currentPos = playerPos;
}


void Move::setKeyDepl(int key) 
{
	keyDepl = key;
}
