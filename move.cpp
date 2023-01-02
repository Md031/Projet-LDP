
#include "move.hpp"
#include "cell.hpp"
#include <iostream>
using namespace std;

Move::Move(Board *board, vector<Target*> targetGoal) 
	: board{board}, targetGoal{targetGoal} {} //tpVector = board->getTpVector(); }


Move::Move() {}


bool Move::checkMove(Point posPlayer, Point senseMovement)  // faire tous les if
{
	posPlayer += senseMovement;
	if (!isInBoard(posPlayer)) return false;
	if (!canItMove(posPlayer, senseMovement)) return false;
	if (!(board->getCell(posPlayer)->getMoveInside())) return false;
	if (board->getTargetCount() == 0) return false;
	return true;
}


bool Move::isInBoard(Point posPlayer)
{
	// si il est inférieur à 0 ou supérieur à la taille du vecteur on n'autorise pas le déplacement
	if (posPlayer.x < 0) return false;
	if (posPlayer.y < 0) return false;
	if (posPlayer.x >= board->getSize().x) return false;
	if (posPlayer.y >= board->getSize().y) return false;
	return true;
}


bool Move::canItMove(Point posPlayer, Point senseMovement)  // si le déplacement de la box est possible on doit changer box avec la cell où elle atterit
{
	if (!board->getCell(posPlayer)->getCanBeMoved()) return true;  // si on peut bouger et que c'est pas une box où on atterit
	return moveBox(posPlayer, senseMovement);  // si on passe le if c'est qu'on arrive sur une box
}


bool Move::moveBox(Point wishedDepl, Point senseMovement)
{
	wishedDepl.x += senseMovement.x;  // on verifie la case derrière la box qu'on veut bouger
	wishedDepl.y += senseMovement.y;
	if (isInBoard(wishedDepl) && board->getCell(wishedDepl)->getMoveInside())
	{
		Point temp = Point{wishedDepl.x - senseMovement.x, wishedDepl.y - senseMovement.y};
		for (auto &c: targetGoal)  // on vérifie si on ne ramène pas la box sur une target
		{
			if (temp.comparePoint(c->getPos()))  // si la box arrive sur une target on la cache
			{
				if(c->getFullness())
				{ 
					c->reverseFullness();
					board->updateTargetCount(+1);
				}
			}
			else if (wishedDepl.comparePoint(c->getPos()))  // si la box arrive sur une target on la cache
			{
				c->reverseFullness();
				board->updateTargetCount(-1);
			}
		}
		Cell *tempCell = board->getCell(wishedDepl);
		Cell *tempBox = board->getCell({wishedDepl.x - senseMovement.x, wishedDepl.y - senseMovement.y});
		board->setCell(wishedDepl, tempBox);
		tempBox->setPos(wishedDepl);
		wishedDepl.x -= senseMovement.x;  // reset du mouvement
		wishedDepl.y -= senseMovement.y;
		board->setCell(wishedDepl, tempCell);
		tempCell->setPos(wishedDepl);
		return true;
	}
	else
	{
		wishedDepl.x -= senseMovement.x; // reset du mouvement
		wishedDepl.y -= senseMovement.y;
	}
	return false;
}