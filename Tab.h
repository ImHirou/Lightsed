#ifndef LIGHTSED_TAB_H
#define LIGHTSED_TAB_H

#include "Upgrades.h"

class Tab {
private:
    std::string m_title;
    Button **m_buttons;
    Point m_pos1;
    Point m_pos2;
    int m_totalButtons;
    bool m_open;
public:
    Tab(Point& pos1, Point& pos2, const std::string& title, BaseObject::ObjectType type=BaseObject::EMPTY) :
        m_pos1(pos1), m_pos2(pos2), m_title(title), m_open(false), m_totalButtons(buttonsNumByType(type)) {
        initButtonsByType(type);
    }
    Tab(int x1, int y1, int x2, int y2, const std::string& title, BaseObject::ObjectType type=BaseObject::EMPTY) :
        m_pos1(x1, y1), m_pos2(x2, y2), m_title(title), m_open(false), m_totalButtons(buttonsNumByType(type)) {
        initButtonsByType(type);
    }

    virtual ~Tab() {
        for(int i=0; i<m_totalButtons; i++) delete m_buttons[i];
        delete[] m_buttons;
    }

    Button** getButtons();
    int getButtonsNum() const;
    Point& getPos1();
    Point& getPos2();
    bool isOpen() const;

    static int buttonsNumByType(BaseObject::ObjectType type);
    void initButtonsByType(BaseObject::ObjectType type);

    void setOpen(bool o);

    void draw(sf::RenderWindow &window, sf::Font &font);
    void checkHover(int x, int y);

};

#endif //LIGHTSED_TAB_H
