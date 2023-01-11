
#include "view.hpp"

MainWindow::MainWindow(string windowName, const int windowWidth, const int windowHeight) 
        : Fl_Window(500, 225, windowWidth, windowHeight, windowName.c_str()), windowName{windowName}, windowWidth{windowWidth}, windowHeight{windowHeight}
{
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    resizable(this);
}


MainWindow::~MainWindow() { delete controller; }


void MainWindow::draw() 
{
    Fl_Window::draw();
    if (windowName == "Sokoban") controller->drawBoard();
    else  // pour le splashScreen
    {
        fl_font(FL_HELVETICA,30);
        fl_color(fl_rgb_color(0,0,0));
        fl_draw("Welcome to Sokoban\n Made by Ziauddin Md and Benjana Moaad",0,0,675,450,FL_ALIGN_CENTER,nullptr,false);
    }
}


void MainWindow::Timer_CB(void *userdata) 
{
    MainWindow *o = (MainWindow*) userdata;
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
}

int MainWindow::handle(int key) 
{ 
    controller->handler(key);
    return 0;
}


void MainWindow::setController(Controller* newController) { controller = newController; }
