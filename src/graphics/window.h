#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace NebulousEngine { namespace Graphics {

#define MAX_BUTTONS	32
#define MAX_KEYS	1024

		class Window
		{
		private:
			const char *m_title;
			int m_width, m_height;
			GLFWwindow *m_window;
			
			bool init();

			static bool m_keys[MAX_KEYS];
			static bool m_buttons[MAX_BUTTONS];
			static double mx, my;

			friend static void windowResize(GLFWwindow *window, int width, int height);
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_callback(GLFWwindow *window, double xpos, double ypos);

		public:
			Window(const char *title, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			static bool getKeyAt(int i);
			static bool getButtonAt(int i);

			static double getMouseX();
			static double getMouseY();

			int getWidth() const;
			int getHeight() const;
		};

} }