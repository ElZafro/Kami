#pragma once

#ifdef KM_PLATFORM_WINDOWS

extern Kami::Application* Kami::CreateApplication();

int main(int argc, char** argv) {

	auto app = Kami::CreateApplication();
	app->Run();
	delete app;
}

#endif