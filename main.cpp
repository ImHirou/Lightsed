#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Map.h"
#include "Tab.h"
#include "constants.h"

using namespace sf;
static Font font;

int main() {

    srand(time(0));
    rand();

    RenderWindow window(VideoMode(830, 840), "Lightsed!");

    font.loadFromFile("./fonts/VCR_OSD_MONO_1.001.ttf");
    Map map;
    Clock clock;

    while(window.isOpen()) {

        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
            if(event.type == Event::MouseMoved) {
                Building** buildings = map.getBuildings();
                for(int i=0; i<3; i++) {
                    if(!buildings[i]->getTab().isOpen()) continue;
                    buildings[i]->getTab().checkHover(event.mouseMove.x, event.mouseMove.y);
                }
            }
            if(event.type == Event::MouseButtonPressed) {
                if(event.mouseButton.button == Mouse::Left) {
                    Building** buildings = map.getBuildings();
                    for(int i=0; i<3; i++) {
                        if(!buildings[i]->getTab().isOpen()) continue;
                        Button** buttons = buildings[i]->getTab().getButtons();
                        for(int j=0; j<buildings[i]->getTab().getButtonsNum(); j++) {
                            if(buttons[j]->isHovered()) {
                                UpgradeButton* button = dynamic_cast<UpgradeButton*>(buttons[j]);
                                button->buy(map.getPlayer());
                            }
                        }
                    }
                }
            }
            if(event.type == Event::KeyPressed) {
                if(event.key.code == Keyboard::W) {
                    map.getPlayer().setKey(Player::Key_W, true);
                    map.getPlayer().setLastKeyPressed(Player::Key_W);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::A) {
                    map.getPlayer().setKey(Player::Key_A, true);
                    map.getPlayer().setLastKeyPressed(Player::Key_A);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::S) {
                    map.getPlayer().setKey(Player::Key_S, true);
                    map.getPlayer().setLastKeyPressed(Player::Key_S);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::D) {
                    map.getPlayer().setKey(Player::Key_D, true);
                    map.getPlayer().setLastKeyPressed(Player::Key_D);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::LShift) {
                    map.getPlayer().setKey(Player::Key_SHIFT, !map.getPlayer().isKeyPressed(Player::Key_SHIFT));
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::LControl) map.getPlayer().setKey(Player::Key_CTRL, true);
            }
            if(event.type == Event::KeyReleased) {

                if(event.key.code == Keyboard::W) {
                    map.getPlayer().setKey(Player::Key_W, false);
                }
                if(event.key.code == Keyboard::A) {
                    map.getPlayer().setKey(Player::Key_A, false);
                }
                if(event.key.code == Keyboard::S) {
                    map.getPlayer().setKey(Player::Key_S, false);
                }
                if(event.key.code == Keyboard::D) {
                    map.getPlayer().setKey(Player::Key_D, false);
                }
                if(event.key.code == Keyboard::LControl) map.getPlayer().setKey(Player::Key_CTRL, false);
            }
        }

        if(1.0/map.getTPS() <= clock.getElapsedTime().asSeconds()) {
            map.tick();
            clock.restart();
        }
        window.clear(Color::Black);
        map.draw(window, font);
        window.display();

    }

}
