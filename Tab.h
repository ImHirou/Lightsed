#ifndef LIGHTSED_TAB_H
#define LIGHTSED_TAB_H

#include "Upgrades.h"

class Tab {
private:
    std::string m_title;
    Button **m_buttons;
    Point m_pos1;
    Point m_pos2;
    bool m_open;
public:
    Tab(const Point &pos1, const Point &pos2, const std::string& title) : m_pos1(pos1), m_pos2(pos2), m_title(title), m_open(false) {
        m_buttons = new Button*[1];
        m_buttons[0] = new UpgradeButton(100+pos1.getX(), 100+pos1.getY(), 400+pos1.getX(), 200+pos1.getY(), "Hellow", 100, 2, UpgradeFunc1);
    }

    virtual ~Tab() {
        delete m_buttons[0];
        delete[] m_buttons;
    }

    Button** getButtons();
    Point& getPos1();
    Point& getPos2();
    bool isOpen() const;

    void setOpen(bool o);

    void draw(sf::RenderWindow &window, sf::Font &font);
    void checkHover(int x, int y);

};

#endif //LIGHTSED_TAB_H
