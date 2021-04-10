#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 ourColor;

uniform float hoffset; 

void main()
{
    gl_Position = vec4(aPos.x + hoffset, -aPos.y, aPos.z, 1.0);
    //ourColor = aColor;
    ourColor = vec3(aPos.x + hoffset, -aPos.y, aPos.z);
}