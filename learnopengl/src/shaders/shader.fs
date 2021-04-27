#version 330 core
out vec4 FragColor;
in vec3 ourColor;

void main()
{
    if (gl_PointCoord.x > 0.5)
    {
        FragColor = vec4(ourColor, 1.0);
    }
}