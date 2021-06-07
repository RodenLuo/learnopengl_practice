#version 330 core
layout (location = 0) in vec3 aPos;




uniform float hoffset;
uniform float mix_ratio;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.x + hoffset, aPos.y, aPos.z, 1.0);
    
}