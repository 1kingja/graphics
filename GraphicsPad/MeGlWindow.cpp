#include <gl\glew.h>
#include <MeGlWindow.h>

void MeGlWindow::initializeGL()
{
	glewInit();
}

void MeGlWindow::paintGL()
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}