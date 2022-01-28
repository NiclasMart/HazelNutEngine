#pragma once

#include "hzn_pch.h"

#include "HazelNut/Core.h"
#include "HazelNut/Events/Event.h"

namespace HazelNut {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "HazelNut Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{

		}
	};

	// Interface representing a desktop system based widow
	// this class is purely an interface and must be implemented for every platform independently
	class HAZELNUT_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// the caller should not care, which window type he must create
		// so the call is static from window and is redirected to the corresponding window class
		// this function must be implemented by every window class
		static Window* Create(const WindowProps& props = WindowProps());
	};
}
