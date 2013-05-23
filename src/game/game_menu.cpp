#include "game_menu.h"

GameMenu::GameMenu()
{
    ALLEGRO_FONT *menuFont = al_load_font("arial.ttf", 20, 0);
    m_buttons << new Button(5, 5, 200, 200, menuFont, al_color_html("#cccccc"), al_color_html("#222222"), al_color_html("#222222"), al_color_html("#222222"), "Hello", 0);
    qDebug() << "GameMenu Init";
}

void GameMenu::Draw()
{
    foreach(Button *button, m_buttons)
    {
        button->Draw();
    }
}

int GameMenu::Update(bool *keys, ALLEGRO_MOUSE_EVENT *mouse)
{
    foreach(Button *button, m_buttons)
    {
        if(button->Update(mouse))
        {
            return button->getValue();
        }
    }

    return -1;
}
