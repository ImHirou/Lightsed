#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "UpgradeButton.h"
#include "constants.h"

long long UpgradeButton::getCost() const { return m_cost; }

void UpgradeButton::setCost(long long cost) { m_cost = cost; }

void UpgradeButton::buy(Player &player) {
    if (m_maxTimesToBuy <= m_timesBought) return;
    if(player.getLight() >= m_cost) {
        player.reduceLight(m_cost);
        m_function(*this, player);
        m_timesBought++;
    }
}

void UpgradeButton::draw(sf::RenderWindow &window, sf::Font &font) {
    float xs = (m_pos2.getX()-m_pos1.getX());
    float ys = (m_pos2.getY()-m_pos1.getY());

    sf::RectangleShape rect(sf::Vector2f(xs, ys));
    sf::Text text;
    text.setFont(font);
    text.setString(m_title);
    text.setCharacterSize(Constants::characterSize);
    if(m_hovered) {
        rect.setOutlineThickness(4);
        rect.setFillColor(sf::Color(30, 30, 30));
        rect.setOutlineColor(sf::Color(170, 170, 170));
        text.setFillColor(sf::Color(30, 30, 170));
    }
    else {
        rect.setOutlineThickness(2);
        rect.setFillColor(sf::Color(50, 50, 50));
        rect.setOutlineColor(sf::Color(160, 160, 160));
        text.setFillColor(sf::Color(200, 200, 200));
    }
    rect.setPosition(m_pos1.getX(), m_pos1.getY());
    text.setPosition(m_pos1.getX()+10, m_pos1.getY()+5);
    window.draw(rect);
    window.draw(text);
    if(m_maxTimesToBuy != m_timesBought) {
        text.setString("Cost:");
        text.setCharacterSize(Constants::characterSize / 2);
        text.setPosition(m_pos1.getX() + 10, m_pos1.getY() + ys - 20);
        window.draw(text);

        std::ostringstream cost;
        cost << m_cost;
        std::string costStr = cost.str();

        text.setString(costStr);

        text.move(40, 0);
        window.draw(text);
    }
    else {
        text.setString("Bought.");
        text.setCharacterSize(Constants::characterSize / 2);
        text.setPosition(m_pos1.getX() + 10, m_pos1.getY() + ys - 20);
        window.draw(text);
    }
}