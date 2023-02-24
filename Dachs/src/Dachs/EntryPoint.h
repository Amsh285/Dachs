#pragma once

#ifdef DS_PLATFORM_WINDOWS

extern Dachs::Application* Dachs::CreateApplication();

int main(int argc, char** argv)
{
	Dachs::Log::Init();

	DS_CORE_WARN("Initialized Log!");
	DS_CLIENT_INFO("Initialized Log!");

	Dachs::Application* app = Dachs::CreateApplication();
	app->Run();
	delete app;
}

#endif // DS_PLATFORM_WINDOWS

