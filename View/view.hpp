
#ifndef VIEW_HPP
#define VIEW_HPP

// These should include everything you might use
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <random>
#include <unistd.h>
#include <iostream>
#include "../Controller/controller.hpp"

using namespace std;

class Controller;

class MainWindow : public Fl_Window 
{
private:
    string windowName;
    const int windowWidth;
    const int windowHeight;
    static constexpr double refreshPerSecond = 60;
    Controller* controller;
public:
	MainWindow(string windowName, const int windowWidth = Fl::w(), const int windowHeight = Fl::h());
	virtual ~MainWindow();
	virtual void draw();
	virtual int handle(int key);
	static void Timer_CB(void *userdata);
    void setController(Controller* newController);
};

#endif