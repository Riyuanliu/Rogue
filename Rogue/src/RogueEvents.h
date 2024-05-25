#pragma once

#include "Utility.h"

namespace Rogue {
	class ROGUE_API KeyPressed {
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class ROGUE_API KeyReleased {
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}