#include "Rogue.h"
#include <iostream>

class MyGame : public Rogue::RogueApplication {
    virtual void Initialize() override {
        
    }

    virtual void OnUpdate() override {
        std::cout << "Window width: " << Rogue::RogueWindow::GetWindow()->GetWidth() << std::endl;
    }

    virtual void Shutdown() override {
       std::cout << "Window width: " << Rogue::RogueWindow::GetWindow()->GetWidth()<< std::endl;
    }
private:

};

START_GAME(MyGame)