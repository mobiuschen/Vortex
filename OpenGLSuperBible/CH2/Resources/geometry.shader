#version 410 core

layout (triangles) in;
layout (points, max_vertices = 3) out;

void main(void) {
    for(int i = 0, n = gl_in.length(); i < n; i++) {
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }
}