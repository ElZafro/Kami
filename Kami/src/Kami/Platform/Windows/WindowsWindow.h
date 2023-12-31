#pragma once

#include "Kami/Window.h"

#include <GLFW/glfw3.h>

namespace Kami {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; }
		inline uint32_t GetHeight() const override { return m_Data.Height; }

		virtual void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; };

	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title{};
			uint32_t Width{}, Height{};

			EventCallbackFn EventCallback;
		};

		WindowData m_Data{};
	};
}

