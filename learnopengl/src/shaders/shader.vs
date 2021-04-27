#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 circle_radii_;

out vec3 ourColor;
out vec2 circle_radii;

uniform float hoffset; 

void main()
{
    gl_Position = vec4(aPos.x + hoffset, aPos.y, aPos.z, 1.0);
    ourColor = aColor;

    circle_radii = circle_radii_;
    //ourColor = vec3(aPos.x + hoffset, -aPos.y, aPos.z);
}