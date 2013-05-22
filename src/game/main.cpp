//Include Qt libraries
#include <QtCore/QCoreApplication>
#include <QtCore/QThread>
#include <QtCore/QTime>
#include <QDebug>

//Include Allegro5 libraries
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "Globals.h"

bool keys[255] = {false};

ALLEGRO_MOUSE_EVENT mouse;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_FONT *listFont;
ALLEGRO_FONT *playerFont;

void draw();
void update();

int main(int argc, char *argv[])
{
    //Allegro Setup
    if(!al_init())
    {
        qDebug() << "Allegro Init is failing!";
        return -1;
    }

    QCoreApplication app(argc, argv);
    app.setApplicationName("Crispy Goldfish");

    qDebug() << "Welcome";

    //primitive variable
    bool redraw = true;
    const int FPS = 60;

    //Allegro variables

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    display = al_create_display(ScreenWidth, ScreenHeight);
    al_set_window_title(display, "Crispy Goldfish");

    //Check if we have a valid display
    if(!display)
    {
        qDebug() << "Display is failing!";
        return -1;
    }

    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    return app.exec();
}

void draw()
{

}

void update()
{

}
