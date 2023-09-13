#pragma once

#include "Core.h"
#include "Window.h"

namespace Kami {

	class KAMI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		Window* m_Window;
		bool m_Running = true;
	};

	//To be defined in client
	Application* CreateApplication();
}

