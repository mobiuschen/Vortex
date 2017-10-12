#version 410 core
//fragment的颜色根据位置而改变
out vec4 color;

void main(void)
{
    float r = sin(gl_FragCoord.x * 0.25) * 0.25 + 0.5;
    float g = cos(gl_FragCoord.y * 0.25) * 0.25 + 0.5;
    float b = sin(gl_FragCoord.x * 0.15) * cos(gl_FragCoord.y * 0.15);
    color = vec4(r, g, b, 1.0);
}                                                         