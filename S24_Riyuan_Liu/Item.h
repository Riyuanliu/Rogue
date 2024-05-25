#pragma once
#include "Rogue.h"
#include "Player.h"

class Item {
public:
    Item(int x, int y, const std::string& spritePath);
    virtual ~Item() = default;

    void render();
    bool collidesWith(const Player& player) const;
    virtual void applyEffect(Player& player) = 0;

protected:
    int x;
    int y;
    Rogue::Image sprite{"../Asserts/Textures/Item/Gun_1.png"};
};

class HealthBooster : public Item {
public:
    HealthBooster(int x, int y, const std::string& spritePath);
    void applyEffect(Player& player) override;
};

class SpeedUpgrade : public Item {
public:
    SpeedUpgrade(int x, int y, const std::string& spritePath);
    void applyEffect(Player& player) override;
};


class BulletUpgrade1 : public Item {
public:
    BulletUpgrade1(int x, int y, const std::string& spritePath);
    void applyEffect(Player& player) override;
private:
    int upgradeLevel=1;
};

class BSpawnUpgrade : public Item {
public:
    BSpawnUpgrade(int x, int y, const std::string& spritePath);
    void applyEffect(Player& player) override;
};

