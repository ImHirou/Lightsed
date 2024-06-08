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
    UpgradeButton(Point& p1, Point& p2, const std::string &title, long long cost, int maxTimesToBuy, void (*function)(UpgradeButton& , Player& player)) :
            Button(p1, p2, title), m_cost(cost), m_timesBought(0), m_maxTimesToBuy(maxTimesToBuy), m_function(function) {
    }
    UpgradeButton(double x1, double y1, double x2, double y2, const std::string &title, long long cost, int maxTimesToBuy, void (*function)(UpgradeButton& , Player& player)) :
            Button(x1, y1, x2, y2, title), m_cost(cost), m_timesBought(0), m_maxTimesToBuy(maxTimesToBuy), m_function(function) {
    }
    UpgradeButton(int x1, int y1, int x2, int y2, const std::string &title, long long cost, int maxTimesToBuy, void (*function)(UpgradeButton& , Player& player)) :
            Button(x1, y1, x2, y2, title), m_cost(cost), m_timesBought(0), m_maxTimesToBuy(maxTimesToBuy), m_function(function) {
    }

    long long getCost() const;

    void setCost(long long cost);

    void buy(Player &player);

    void draw(sf::RenderWindow &window, sf::Font &font);
};

#endif //LIGHTSED_UPGRADEBUTTON_H
