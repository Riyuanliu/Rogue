#pragma once

#include "../WindowImpl.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "RogueEvents.h"

namespace Rogue {
	class WindowGLFW : public WindowImpl{
	public:
		WindowGLFW();
		virtual void Create(int width, int height) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc) override; 
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc) override;
		virtual void SetWindowCloseCallback(std::function<void()>& callbackFunc) override;

		~WindowGLFW();


	private:
		struct Callbacks
		{
			std::function<void(const KeyPressed&)> keyPressedFunc{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)> keyReleasedFunc{ [](const  KeyReleased&) {}};
			std::function<void()> windowCloseFunc{ []() {} };
		}mCallbacks;

		GLFWwindow* mWindow{ nullptr };

	};
}