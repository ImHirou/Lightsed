#ifndef LIGHTSED_PLAYER_H
#define LIGHTSED_PLAYER_H

#include "Cell.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class Player : public BaseObject{
public:
    enum Key {
        Key_W,
        Key_A,
        Key_S,
        Key_D,
        TOTAL_KEYS
    };
private:
    long long m_light;
    int m_x;
    int m_y;
    bool m_keyPressed[TOTAL_KEYS] {};
public:
    Player(int x=0, int y=0, long long light=0) :
            BaseObject(PLAYER), m_x(x), m_y(y), m_light(light) {
        for(int i = 0; i < static_cast<int>(TOTAL_KEYS); ++i) m_keyPressed[static_cast<Key>(i)] = false;
    }

    int getX() const;
    int getY() const;
    long long getLight() const;

    void reduceLight(long long n);

    void setKey(Key key, bool p);

    void draw(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void moveBy(int x, int y, Cell &cell);
    bool isKeyPressed(Key key) const;

};

#endif //LIGHTSED_PLAYER_H
