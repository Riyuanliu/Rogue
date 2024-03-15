#pragma once
#include "Utility.h"

namespace Rogue {
    class ROGUE_API RogueApplication{
    public:
        virtual void Initialize() = 0;
        virtual void OnUpdate() = 0;
        virtual void Shutdown() = 0;

        void Run();
    private:
    };

}
