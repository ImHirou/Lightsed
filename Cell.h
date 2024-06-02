
#ifndef LIGHTSED_CELL_H
#define LIGHTSED_CELL_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Object.h"
#include "Locked.h"
#include "SFML/Graphics/Font.hpp"

class Player;

class Cell {
private:
    Object m_layer1;
    Object m_layer2;
public:
    Cell();
    Cell(Object layer1, Object layer2) :
            m_layer1(layer1), m_layer2(layer2) {
    }

    bool canUnlockCell(const Player &player);
    bool isLocked() const;
    bool isLight() const;
    void unlockCell(Player &player);
    void drawCell(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void changeLightLevel(int lightLevel);
    void makeEmpty();

};

#endif //LIGHTSED_CELL_H
