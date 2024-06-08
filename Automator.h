#ifndef LIGHTSED_AUTOMATOR_H
#define LIGHTSED_AUTOMATOR_H


class Automator {
private:
    int m_level;
    int m_ticks;
    int m_collectTicks;
public:
    Automator() : m_level(0), m_ticks(0), m_collectTicks(0) {}

    int getLevel() const;
    int getTicks() const;
    int getCollectTicks() const;

    int ticksByLevel() const;

    void addLevel();
    void reduceCollectTicks();
    void reloadCollectTicks();
    void setLevel(int l);
    void setTicks(int t);
    void setCollectTicks(int ct);

    bool isMaxed();
    bool needCollect();

};


#endif //LIGHTSED_AUTOMATOR_H
