
#include "controller.hpp"

class MainWindow;
class Board;

Controller::Controller() { board = new Board(); }


void Controller::setView(MainWindow* newView) { view = newView; }


Controller::~Controller()
{
	delete board;
	delete view;
}

int Controller::handler(int key)
{
	switch (key) 
    {
        case FL_MOVE:  // pour le déplacement à la souris
        	//mouseMove(Fl::event_x(),Fl::event_y());
            return 1;
        case FL_KEYDOWN:
            if (((int)'0' + FL_KP <=  Fl::event_key()) && ( Fl::event_key() <= (int)'9' + FL_KP))  // changement de level
            {
                currentLevel = directory + (char)(Fl::event_key() - FL_KP) + output;
                resetBoard();
            }
            else if (Fl::event_key() == ' ') resetBoard();  // reset level
            else if (Fl::event_key() == 'q') exit(0);  // pour fermer le jeu
            else if (Fl::event_key() == FL_Up || Fl::event_key() == FL_Down || Fl::event_key() == FL_Right 
                    || Fl::event_key() == FL_Left || Fl::event_key() == 't')  // le 't' c'est pour les téléportations
            { 
                board->keyPressed(Fl::event_key()); 
            }
            else if (Fl::event_key() == 'r')  // pour reset le best score du level
            {
                board->resetBestScore();
                resetBoard();
            }
    }
    return 0;
}


void Controller::resetBoard()
{
    delete board; board = nullptr;
    board = new Board{currentLevel};
    board->draw();
}


void Controller::drawBoard() { board->draw(); }