#version 330 core
out vec4 outColor;
uniform vec3 colorIn;
void main()
{
   outColor = vec4(colorIn, 1.0);
}