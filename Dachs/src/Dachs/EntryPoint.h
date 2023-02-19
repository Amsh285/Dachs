#pragma once

#ifdef DS_PLATFORM_WINDOWS

extern Dachs::Application* Dachs::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Beim Badger!" << std::endl;

	Dachs::Application* app = Dachs::CreateApplication();
	app->Run();
	delete app;
}

#endif // DS_PLATFORM_WINDOWS

