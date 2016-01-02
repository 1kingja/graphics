#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW
#include <gl\glew.h>
#include <QtOpenGL\qglwidget>
#include <string>
class MyModel;

class MeGlWindow : public QGLWidget
{
	void sendDataToOpenGL();
	bool checkShaderStatus(GLuint shaderID);
	bool checkProgramStatus(GLuint programID);
	bool checkStatus(
		GLuint objectID,
		PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
		PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
		GLenum statusType);
	std::string readShaderCode(const char* fileName);
	void installShaders();
	MyModel* theModel;
protected:
	void initializeGL();
	void paintGL();
	void mouseMoveEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
public:
	MeGlWindow(MyModel* theModel);
	~MeGlWindow();
};

#endif
