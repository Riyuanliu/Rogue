#include "Enemy.h"


Enemy::Enemy(Difficulty level, int x, int y)
    : difficulty(level), x(x), y(y) {
    initializeAttributes();
    // Assuming the image path and logic to load it will be different based on difficulty
    switch (difficulty) {
    case Difficulty::l1:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_1.png");
        break;
    case Difficulty::l2:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_2.png");
        break;
    case Difficulty::l3:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_3.png" );
        break;
    case Difficulty::l4:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_4.png");
        break;
    case Difficulty::l5:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_5.png");
        break;
    case Difficulty::l6:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_6.png");
        break;
    case Difficulty::l7:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_7.png");
        break;
    case Difficulty::l8:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_8.png");
        break;
    case Difficulty::l9:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_9.png");
        break;
    case Difficulty::l10:
        image = Rogue::Image("../Assets/Textures/Enemy/Enemy_10.png");
        break;
    }
    width = image.GetWidth();
    height = image.GetHeight();
}

Enemy::~Enemy() {
    // Any necessary cleanup
}

// Move constructor
Enemy::Enemy(Enemy&& other) noexcept
    : difficulty(other.difficulty), health(other.health), speed(other.speed),
    x(other.x), y(other.y), width(other.width), height(other.height),point(other.point),damage(other.damage),image(std::move(other.image)) {
    other.health = 0;
    other.x = 0;
    other.y = 0;
    other.width = 0;
    other.height = 0;
    other.point = 0;
    other.damage = 0;
}

// Move assignment operator
Enemy& Enemy::operator=(Enemy&& other) noexcept {
    if (this != &other) {
        difficulty = other.difficulty;
        health = other.health;
        speed = other.speed;
        x = other.x;
        y = other.y;
        image = std::move(other.image);
        damage = other.damage;

        other.health = 0;
        other.x = 0;
        other.y = 0;
        other.damage = 0;
    }
    return *this;
}

void Enemy::initializeAttributes() {
    switch (difficulty) {
    case Difficulty::l1:
        health = 25;
        speed = 3;
        point = 1; // Add point value for level 1
        damage = 1; // Add damage value for level 1
        break;
    case Difficulty::l2:
        health = 100;
        speed = 2.5;
        point = 2; // Add point value for level 2
        damage = 2; // Add damage value for level 2
        break;
    case Difficulty::l3:
        health = 200;
        speed = 2;
        point = 4; // Add point value for level 3
        damage = 4; // Add damage value for level 3
        break;
    case Difficulty::l4:
        health = 300;
        speed = 1.8;
        point = 8; // Add point value for level 4
        damage = 8; // Add damage value for level 4
        break;
    case Difficulty::l5:
        health = 400;
        speed = 1.6;
        point = 16; // Add point value for level 5
        damage = 16; // Add damage value for level 5
        break;
    case Difficulty::l6:
        health = 800;
        speed = 1.4;
        point = 32; // Add point value for level 6
        damage = 32; // Add damage value for level 6
        break;
    case Difficulty::l7:
        health = 1600;
        speed = 1.5;
        point = 64; // Add point value for level 7
        damage = 64; // Add damage value for level 7
        break;
    case Difficulty::l8:
        health = 1700;
        speed = 1.5;
        point = 128; // Add point value for level 8
        damage = 128; // Add damage value for level 8
        break;
    case Difficulty::l9:
        health = 3200;
        speed = 1.6;
        point = 256; // Add point value for level 9
        damage = 256; // Add damage value for level 9
        break;
    case Difficulty::l10:
        health = 20;
        speed = 5;
        point = 256; // Add point value for level 9
        damage = 6; // Add damage value for level 9
        break;
    default:
        // Handle default case if needed
        break;
    }
}



void Enemy::render() {
    Rogue::Renderer::Draw(image, x, y);
}

void Enemy::update(int targetX, int targetY) {
    // Calculate direction vector
    int deltaX = targetX - x;
    int deltaY = targetY - y;

    // Calculate distance to target
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    // Normalize direction vector and update position
    if (distance > 0) {
        x += static_cast<int>(speed * (deltaX / distance));
        y += static_cast<int>(speed * (deltaY / distance));
    }
}

int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}

int Enemy::getHealth() const {
    return health;
}

int Enemy::getWidth() const
{
    return width;
}

int Enemy::getHeight() const
{
    return height;
}

int Enemy::getPoint() const
{
    return point;
}

int Enemy::getDamage() const
{
    return damage;
}


void Enemy::setHealth(int health) {
    this->health = health;
}

Enemy::Difficulty Enemy::getDifficulty() const {
    return difficulty;
}

void Enemy::takeDamage(int damage)
{
    health -= damage;
}

