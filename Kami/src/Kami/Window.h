#pragma once

#include "kmpch.h"

#include "Kami/Core.h"

namespace Kami {

	struct WindowProps {
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Kami Engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	//Interface representing a desktop system based Window
	class KAMI_API Window {
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}