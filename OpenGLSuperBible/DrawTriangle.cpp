
#import <glew.h>
#include <cmath>
#import "Shader.h"
#import "platform.hpp"
#include "DrawTriangle.h"

bool DrawTriangle::Startup()
{
    bool result = false;
    bool retCode = CreateProgram();
    if (!retCode)
        goto Exit0;


    glGenVertexArrays(1, &m_vertex_array_object);
    glBindVertexArray(m_vertex_array_object);
    result = true;
Exit0:
    return result;
}


bool DrawTriangle::Render(double currentTime)
{

    const GLfloat bgColor[] = {0.5f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    glUseProgram(m_program);

    const float offset[4] = {
            (float) sin(currentTime) * 0.5f,
            (float) cos(currentTime) * 0.6f,
            0.0f, 0.0f};
    const float vsColor[] = {
            0.0f,
            (float) sin(currentTime) * 0.5f,
            (float) cos(currentTime) * 0.5f,
            0.0f
    };

//    glVertexAttrib4fv(0, offset);
//    glVertexAttrib4fv(1, vsColor);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    return true;
}


bool DrawTriangle::Run()
{
    Application::Run();
    return true;
}


bool DrawTriangle::CreateProgram()
{
    bool result = false;

    Shader *shaders[2];
    shaders[0] = Shader::ShaderFromFile(ResourcePath("triangle_vertex.shader"), GL_VERTEX_SHADER);
    shaders[1] = Shader::ShaderFromFile(ResourcePath("simple_fragment.shader"), GL_FRAGMENT_SHADER);

    m_program = glCreateProgram();
    for (int i = 0, n = (sizeof(shaders) / sizeof(shaders[0])); i < n; i++)
    {
        auto shader = shaders[i];
        if (shader != nullptr)
        {
            glAttachShader(m_program, shader->GetObject());
        }
    }
    glLinkProgram(m_program);

    result = true;
//Exit0:
    for (int i = 0, n = (sizeof(shaders) / sizeof(shaders[0])); i < n; i++)
    {
        if (shaders[i] != nullptr)
        {
            delete shaders[i];
            shaders[i] = nullptr;
        }
    }
    return result;
}