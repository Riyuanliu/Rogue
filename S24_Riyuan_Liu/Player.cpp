#include "Player.h"

// Constructor
Player::Player() : action(Action::IdleL), health(1000), x(0), y(0), currentImage(nullptr) {
    loadImages();
    currentImage = &list_image[static_cast<int>(Action::IdleL)];
}

// Destructor
Player::~Player() {}

// Method to handle when the player gets hurt
void Player::gotHurt(int damage_amount) {
    health -= damage_amount;
    if (health < 0) {
        health = 0;
    }
}

// Method to get the current image based on the action
Rogue::Image* Player::getImage() const {
    return currentImage;
}

// Getters
int Player::getXLocation() const {
    return x;
}

int Player::getYLocation() const {
    return y;
}

int Player::getHealth() const {
    return health;
}

int Player::getWidth() const
{
    return currentImage->GetWidth();
}

int Player::getHeight() const
{
    return currentImage->GetHeight();
}

Direction Player::getDirection() const
{
    return direction;
}

Action Player::getAction()
{
    return action;
}

float Player::getSpeed() const
{
    return speed;
}

int Player::getCurrentBullet() const
{
    return current_bullet;
}

int Player::getCurrentBulletSpawn() const
{
    return current_bullet_spawn;
}

// Setters
void Player::setX(int x) {
    this->x = x;
}

void Player::setY(int y) {
    this->y = y;
}

void Player::setHealth(int health) {
    this->health = health;
}

// Set the current action and update the current image
void Player::setAction(Action action) {
    this->action = action;
    currentImage = &list_image[static_cast<int>(action)];
}

void Player::setDirection(Direction direction)
{
    this->direction = direction;
}

void Player::setCurrentBullet(int x)
{
    current_bullet = x;
}

void Player::setCurrentBulletSpawn(int x)
{
    current_bullet_spawn += x;
}

void Player::updateCurrentBullet(int x)
{
    if (current_bullet < 9) {
        current_bullet += 1;
    }
    
}

void Player::increaseSpeed(float x)
{
    if (speed < 10.0) {
        speed += x;
    }
}

void Player::increaseShooting(int x)
{
    current_bullet_spawn += x;
}

void Player::increaseHealth(int x)
{
    health += x;
}

// Render the player
void Player::render() const {
    // Assume there's a Renderer class that handles rendering
    Rogue::Renderer::Draw(*currentImage, x, y);
}

// Update the player state
void Player::update() {
    // Update the player state, e.g., handle movement or actions
    // This method would be more complex in a full game implementation
}

bool Player::collidesWith(const Enemy& enemy) const
{
    return (x < enemy.getX() + enemy.getWidth() &&
        x + getWidth() > enemy.getX() &&
        y < enemy.getY() + enemy.getHeight() &&
        y + getHeight() > enemy.getY());
}

void Player::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

// Load images for each action
void Player::loadImages() {
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_idleR.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_idleL.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_upl.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_upr.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_downl.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_downr.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_left.png" });
    list_image.push_back(Rogue::Image{ "../Assets/Textures/Diver/PixelArt_Diver_right.png" });

}
