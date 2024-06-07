#ifndef LIGHTSED_TAB_H
#define LIGHTSED_TAB_H

#include "Button.h"

class Tab {
private:
    std::string m_title;
    Button *m_buttons;
    Point m_pos1;
    Point m_pos2;
public:
    Tab(const Point &pos1, const Point &pos2, const std::string& title) : m_pos1(pos1), m_pos2(pos2), m_title(title) {
        m_buttons = new Button[1];
        m_buttons[0] = Button(100, 100, 400, 200, "Hellow");
    }

    virtual ~Tab() {
        delete[] m_buttons;
    }

    Button* getButtons();
    Point& getPos1();
    Point& getPos2();

    void draw(sf::RenderWindow &window, sf::Font &font);

};

#endif //LIGHTSED_TAB_H
