#version 430

in vec3 vertexToFragmentColor;
out vec4 daColor;

void main()
{
	daColor = vec4(vertexToFragmentColor, 1);
}