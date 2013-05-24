#include "button.h"

Button::Button()
{

}

Button::Button(int x, int y, int width, int height, ALLEGRO_FONT *buttonFont, ALLEGRO_COLOR inactiveColor, ALLEGRO_COLOR activeColor, ALLEGRO_COLOR textColor, ALLEGRO_COLOR borderColor, QString title, int value)
{
    setRectangle(x, y, width, height);

    setTitle(title);

    setColors(inactiveColor, activeColor, textColor, borderColor);

    setValue(value);

    m_buttonFont = buttonFont;

    if (!m_buttonFont){
        qDebug() << "Could not load font";
    }
    qDebug() << "Created Button";
    this->m_prevClick = 0;
}

//Setters
void Button::setRectangle(int x, int y, int width, int height)
{
    this->m_xPosition = x;
    this->m_yPosition = y;

    this->m_buttonWidth = width;
    this->m_buttonHeight = height;
}

void Button::setValue(int value)
{
    this->m_value = value;
}

void Button::setTitle(QString title)
{
    this->m_title = title;
}

void Button::setColors(ALLEGRO_COLOR inactiveColor, ALLEGRO_COLOR activeColor, ALLEGRO_COLOR textColor, ALLEGRO_COLOR borderColor)
{
    this->m_inactiveColor = inactiveColor;
    this->m_activeColor = activeColor;
    this->m_textColor = textColor;
    this->m_borderColor = borderColor;
}

void Button::toggleActive()
{
    this->m_isActive = !this->m_isActive;
}

void Button::setActive(bool isActive)
{
    this->m_isActive = isActive;
}

int Button::getValue()
{
    return this->m_value;
}

void Button::Draw()
{
    al_draw_rectangle(m_xPosition, m_yPosition, m_xPosition + m_buttonWidth, m_yPosition + m_buttonHeight, m_borderColor, 2);


    int text_x = m_xPosition + (m_buttonWidth / 2);
    int text_y = m_yPosition + (m_buttonHeight / 2) - 10;

    al_draw_text(m_buttonFont, m_borderColor, text_x, text_y, ALLEGRO_ALIGN_CENTER, m_title.toLocal8Bit().data());
}

//update returns if clicked
bool Button::Update(ALLEGRO_MOUSE_STATE *mouse)
{
    m_isActive = false;

    if(mouse->x > m_xPosition && mouse->x < m_yPosition + m_buttonWidth)
    {
        if(mouse->y > m_yPosition && mouse->y < m_yPosition + m_buttonHeight)
        {
            m_isActive = true;

            if(al_mouse_button_down(mouse, 1))
            {
                if(m_prevClick == 1)
                {
                    m_prevClick = 2;
                    return true;
                }
            } else
            {
                m_prevClick = 1;
            }
        }
    }

    return false;
}
