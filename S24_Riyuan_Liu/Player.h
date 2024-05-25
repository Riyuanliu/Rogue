#pragma once
#include "Rogue.h"
#include "Enemy.h"
#include <vector>
#include <string>

enum class Action {
    IdleR,
    IdleL,
    GoingUpL,
    GoingUpR,
    GoingDownL,
    GoingDownR,
    GoingLeft,
    GoingRight,
};
enum class Direction {
    Left,
    right,
    up,
    down
};
class Player {
public:
    // Define the Action enum


    Player();
    ~Player();

    void gotHurt(int damage_amount);

    Rogue::Image* getImage() const;
    int getXLocation() const;
    int getYLocation() const;
    int getHealth() const;
    int getWidth() const;
    int getHeight() const;
    Direction getDirection() const;
    Action getAction();
    float getSpeed() const;
    int getCurrentBullet() const;
    int getCurrentBulletSpawn() const;

    void setX(int x);
    void setY(int y);
    void setHealth(int health);
    void setAction(Action action);
    void setDirection(Direction direction);
    void setCurrentBullet(int x);
    void setCurrentBulletSpawn(int x);

    void updateCurrentBullet(int x);
    void increaseSpeed(float x);
    void increaseShooting(int x);
    void increaseHealth(int x);
    void render() const;
    void update();

    bool collidesWith(const Enemy& enemy) const; // Method to check collision with an enemy
    void takeDamage(int damage);

private:
    int current_bullet = 0;
    int current_bullet_spawn = 220;//ms
    Action action;
    Direction direction;
    int health = 100;
    float speed = 2;
    int x, y;
    std::vector<Rogue::Image> list_image;

    Rogue::Image* currentImage; // Pointer to the current image based on action

    void loadImages();
};
