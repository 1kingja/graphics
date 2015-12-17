#include <gl\glew.h>
#include <MeGlWindow.h>

extern const char* vertexShaderCode;

void sendDataToOpenGL()
{
	GLfloat verts[] =
	{
		+0.0f, +0.0f,
		+0.0f, +0.0f, +0.0f,
		+1.0f, +1.0f,
		+0.0f, +0.0f, +0.0f,
		-1.0f, +1.0f,
		+0.0f, +0.0f, +0.0f,
		-1.0f, -1.0f,
		+0.0f, +0.0f, +0.0f,
		+1.0f, -1.0f,
		+0.0f, +0.0f, +0.0f,
	};
	GLuint myBufferID;
	glGenBuffers(1, &myBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2));

	GLushort indices[] = { 0,1,2, 0,3,4 };
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		indices, GL_STATIC_DRAW);
}

void installShaders()
{

}

void MeGlWindow::initializeGL()
{
	glewInit();
	sendDataToOpenGL();
	installShaders();
}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height());
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}