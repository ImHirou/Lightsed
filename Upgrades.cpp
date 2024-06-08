#include <iostream>
#include "Upgrades.h"

void UpgradeFunc1(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 2);
    player.setMulti(player.getMulti()*2);
}

void UpgradeChanceFunc(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 10);
    player.setLightChance(player.getLightChance()*2);
}

void UpgradeAutomatorFunc(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 5);
    player.getAutomator().addLevel();
}