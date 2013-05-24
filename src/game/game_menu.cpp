#include "game_menu.h"

GameMenu::GameMenu()
{
    ALLEGRO_FONT *menuFont = al_load_ttf_font("../arial.ttf", 20, 0);
    m_buttons << new Button(100, 5, 200, 50, menuFont, al_color_html("#cccccc"), al_color_html("#222222"), al_color_html("#222222"), al_color_html("#222222"), "Game", GAME);
    m_buttons << new Button(100, 100, 200, 50, menuFont, al_color_html("#cccccc"), al_color_html("#222222"), al_color_html("#222222"), al_color_html("#222222"), "Testing", TESTING);
    m_buttons << new Button(100, 200, 200, 50, menuFont, al_color_html("#cccccc"), al_color_html("#222222"), al_color_html("#222222"), al_color_html("#222222"), "Exit", CLOSE);
    qDebug() << "GameMenu Init";
}

void GameMenu::Draw()
{
    foreach(Button *button, m_buttons)
    {
        button->Draw();
    }
}

int GameMenu::Update(bool *keys, ALLEGRO_MOUSE_STATE *mouse)
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
