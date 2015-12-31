#version 430

in vec3 position;
in mat4 fullTransformMatrix;
in vec3 vertexColor;

out vec3 theColor;

void main()
{
	vec4 v = vec4(position, 1.0);
	gl_Position = fullTransformMatrix * v;
	theColor = vertexColor;
}