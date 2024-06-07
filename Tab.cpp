#include <SFML/Graphics.hpp>
#include "Tab.h"
#include "constants.h"

Button* Tab::getButtons() { return m_buttons; }
Point& Tab::getPos1() { return m_pos1; }
Point& Tab::getPos2() { return m_pos2; }

void Tab::draw(sf::RenderWindow &window, sf::Font &font) {
    float xs = (m_pos2.getX()-m_pos1.getX());
    float ys = (m_pos2.getY()-m_pos1.getY());

    sf::RectangleShape rect(sf::Vector2f(xs, ys), sf::Vector2f());
    rect.setOutlineThickness(2);
    rect.setFillColor(sf::Color(50, 50, 50));
    rect.setOutlineColor(sf::Color(160, 160, 160));
    rect.setPosition(m_pos1.getX(), m_pos1.getY());

    sf::Text text;
    text.setFont(font);
    text.setString(m_title);
    text.setCharacterSize(Constants::characterSize);
    text.setPosition(m_pos1.getX()+10+Constants::characterSize, m_pos1.getX()+5+Constants::characterSize);
    text.setFillColor(sf::Color(200, 200, 200));

    window.draw(rect);
    window.draw(text);
    for(int i=0; i<1; i++) {
        m_buttons[i].draw(window, font, m_pos1.getX(), m_pos1.getY());
    }
}