#include <iostream>
#include "Upgrades.h"

void Upgrade1Build1Func(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 2.5);
    player.setMulti(player.getMulti()*2);
}
void Upgrade2Build1Func(UpgradeButton& but, Player& player) {
    player.setNXBoost(true);
}
void Upgrade3Build1Func(UpgradeButton& but, Player& player) {
    player.unlockCTRL();
}
void Upgrade4Build1Func(UpgradeButton& but, Player& player) {
    player.unlockShift();
}

void UpgradeChanceFunc(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 10);
    player.setLightChance(player.getLightChance()*2);
}

void UpgradeAutomatorFunc(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 5);
    player.getAutomator().addLevel();
}