#version 430

in layout(location=0) vec3 position;
in layout(location=1) vec3 vertexColor;
in layout(location=2) vec3 normal;
uniform vec3 ambientLight;
uniform vec3 lightPosition;

uniform mat4 fullTransformMatrix;

out vec3 theColor;

void main()
{
	vec4 v = vec4(position, 1.0);
	gl_Position = fullTransformMatrix * v;
	vec3 lightVector = normalize(lightPosition - position);
	float brightness = dot(lightVector, normal);
	theColor = vec3(brightness, brightness, brightness);
}