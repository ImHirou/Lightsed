#ifndef LIGHTSED_UPGRADEBUTTON_H
#define LIGHTSED_UPGRADEBUTTON_H

#include "Button.h"
#include "Player.h"

class UpgradeButton : public Button {
protected:
    long long m_cost;
    int m_timesBought;
    const int m_maxTimesToBuy;
    void (*m_function)(UpgradeButton& but, Player& player);
public:
    UpgradeButton(long long cost, int maxTimesToBuy, void (*function)(UpgradeButton& , Player& player)) :
        m_cost(cost), m_timesBought(0), m_maxTimesToBuy(maxTimesToBuy), m_function(function) {

    }

    long long getCost() const;

    void setCost(long long cost);

    void buy(Player &player);

};

#endif //LIGHTSED_UPGRADEBUTTON_H
