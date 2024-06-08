#ifndef LIGHTSED_PLAYER_H
#define LIGHTSED_PLAYER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Cell.h"
#include "Automator.h"

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
    Automator m_automator;
    long long m_light;
    long long m_multi;
    int m_lightChance;
    int m_x;
    int m_y;
    bool m_keyPressed[TOTAL_KEYS] {};
public:
    Player(int x=0, int y=0, long long light=0) :
            BaseObject(PLAYER), m_x(x), m_y(y), m_light(light), m_multi(1), m_lightChance(1), m_automator() {
        for(int i = 0; i < static_cast<int>(TOTAL_KEYS); ++i) m_keyPressed[static_cast<Key>(i)] = false;
    }

    int getX() const;
    int getY() const;
    int getLightChance() const;
    long long getLight() const;
    long long getMulti() const;
    Automator& getAutomator();

    void reduceLight(long long n);
    void addLight(long long n);
    void addMulti(long long n);

    void setKey(Key key, bool p);
    void setMulti(long long mult);
    void setLightChance(int c);

    void draw(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void moveBy(int x, int y, Cell &cell);
    bool isKeyPressed(Key key) const;

};

#endif //LIGHTSED_PLAYER_H
