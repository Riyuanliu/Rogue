#include "pch.h"
#include "RogueWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Rogue {
	RogueWindow::RogueWindow() {

#ifdef ROGUE_GLFW_WINDOW
		mWindow = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else
	#definition_ROGUE_GLFW_is_missing
#endif

	}
	void RogueWindow::Init()
	{
		if (!mInstance)
			mInstance = new RogueWindow;
	}
	RogueWindow* RogueWindow::GetWindow()
	{
		return mInstance;
	}
	void RogueWindow::Shutdown()
	{
		if (mInstance)
			delete mInstance;
	}
	void RogueWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}
	void RogueWindow::PollEvents()
	{
		mWindow->PollEvents();
	}
	void RogueWindow::Create(int width, int height)
	{
		mWindow->Create(width, height);
	}
	int RogueWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}
	int RogueWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}
}
