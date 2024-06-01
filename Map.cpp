#include "Map.h"
#include "Cell.h"
#include "Object.h"
#include "constants.h"
#include "SFML/Graphics.hpp"
#include <iostream>

Map::Map() : m_player(Player(17, 25, 100000)), m_tps(20) {
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            m_cells[i][j] = Cell(Object(Object::typeByChar(Constants::mapLayer1[i][j])), Locked(Object::typeByChar(Constants::mapLayer2[i][j])));
        }
    }
}

Player& Map::getPlayer() { return m_player; }
int Map::getTPS() const { return m_tps; }

void Map::drawEmptyCell(sf::RenderWindow &window, int x, int y, sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setString("#");
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(x*Constants::characterSize, y*Constants::characterSize);
    text.setColor(sf::Color(40, 40, 40));
    window.draw(text);
}

void Map::draw(sf::RenderWindow &window, sf::Font &font) {
    int x = m_player.getX();
    int y = m_player.getY();
    for(int i = x-15; i < x+15; ++i) {
        for(int j = y-15; j < y+15; ++j) {
            //std::cout << i << " " << j << "\n";
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
    movePlayer();
}
