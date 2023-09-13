#include "kmpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Kami {
	Application::Application() {
		m_Window = Window::Create();
	}

	Application::~Application() {
		glfwTerminate();
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}