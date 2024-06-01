#ifndef LIGHTSED_MAP_H
#define LIGHTSED_MAP_H

#include "Cell.h"
#include "Player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

class Map {
private:
    Cell m_cells[50][50];
    Player m_player;
    int m_tps;
public:
    Map();

    Player& getPlayer();
    int getTPS() const;

    void draw(sf::RenderWindow &window, sf::Font &font);
    void drawEmptyCell(sf::RenderWindow &window, int x, int y, sf::Font &font);
    void movePlayer();
    void tick();

};

#endif //LIGHTSED_MAP_H
