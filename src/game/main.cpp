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

int gameState = LOADING;

ALLEGRO_MOUSE_EVENT mouse;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_FONT *listFont;
ALLEGRO_FONT *playerFont;

//Main function declarations
void Draw();
void Update();

int main(int argc, char *argv[])
{
    //Init Allegro
    if(!al_init())
    {
        qDebug() << "Allegro Init is failing!";
        return -1;
    }

    //Init Qt
    QCoreApplication app(argc, argv);
    app.setApplicationName("Crispy Goldfish");

    qDebug() << "Welcome";

    //primitive variable
    bool redraw = true;
    const int FPS = 60;

    //Allegro variables
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    //Set up allegro
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    display = al_create_display(ScreenWidth, ScreenHeight);
    al_set_window_title(display, "Crispy Goldfish");

    //Check if we have a valid display
    if(!display)
    {
        qDebug() << "Display is failing!";
        return -1;
    }

    //Init allegro libraries
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);
    qsrand(QTime::currentTime().msec());

    //Load up the fonts
   // listFont = al_load_font(tifax.toLocal8Bit().data(), 20, 0);
    //playerFont = al_load_font(arial.toLocal8Bit().data(), 12, 0);

    //Load the static pages
    //serverList = new ServerList(listFont);
    //aboutPage = new AboutPage(listFont);

    //Register all of the allegro events into the queue
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_keyboard_event_source());
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_mouse_event_source());
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_timer_event_source(timer));
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)al_get_display_event_source(display));
    al_register_event_source(event_queue, (ALLEGRO_EVENT_SOURCE*)display);

    //Starts up out timer which will tick in the event loop and run our update function
    al_start_timer(timer);

    //Main game loop!
    while(gameState != CLOSE)
    {
        QCoreApplication::processEvents();
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        switch(ev.type)
        {
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                Update();
            break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                gameState = CLOSE;
            break;

            case ALLEGRO_EVENT_KEY_DOWN:
                keys[ev.keyboard.keycode] = true;
            break;

            case ALLEGRO_EVENT_KEY_UP:
                keys[ev.keyboard.keycode] = false;
            break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            case ALLEGRO_EVENT_MOUSE_AXES:
                mouse = ev.mouse;
            break;
        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            //cout << "Drawing";
            redraw = false;
            Draw();

            //FLIP BUFFERS
            al_flip_display();

            if(gameState != GAME) //game takes care of it's own background
            {
                if(background != NULL)
                {
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(background, 0, 0, 0);
                }
                else
                {
                    al_clear_to_color(al_map_rgb(0, 191, 255));
                }
            }
        }
    }

    //Stops all sounds
    //soundPlayer->stopAll();

    return 1;

    return app.exec();
}

void Draw()
{
    qDebug() << "Draw";
}

void Update()
{
   qDebug() << "Tick";
}
