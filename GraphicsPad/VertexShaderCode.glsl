#version 430

in layout(location=0) vec2 position;
in layout(location=1) float offset;

out vec3 theColor;

void main()
{
	gl_Position = vec4(position.x + offset, position.y, 0, 1);
	theColor = vec3(1, 0, 0);
}