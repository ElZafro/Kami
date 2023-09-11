#pragma once

#ifdef KM_PLATFORM_WINDOWS

extern Kami::Application* Kami::CreateApplication();

int main(int argc, char** argv) {

	Kami::Log::Init();
	KM_CORE_WARN("Initialized log!");
	const auto a = 5;
	KM_INFO("Hello! Var={0}", a);

	auto app = Kami::CreateApplication();
	app->Run();
	delete app;
}

#endif