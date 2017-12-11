#include "window.h"

namespace crusaderEngine {
	namespace graphics {

		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* title, int width, int height) 
		{
			mTitle = title;
			mWidth = width;
			mHeight = height;
			if (!init()) {
				glfwTerminate();
			}
		}

		Window::~Window() 
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}

			mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
			if (!mWindow) 
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(mWindow);
			glfwSetWindowSizeCallback(mWindow, windowResize);

			return true;
		}

		void Window::clear() const 
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::closed() const 
		{
			return glfwWindowShouldClose(mWindow);
		}

		void Window::update() 
		{
			glfwPollEvents();
			glfwSwapBuffers(mWindow);
		}

		void windowResize(GLFWwindow* window, int width, int height) 
		{
			glViewport(0, 0, width, height);

		}
	}
}