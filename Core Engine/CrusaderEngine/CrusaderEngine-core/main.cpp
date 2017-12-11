#include "Source\Graphics\window.h"

int main() 
{
	using namespace crusaderEngine;
	using namespace graphics;

	Window window("Memes!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << "Faka MarkyDooda" << std::endl;

	while (!window.closed()) 
	{
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		window.update();
	}

	//system("PAUSE");
	return 0;
}