#ifndef BUTTON_H
#define BUTTON_H

#include <QtCore/QString>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

class Button
{
public:
    Button();
    Button(int x, int y, int width, int height, ALLEGRO_FONT *buttonFont, ALLEGRO_COLOR inactiveColor, ALLEGRO_COLOR activeColor, QString title);

    //Setters
    void setRectangle(int x, int y, int width, int height);
    void setValue(int value);
    void setTitle(QString title);
    void setColors(ALLEGRO_COLOR inactiveColor, ALLEGRO_COLOR activeColor, ALLEGRO_COLOR m_textColor, ALLEGRO_COLOR m_borderColor);

    void toggleActive();
    void setActive(bool isActive);


    //Getters


    //Action Methods
    void Draw();

    //update returns if clicked
    bool Update(ALLEGRO_MOUSE_EVENT *mouse);
private:
    //Class Variables
    int m_xPosition;
    int m_yPosition;
    int m_buttonHeight;
    int m_buttonWidth;
    bool m_isActive = false;
    QString m_title;

    ALLEGRO_FONT *m_buttonFont;
    ALLEGRO_COLOR m_inactiveColor, m_activeColor, m_textColor, m_borderColor;
};

#endif // BUTTON_H
