#version 410 core

layout(location = 0) in vec4 offset;
layout(location = 1) in vec4 color;

out vec4 vsColor;

void main(void)
{
    const vec4 vertices[] = vec4[](
            vec4( 0.25, -0.25, 0.5, 1.0),
            vec4(-0.25, -0.25, 0.5, 1.0),
            vec4( 0.25,  0.25, 0.5, 1.0)
    );

    gl_Position = vertices[gl_VertexID] + offset;
    
//    vsColor = color;
    vsColor = vec4(1.0, 0.0, 0.0, 1.0);
}