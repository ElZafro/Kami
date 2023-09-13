#include "kmpch.h"
#include "WindowsWindow.h"

namespace Kami {

	inline bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		KM_CORE_INFO("Creating window {0} [{1} x {2}]", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			if (!glfwInit())
				KM_CORE_ERROR("Could not initialize GLFW!");

			m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(m_Window);
		}
	}

	WindowsWindow::~WindowsWindow() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}


}