//
//  main.cpp
//  RenderVotex
//
//  Created by mobiuschen on 2/6/2017.
//  Copyright (c) 2017 mobiuschen. All rights reserved.
//

#include "platform.hpp"

// third-party libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// standard C++ libraries
#include <iostream>


#include "Shader.h"

GLFWwindow *glfwWindow = NULL;
Shader *vertexShader = nullptr;
Shader *fragmentShader = nullptr;
GLuint program = 0;
GLuint vertex_array_object = 0;


void OnGLFWError(int errCode, const char *msg)
{
    throw std::runtime_error(msg);
}


bool LoadShaders()
{
    vertexShader = Shader::ShaderFromFile(ResourcePath("vertex.shader"), GL_VERTEX_SHADER);
    fragmentShader = Shader::ShaderFromFile(ResourcePath("fragment.shader"), GL_FRAGMENT_SHADER);
    assert(vertexShader != nullptr);
    assert(fragmentShader != nullptr);
    return true;
}

bool CreateProgram()
{
    bool result = false;

    assert(vertexShader != nullptr);
    assert(fragmentShader != nullptr);
    if (vertexShader == nullptr)
        goto Exit0;

    if (fragmentShader == nullptr)
        goto Exit0;

    program = glCreateProgram();
    glAttachShader(program, vertexShader->GetObject());
    glAttachShader(program, fragmentShader->GetObject());
    glLinkProgram(program);

    delete vertexShader;
    vertexShader = nullptr;

    delete fragmentShader;
    fragmentShader = nullptr;

    result = true;
Exit0:
    return result;
}

bool Startup()
{
    bool result = false;
    auto retCode = LoadShaders();
    assert(retCode);
    if (!retCode)
        goto Exit0;

    retCode = CreateProgram();
    assert(retCode);
    if (!retCode)
        goto Exit0;

    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    result = true;
Exit0:
    return result;
}

bool Render(double currentTime)
{
    const GLfloat color[] = {0.5f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, color);
    
    glUseProgram(program);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    return true;
}


bool InitGLFW()
{
    // initialise GLFW
    glfwSetErrorCallback(OnGLFWError);
    if (!glfwInit())
    {
        throw std::runtime_error("glfwInit failed.");
    }

    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindow = glfwCreateWindow(800, 600, "This is Title", NULL, NULL);
    if (glfwWindow == NULL)
    {
        throw std::runtime_error("Creating window failed.");
    }

    glfwMakeContextCurrent(glfwWindow);
    return true;
}


bool InitGlew()
{
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("glewInit failed.");
    }

    return true;
}


bool PrintInfo()
{
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    return true;
}


int main(int argc, const char *argv[])
{
    int result = EXIT_FAILURE;
    bool retCode = false;
    std::cout << "Hello OpenGL" << std::endl;

    try
    {
        InitGLFW();
        InitGlew();
        PrintInfo();

        if (!GLEW_VERSION_3_2)
            throw std::runtime_error("OpenGL API 3.2 is not available.");

        retCode = Startup();
        assert(retCode);

        while (!glfwWindowShouldClose(glfwWindow))
        {
            glfwPollEvents();
            retCode = Render(glfwGetTime());
            assert(retCode);
            glfwSwapBuffers(glfwWindow);
        }

        glfwTerminate();
    } catch (const std::exception &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        goto Exit0;
    }

    result = EXIT_SUCCESS;
Exit0:
    if (vertexShader != nullptr)
    {
        delete vertexShader;
        vertexShader = nullptr;
    }

    if (fragmentShader != nullptr)
    {
        delete fragmentShader;
        fragmentShader = nullptr;
    }
    return result;

}
