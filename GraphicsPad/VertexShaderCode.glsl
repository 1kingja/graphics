#version 430

in layout(location=0) vec3 position;
in layout(location=1) vec3 vertexColor;

uniform vec3 dominatingColor;
uniform float yFlip;

out vec3 theColor;

void main()
{
	gl_Position = vec4(position, 1.0);
	gl_Position.y = gl_Position.y * yFlip;
	theColor = dominatingColor;
}