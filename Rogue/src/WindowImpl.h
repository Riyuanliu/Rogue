#pragma once
namespace Rogue {
	class WindowImpl {
	public:
		virtual void Create(int width, int height) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents()=0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual ~WindowImpl() {};
	};
}