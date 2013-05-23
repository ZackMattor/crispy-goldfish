#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "button.h"

#include <QtCore/QString>
#include <QList>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

class GameMenu
{
public:
    GameMenu();

    void Draw();
    int Update(bool *keys, ALLEGRO_MOUSE_EVENT *mouse);
private:
    QList<Button*> m_buttons;
};

#endif // GAME_MENU_H
