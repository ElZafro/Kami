#pragma once

#include "Core.h"

namespace Kami {

	class KAMI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//This should be defined in Client
	Application* CreateApplication();
}

