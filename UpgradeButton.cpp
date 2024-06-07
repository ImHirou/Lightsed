#include "UpgradeButton.h"

long long UpgradeButton::getCost() const { return m_cost; }

void UpgradeButton::setCost(long long cost) { m_cost = cost; }

void UpgradeButton::buy(Player &player) {
    if (m_maxTimesToBuy <= m_timesBought) return;
    if(player.getLight() >= m_cost) {
        m_function(*this, player);
        m_timesBought++;
        player.reduceLight(m_cost);
    }
}