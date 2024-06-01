
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
    Locked m_layer2;
public:
    Cell();
    Cell(Object layer1, Locked layer2) :
            m_layer1(layer1), m_layer2(layer2) {

    }

    bool canUnlockCell(const Player &player) const;
    bool isLocked() const;
    void unlockCell(Player &player);
    void drawCell(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void changeLightLevel(int lightLevel);

};

#endif //LIGHTSED_CELL_H
