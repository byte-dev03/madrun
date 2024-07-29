#include <iostream>
#include <gtkmm/application.h>
#include "window.hpp"


int main(int argc, char** argv)
{
	auto app = Gtk::Application::create(argc, argv, "org.builds.madrun");

	Window window;

	// Shows the window and returns when it is closed
	return app->run(window);
}
