#pragma once
#include <iostream>
#include <glfw3.h>

namespace crusaderEngine {
	namespace graphics {

		class Window {
		private:
			const char* mTitle;
			int mWidth, mHeight;
			GLFWwindow* mWindow;
			bool mClosed;

		public:
			Window(const char* name, int width, int height);
			~Window();
			void update();
			void clear() const;
			bool closed() const;

			int getWidth() const { return mWidth; }
			int getHeight() const { return mHeight; }

		private:
			bool init();
		};

}

}