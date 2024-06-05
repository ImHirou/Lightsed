#ifndef LIGHTSED_UPGRADEBUTTON_H
#define LIGHTSED_UPGRADEBUTTON_H

#include "Button.h"

class UpgradeButton : public Button {
protected:
    long long m_cost;
    int m_timesBought;
    int m_maxTimesToBuy;
    void (*m_function)(UpgradeButton& but);
public:
    UpgradeButton(long long cost, int maxTimesToBuy, void (*function)(UpgradeButton& but)) :
        m_cost(cost), m_timesBought(0), m_maxTimesToBuy(maxTimesToBuy), m_function(function) {}
};

#endif //LIGHTSED_UPGRADEBUTTON_H
