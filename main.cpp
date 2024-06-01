#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "Object.h"
#include "Map.h"
#include "constants.h"

using namespace sf;
static Font font;

int main() {

    RenderWindow window(VideoMode(830, 840), "Lightsed!");

    font.loadFromFile("F:\\MyCodes\\Lightsed\\fonts\\VCR_OSD_MONO_1.001.ttf");
    Map map;
    Clock clock;

    while(window.isOpen()) {

        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed) {
                if(event.key.code == Keyboard::W) {
                    map.getPlayer().setKey(Player::Key_W, true);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::A) {
                    map.getPlayer().setKey(Player::Key_A, true);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::S) {
                    map.getPlayer().setKey(Player::Key_S, true);
                    map.movePlayer();
                }
                if(event.key.code == Keyboard::D) {
                    map.getPlayer().setKey(Player::Key_D, true);
                    map.movePlayer();
                }
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
