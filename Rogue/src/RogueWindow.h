#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "Utility.h"



namespace Rogue {
	class ROGUE_API RogueWindow {
	public:
		static void Init();
		static RogueWindow* GetWindow();
		static void Shutdown();

		void SwapBuffers();
		void PollEvents();
		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static RogueWindow* mInstance{ nullptr };

		std::unique_ptr<WindowImpl> mWindow{ nullptr };

		RogueWindow();
	};
}
