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
    Button(int x, int y, int width, int height);

    void setRectangle(int x, int y, int width, int height);
    void setValue(int value);
    void setTitle(QString title);

    //Action Methods
    void Draw();

    //update returns value, if clicked
    bool Update(ALLEGRO_MOUSE_EVENT *mouse);
private:
    //Class Variables
    int m_xPosition;
    int m_yPosition;
    int m_buttonHeight;
    int m_buttonWidth;

    QString m_title;

    ALLEGRO_FONT *m_buttonFont;
    ALLEGRO_COLOR m_inactiveColor, m_activeColor, m_textColor, m_borderColor;
};

#endif // BUTTON_H