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
        Key_SHIFT,
        Key_CTRL,
        TOTAL_KEYS
    };
private:
    Automator m_automator;
    Key m_lastKeyPressed;
    long long m_light;
    long long m_multi;
    int m_lightChance;
    int m_x;
    int m_y;
    bool m_NXBoost;
    bool m_keyPressed[TOTAL_KEYS] {};
    bool m_ctrlUnlocked;
    bool m_shiftUnlocked;
public:
    Player(int x=0, int y=0, long long light=0) :
            BaseObject(PLAYER), m_x(x), m_y(y), m_light(light), m_multi(1), m_lightChance(1), m_automator(), m_NXBoost(false), m_shiftUnlocked(false), m_ctrlUnlocked(false) {
        for(int i = 0; i < static_cast<int>(TOTAL_KEYS); ++i) m_keyPressed[static_cast<Key>(i)] = false;
    }

    bool isNXBoost() const;
    bool isCTRLUnlocked() const;
    bool isShiftUnlocked() const;
    int getX() const;
    int getY() const;
    int getLightChance() const;
    long long getLight() const;
    long long getMulti() const;
    Key getLastKeyPressed() const;
    Automator& getAutomator();

    void reduceLight(long long n);
    void addLight(long long n);
    void addMulti(long long n);
    void setNXBoost(bool tb);
    void collectLight(int x, int y, Cell &cell);

    void unlockCTRL();
    void unlockShift();

    void setKey(Key key, bool p);
    void setLastKeyPressed(Key key);
    void setMulti(long long mult);
    void setLightChance(int c);

    void draw(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void moveBy(int x, int y, Cell &cell);
    bool isKeyPressed(Key key) const;

};

#endif //LIGHTSED_PLAYER_H
