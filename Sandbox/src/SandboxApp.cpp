#include <Kami.h>

class Sandbox : public Kami::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

Kami::Application* Kami::CreateApplication() {
	return new Sandbox();
}