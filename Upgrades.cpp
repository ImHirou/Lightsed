#include <iostream>
#include "Upgrades.h"

void Upgrade1Build1Func(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 2);
    player.setMulti(player.getMulti()*2);
}
void Upgrade2Build1Func(UpgradeButton& but, Player& player) {
    player.setTripleBoost(true);
}
void Upgrade3Build1Func(UpgradeButton& but, Player& player) {

}
void Upgrade4Build1Func(UpgradeButton& but, Player& player) {

}

void UpgradeChanceFunc(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 10);
    player.setLightChance(player.getLightChance()*2);
}

void UpgradeAutomatorFunc(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 5);
    player.getAutomator().addLevel();
}