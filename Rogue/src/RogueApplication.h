#pragma once

#include "pch.h"
#include "Utility.h"
#include "RogueEvents.h"
#include "Image.h"
#include "Renderer.h"
#include "RogueKeys.h"


constexpr int ROGUE_FRAME_RATE{ 60 };
namespace Rogue {
    class ROGUE_API RogueApplication {
    public:
        RogueApplication();

        virtual void Initialize() = 0;
        virtual void OnUpdate() = 0;
        virtual void Shutdown() = 0;

        void Run();

        void SetKeyPressedCallback(std::function<void(const KeyPressed&)>callbackFunc);
        void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>callbackFunc);
        void SetWindowCloseCallback(std::function<void()>callbackFunc);
        void DefaultWindowCloseHandler();

    private:
        std::chrono::steady_clock::time_point mNextFrameTime;
        std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / ROGUE_FRAME_RATE };
        //std::chrono::duration<int, std::chrono::milliseconds::period> mFrameDuration{ 1000 / ROGUE_FRAME_RATE };

        bool mShouldContinue{ true };

    };

}
