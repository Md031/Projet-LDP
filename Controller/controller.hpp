
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../Model/board.hpp"
#include "../View/view.hpp"

class MainWindow;

class Controller
{
private:
	Board* board;
	MainWindow* view;
	string currentLevel = "Model/Levels/Level 0.txt";
	string directory = "Model/Levels/Level ";
	string output = ".txt";
public:
	Controller();
	~Controller();
	int handler(int key);
	void drawBoard();
	void resetBoard();
	void setView(MainWindow* newView);
};

#endif