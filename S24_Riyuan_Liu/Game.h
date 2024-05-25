#pragma once

#include "Rogue.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "Bullets.h"
#include "Score.h"
#include "Item.h"



class MyGame : public Rogue::RogueApplication {
public:
    MyGame();
    
    virtual void Initialize() override;
    virtual void OnUpdate() override;
    virtual void Shutdown() override;
    
    void OnKeyPress(const Rogue::KeyPressed& e);
    void OnKeyRelease(const Rogue::KeyReleased& e);
    void UpdateMovement();
    void bulletRenderAndRemove();
    void checkCollisions();
    void spawnItem();
    void checkItemCollisions();
private:
    int gameStatus = 0;
    score score;
    enum class State { moving = 0, stopped = 1 } mState;
    Player main_character;
    Rogue::Image background{ "C:\\Users\\Riyuan Liu\\Documents\\GameEngine\\S24_Riyuan_Liu\\Rogue\\Assets\\Textures\\Background.png" };
    std::vector<Bullets> bullets;
    std::unordered_map<int, bool> keyStates;
    std::chrono::time_point<std::chrono::steady_clock> gameStartTime;

    std::vector<Enemy> enemies;
    std::chrono::time_point<std::chrono::steady_clock> lastSpawnTime;
    std::chrono::milliseconds spawnCooldown{ 5000 }; // 5 seconds cooldown
    std::mt19937 rng{ std::random_device{}() }; // Random number generator

    std::vector<std::unique_ptr<Item>> items;
    std::chrono::steady_clock::time_point lastItemSpawnTime;
    std::chrono::seconds itemSpawnCooldown{ 10}; //item spawn every 5 sec

    std::chrono::time_point<std::chrono::steady_clock> lastBulletSpawnTime;
    std::chrono::milliseconds BulletSpawnCooldown{ 220 };


    std::vector<std::vector<std::string>> bullets_image;
    std::vector<int> bullet_damage;
    std::vector<int> bullet_speed;
   

    void spawnEnemy();
    void renderAndRemoveEnemies();
    bool isBackgroundRendered = false; // Flag to check if the background has been rendered

}; 
