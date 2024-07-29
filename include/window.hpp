#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/grid.h>
#include <gtkmm/window.h>

class Window : public Gtk::Window
{
	public:
		Window();
		virtual ~Window();

	protected:

		// Signal handlers
		void on_run_button_clicked();

		// Member widgets;
		Gtk::Grid m_top_container;
		Gtk::Entry m_entry;
		Gtk::Button m_run_button;

};

#endif
