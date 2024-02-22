#include "Rogue.h"
#include <iostream>

class MyGame : public Rogue::RogueApplication {
    virtual void Initialize() override {
        std::cout << "Initializing game..." << std::endl;
    }

    virtual void OnUpdate() override {
        std::cout << "Engine is running..." << std::endl;
    }

    virtual void Shutdown() override {
        std::cout << "Shutting down game..." << std::endl;
    }
};


START_GAME(MyGame)