#ifndef LIGHTSED_UPGRADES_H
#define LIGHTSED_UPGRADES_H

#include "UpgradeButton.h"

void UpgradeFunc1(UpgradeButton& but, Player& player) {
    but.setCost(but.getCost()*2);
}

#endif //LIGHTSED_UPGRADES_H
