#include "Upgrades.h"

void UpgradeFunc1(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost() * 2);
    player.setMulti(player.getMulti()*2);
}