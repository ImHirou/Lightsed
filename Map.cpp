#include "Map.h"
#include "Cell.h"
#include "BaseObject.h"
#include "Light.h"
#include "constants.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <iostream>

Map::Map() : m_player(Player(17, 25, 1000000)), m_tps(20) {
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            auto layer1 = std::make_unique<BaseObject>(BaseObject::typeByChar(Constants::mapLayer1[i][j]));
            auto layer2 = std::make_unique<Locked>(BaseObject::typeByChar(Constants::mapLayer2[i][j]));
            m_cells[i][j] = Cell(std::move(layer1), std::move(layer2));
        }
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

Player& Map::getPlayer() { return m_player; }
int Map::getTPS() const { return m_tps; }

void Map::drawEmptyCell(sf::RenderWindow &window, int x, int y, sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setString("#");
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(x*Constants::characterSize, y*Constants::characterSize);
    text.setColor(sf::Color(7, 7, 7));
    window.draw(text);
}

void Map::draw(sf::RenderWindow &window, sf::Font &font) {
    int x = m_player.getX();
    int y = m_player.getY();
    for(int i = x-15; i < x+15; ++i) {
        for(int j = y-15; j < y+15; ++j) {
            if(i == x && j == y) {
                m_player.draw(window, 0+(i-(x-15)), 0+(j-(y-15)), font);
            }
            else if(i >= 0 && i < 50 && j >=0 && j<50) {
                m_cells[i][j].drawCell(window, 0+(i-(x-15)), 0+(j-(y-15)), font);
            } else {
                drawEmptyCell(window, 0+(i-(x-15)), 0+(j-(y-15)), font);
            }
        }
    }
}

void Map::movePlayer() {
    if(m_player.isKeyPressed(Player::Key_W)) {
        if(m_player.getY()-1 >= 0 && m_player.getY()-1 < 50) m_player.moveBy(0, -1, m_cells[m_player.getX()][m_player.getY()-1]);
    }
    if(m_player.isKeyPressed(Player::Key_A)) {
        if(m_player.getX()-1 >= 0 && m_player.getX()-1 < 50) m_player.moveBy(-1, 0, m_cells[m_player.getX()-1][m_player.getY()]);
    }
    if(m_player.isKeyPressed(Player::Key_S)) {
        if(m_player.getY()+1 >= 0 && m_player.getY()+1 < 50) m_player.moveBy(0, 1, m_cells[m_player.getX()][m_player.getY()+1]);
    }
    if(m_player.isKeyPressed(Player::Key_D)) {
        if(m_player.getX()+1 >= 0 && m_player.getX()+1 < 50) m_player.moveBy(1, 0, m_cells[m_player.getX()+1][m_player.getY()]);
    }
}

void Map::tick() {
    int lightLevel = log2(m_player.getLight());
    for(int i=0; i<50; ++i) {
        for(int j=0; j<50; ++j) {
            m_cells[i][j].changeLightLevel(lightLevel - distance(i, j, m_player.getX(), m_player.getY()) + 5);
            if(!m_cells[i][j].isLocked())
                if(rand() % 10000 <= 1) m_cells[i][j].makeLight();
        }
    }
}
