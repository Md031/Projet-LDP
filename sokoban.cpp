
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

#include "board.hpp"


// DO NOT EDIT HERE !!!!
class MainWindow : public Fl_Window 
{
private:
    string windowName;
    const int windowWidth;
    const int windowHeight;
    static constexpr double refreshPerSecond = 60;
    string currentLevel = "Levels/Level 0.txt";
    string directory = "Levels/Level ";
    string output = ".txt";
    Board *board = new Board(currentLevel);
public:
    MainWindow(string windowName, const int windowWidth = Fl::w(), const int windowHeight = Fl::h()) 
        : Fl_Window(500, 225, windowWidth, windowHeight, windowName.c_str()), windowName{windowName}, windowWidth{windowWidth}, windowHeight{windowHeight}  // 500, 225 de base 
    {
        Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
        resizable(this);
    }
    void draw() override 
    {
        Fl_Window::draw();
        if (windowName == "Sokoban") board->draw();
        else  // pour le splashScreen
        {
            fl_font(FL_HELVETICA,30);
            fl_color(fl_rgb_color(0,0,0));
            fl_draw("Welcome to Sokoban\n Made by Ziauddin Md and Benjana Moaad",0,0,675,450,FL_ALIGN_CENTER,nullptr,false);
        }
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
                else if (Fl::event_key() == FL_Up || Fl::event_key() == FL_Down || Fl::event_key() == FL_Right 
                        || Fl::event_key() == FL_Left || Fl::event_key() == 't')  // le 't' c'est pour les téléportations
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


void closeInstances(Fl_Widget* widget, void* userdata)  // fonction qui sera appelé à la fermeture de la window pour assurer les delete
{
    MainWindow* window = (MainWindow*)widget;
    delete window;
}


void deleteSplashScreen(void* data) {
    MainWindow* splashScreen = (MainWindow*)(data);
    splashScreen->hide();
    delete splashScreen;
    MainWindow* window = new MainWindow{"Sokoban"};
    window->show();
    window->callback((Fl_Callback*)closeInstances);  // pour delete les new à la fermeture de la window
}


int main(int argc, char *argv[]) 
{
    MainWindow* splashScreen = new MainWindow{"SplashScreen", 700,500};
    splashScreen->show(argc, argv);
    Fl::add_timeout(3.0, deleteSplashScreen, static_cast<void*>(splashScreen));
    return Fl::run();
}

