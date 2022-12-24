
// These should include everything you might use
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <math.h>
#include <time.h>
#include <chrono>
#include <random>

#include <iostream>

#include "board.hpp"


const int windowWidth = Fl::w();
const int windowHeight = Fl::h();
const double refreshPerSecond = 60;

// DO NOT EDIT HERE !!!!
class MainWindow : public Fl_Window 
{
private:
    string currentLevel = "Levels/Level 0.txt";
    string directory = "Levels/Level ";
    string output = ".txt";
    Board *board = new Board(currentLevel);
public:
    MainWindow() : Fl_Window(500, 225, windowWidth, windowHeight, "Sokoban") 
    {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
    }
    void draw() override 
    {
        Fl_Window::draw();
        board->draw();
    }
    int handle(int event) override 
    {
        switch (event) 
        {
            case FL_MOVE:
                //mouseMove(Fl::event_x(),Fl::event_y());
                return 1;
            case FL_KEYDOWN:
                if (((int)'0' + FL_KP <=  Fl::event_key()) && ( Fl::event_key() <= (int)'9' + FL_KP))  // changement de level
                {
                    currentLevel = directory + (char)(Fl::event_key() - FL_KP) + output;
                    delete board; board = nullptr;
                    board = new Board{currentLevel};
                    board->draw();
                }
                else if (Fl::event_key() == ' ')  // reset level
                {
                    delete board; board = nullptr;
                    board = new Board{currentLevel};
                    board->draw();
                }
                else if (Fl::event_key() == 'q') exit(0);  // pour fermer le jeu
                else
                {
                    board->keyPressed(Fl::event_key());
                }          
        }
        return 0;
    }
    static void Timer_CB(void *userdata) 
    {
        MainWindow *o = (MainWindow*) userdata;
        o->redraw();
        Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
    }
    ~MainWindow() { delete board; }    
};

int main(int argc, char *argv[]) 
{
    MainWindow window;
    window.show(argc, argv);
    return Fl::run();
}
