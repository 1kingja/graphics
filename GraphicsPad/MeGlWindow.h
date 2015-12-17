#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW
#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
class MyModel;

class MeGlWindow : public QGLWidget
{
	MyModel* theModel;
protected:
	void initializeGL();
	void paintGL();
};

#endif