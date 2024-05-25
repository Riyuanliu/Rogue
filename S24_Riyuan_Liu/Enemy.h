#pragma once

#include <string>
#include "Rogue.h" // Assuming Rogue is a custom library you are using

class Enemy {
public:
    enum class Difficulty {
        l1,
        l2,
        l3,
        l4,
        l5,
        l6,
        l7,
        l8,
        l9,
        l10
    };

    Enemy(Difficulty level, int x, int y);
    ~Enemy();

    // Enable move constructor and move assignment operator
    Enemy(Enemy&&) noexcept;
    Enemy& operator=(Enemy&&) noexcept;

    // Delete copy constructor and copy assignment operator
    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;


    void render();
    void update(int x, int y);

    int getX() const;
    int getY() const;
    int getHealth() const;
    int getWidth() const;
    int getHeight() const;
    int getPoint() const;
    int getDamage() const;

    void setHealth(int health);

    Difficulty getDifficulty() const;
    void takeDamage(int damage);


private:
    int damage;
    int width;
    int height;
    Difficulty difficulty;
    int health;
    float speed;
    int x, y;
    Rogue::Image image{ "../Assets/Textures/Enemy/Enemy_1.png" };
    int point;
    void initializeAttributes();
};
