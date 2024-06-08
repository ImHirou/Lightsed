#ifndef LIGHTSED_CELL_H
#define LIGHTSED_CELL_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include "Locked.h"

class Player;

class Cell {
private:
    std::unique_ptr<BaseObject> m_layer1;
    std::unique_ptr<BaseObject> m_layer2;
public:
    Cell();
    Cell(std::unique_ptr<BaseObject> layer1, std::unique_ptr<BaseObject> layer2) :
            m_layer1(std::move(layer1)), m_layer2(std::move(layer2)) {
    }

    BaseObject* getLayer1();
    BaseObject* getLayer2();
    bool canUnlockCell(const Player &player);
    bool isLocked() const;
    bool isLight() const;
    bool isBuilding() const;
    bool isMoreThan(BaseObject::ObjectType type) const;
    void unlockCell(Player &player);
    void drawCell(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void changeLightLevel(int lightLevel);
    void makeEmpty();
    void makeLight();

};

#endif //LIGHTSED_CELL_H
