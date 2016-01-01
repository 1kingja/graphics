#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW
#include <QtOpenGL\qglwidget>
#include <string>

class MeGlWindow : public QGLWidget
{
	void sendDataToOpenGL();
	bool checkShaderStatus(GLuint shaderID);
	bool checkProgramStatus(GLuint programID);
	std::string readShaderCode(const char* fileName);
	void installShaders();
protected:
	void initializeGL();
	void paintGL();
	void mouseMoveEvent(QMouseEvent*);
public:
	~MeGlWindow();
};

#endif
