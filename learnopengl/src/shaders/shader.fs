#version 330 core

out vec4 FragColor;
in vec3 ourColor;
in vec2 circle_radii;


void main()
{
    if ( (gl_PointCoord.x - 0.5) * (gl_PointCoord.x - 0.5) + (gl_PointCoord.y - 0.5) * (gl_PointCoord.y - 0.5) < circle_radii.x &&
         (gl_PointCoord.x - 0.5) * (gl_PointCoord.x - 0.5) + (gl_PointCoord.y - 0.5) * (gl_PointCoord.y - 0.5) > circle_radii.y)
    {
        FragColor = vec4(ourColor, 1.0);
    }
    else
    {
        FragColor = vec4(0,0,0, 0.0);

    }
    
}