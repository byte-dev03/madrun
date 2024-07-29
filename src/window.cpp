#include "window.hpp"
#include <atomic>
#include <cstdlib>
#include <glibmm/main.h>
#include <iostream>
#include <sigc++/functors/mem_fun.h>
#include <string>
#include <thread>
#include <unistd.h>
#include <wait.h>

Window::Window() : m_run_button("Run") {
  set_border_width(10);

  // This packs the entry into the Window (a container)
  add(m_top_container);
  m_top_container.attach(m_entry, 0, 0, 1, 1);
  m_top_container.attach(m_run_button, 1, 0, 1, 1);

  m_run_button.signal_clicked().connect(
      sigc::mem_fun(*this, &Window::on_run_button_clicked));

  // The final step is to display this newly created widget
  show_all();
}

Window::~Window() {}
void Window::on_run_button_clicked() {
    std::string command = m_entry.get_text();
    
    pid_t pid = fork();
    if (pid == -1) {
        // Fork failed
        std::cerr << "Failed to fork a process" << std::endl;
    } else if (pid == 0) {
        // Child process
        int ret = system(command.c_str());
        if (ret != 0) {
            std::cerr << "Failed to run command: " << command << std::endl;
        }
        // Exit the child process
        _exit(ret);
    } else {
        // Parent process
        hide(); // Hide the window
        auto app = this->get_application().get();
        if (app) {
            app->quit(); // Quit the application
        }
    }
}
