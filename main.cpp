
#include "./View/view.hpp"
#include "Controller/controller.hpp"


void closeInstances(Fl_Widget* widget, void* userdata)  // fonction qui sera appelé à la fermeture de la window pour assurer les delete
{
    MainWindow* window = (MainWindow*)widget;
    Controller* controller = (Controller*)widget;
    delete window;
    delete controller;
}


void deleteSplashScreen(void* data) 
{
    MainWindow* splashScreen = (MainWindow*)(data);
    splashScreen->hide();
    delete splashScreen;
    MainWindow* window = new MainWindow{"Sokoban"};
    Controller* controller = new Controller();
    controller->setView(window);
    window->setController(controller);
    window->show();
    window->callback((Fl_Callback*)closeInstances);  // pour delete les new à la fermeture de la window
}


int main(int argc, char *argv[])
{
    MainWindow* splashScreen = new MainWindow{"SplashScreen", 700,500};
    splashScreen->show(argc, argv);
    Fl::add_timeout(2.0, deleteSplashScreen, static_cast<void*>(splashScreen));  // on delete le splashScreen et on affiche la window du jeu
    return Fl::run();
}
