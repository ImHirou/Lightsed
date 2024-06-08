#include "Automator.h"

int Automator::getLevel() const { return m_level; }
int Automator::getTicks() const { return m_ticks; }
int Automator::getCollectTicks() const {return m_collectTicks; }

int Automator::ticksByLevel() const {
    switch (m_level) {
        case 1: return 1000;
        case 2: return 800;
        case 3: return 700;
        case 4: return 600;
        case 5: return 500;
        case 6: return 400;
        case 7: return 300;
        case 8: return 200;
        case 9: return 100;
        default: return 1000;
    }
}

void Automator::addLevel() {
    ++m_level;
    m_ticks = ticksByLevel();
    reloadCollectTicks();
}
void Automator::reduceCollectTicks() { --m_collectTicks; }
void Automator::reloadCollectTicks() { m_collectTicks = m_ticks; }
void Automator::setLevel(int l) { m_level = l; }
void Automator::setTicks(int t) { m_ticks = t; }
void Automator::setCollectTicks(int ct) { m_collectTicks = ct; }

bool Automator::needCollect() {
    if(m_level == 0 || isMaxed()) return false;
    if(m_collectTicks <= 0) {
        reloadCollectTicks();
        return true;
    }
    return false;
}

bool Automator::isMaxed() { return m_level == 10; }