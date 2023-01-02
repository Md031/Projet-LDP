
#include "move.hpp"
#include "cell.hpp"
#include <iostream>
using namespace std;

Move::Move(Board *board, vector<Target*> targetGoal)  : board{board}, targetGoal{targetGoal} 
{ 
	tpVector = board->getTpVector(); 
}


Move::Move() {}


bool Move::checkMove(Point &posPlayer, Point senseMovement)
{
	Point newPos = posPlayer + senseMovement;
	if (!isInBoard(newPos)) return false;
	if (!canItMove(newPos, senseMovement)) return false;
	if (checkTp(posPlayer, newPos)) return true;  // si la case d'arrivé c'est une tp on tp le player
	if (!(board->getCell(newPos)->getMoveInside())) return false;
	if (board->getTargetCount() == 0) return false;
	posPlayer = newPos;
	return true;
}


bool Move::isInBoard(Point testPos)
{
	// si il est inférieur à 0 ou supérieur à la taille du vecteur on n'autorise pas le déplacement car il n'est pas dans le board
	if (testPos.x < 0) return false;
	if (testPos.y < 0) return false;
	if (testPos.x >= board->getSize().x) return false;
	if (testPos.y >= board->getSize().y) return false;
	return true;
}


bool Move::canItMove(Point testPos, Point senseMovement)  // si le déplacement de la box est possible on doit changer box avec la cell où elle atterit
{
	if (!board->getCell(testPos)->getCanBeMoved()) return true;  // si on peut bouger et que c'est pas une box où on atterit
	return moveBox(testPos, senseMovement);  // si on passe le if c'est qu'on arrive sur une box
}


bool Move::moveBox(Point wishedDepl, Point senseMovement)
{
	wishedDepl += senseMovement;	// on verifie la case derrière la box qu'on veut bouger
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
		wishedDepl -= senseMovement;  // reset du mouvement
		board->setCell(wishedDepl, tempCell);
		tempCell->setPos(wishedDepl);
		return true;
	}
	else wishedDepl -= senseMovement;  // reset du mouvement
	return false;
}


bool Move::checkTp(Point &posPlayer, Point &newPos)
{
	Point tpUn = tpVector.at(0)->getPos();
	Point tpDeux = tpVector.at(1)->getPos();
	if (newPos == tpUn)  // on check que sur la case de tp d'arrivé y a pas de box
	{
		posPlayer.x = tpDeux.x;
		posPlayer.y = tpDeux.y;
		return true;
	}
	else if (newPos == tpDeux)
	{
		posPlayer.x = tpUn.x;
		posPlayer.y = tpUn.y;
		return true;
	}
	return false;
}