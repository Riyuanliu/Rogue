#include "pch.h"
#include "RogueApplication.h"
#include "RogueWindow.h"

namespace Rogue {
	void RogueApplication::Initialize()
	{
	}
	void RogueApplication::OnUpdate()
	{
	}
	void RogueApplication::Shutdown()
	{
	}
	void RogueApplication::Run()
	{
		RogueWindow::Init();
		RogueWindow::GetWindow()->Create(1000, 800);
		Initialize();
		while (true) {
			OnUpdate();
			RogueWindow::GetWindow()->SwapBuffers();
			RogueWindow::GetWindow()->PollEvents();

		}
		Shutdown();
		RogueWindow::Shutdown();

	}
}

