#include "pch.h"
#include "RogueApplication.h"

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
		Initialize();
		while (true) {
			OnUpdate();
		}
		Shutdown();

	}
}

