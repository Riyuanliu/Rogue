#include "Item.h"

Item::Item(int x, int y, const std::string& spritePath)
    : x(x), y(y), sprite(spritePath) {}

void Item::render(){
    if (this != nullptr) {
        Rogue::Renderer::Draw(sprite, x, y);
    }
}

bool Item::collidesWith(const Player& player) const {

    if (this != nullptr) {
        int playerX = player.getXLocation();
        int playerY = player.getYLocation();
        int playerWidth = player.getWidth();
        int playerHeight = player.getHeight();

        bool collisionX = x < playerX + playerWidth && x + sprite.GetWidth() > playerX;
        bool collisionY = y < playerY + playerHeight && y + sprite.GetHeight() > playerY;

        return collisionX && collisionY;
    }
    return false;
}

HealthBooster::HealthBooster(int x, int y, const std::string& spritePath)
    : Item(x, y, "../Assets/Textures/Item/Health.png") {}

void HealthBooster::applyEffect(Player& player) {
    player.increaseHealth(50); // Example value
}

SpeedUpgrade::SpeedUpgrade(int x, int y, const std::string& spritePath)
    : Item(x, y, "../Assets/Textures/Item/Speed.png") {}

void SpeedUpgrade::applyEffect(Player& player) {
    player.increaseSpeed(0.5); // Example value
}

BulletUpgrade1::BulletUpgrade1(int x, int y, const std::string& spritePath)
    : Item(x, y, spritePath) {
    upgradeLevel = 0;
}

void BulletUpgrade1::applyEffect(Player& player) {
    
    if (upgradeLevel < 9) { // Assuming 8 is the max level
        // Construct the filepath for the new image
         
        // Update the player's current bullet type
        player.updateCurrentBullet(1);

        // Increment the upgrade level
        ++upgradeLevel;
    }
}

BSpawnUpgrade::BSpawnUpgrade(int x, int y, const std::string& spritePath)
    : Item(x, y, spritePath) {}

void BSpawnUpgrade::applyEffect(Player& player)
{
    player.setCurrentBulletSpawn(-5);
}
