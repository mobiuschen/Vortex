//
// Created by mobiuschen on 14/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include "Application.h"

#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Program.h"
#include "Utility.h"

Application::Application() :
        m_program(nullptr),
        m_window(nullptr),
        m_closeFlag(false) {
}


Application::~Application() {
}

//----------------------------------------------------------------------------------------------------------------------

bool Application::Init() {
    bool result = false;
    bool retCode = false;

    try {
        _InitGlfw();
        _InitGlew();
        _PrintInfo();

        if (!GLEW_VERSION_3_2)
            throw std::runtime_error("OpenGL API 3.2 is not available.");
    } catch (const std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        goto Exit0;
    }

    result = true;
Exit0:
    return result;
}


bool Application::Run() {
    bool result = false;
    bool retCode = false;

    retCode = Startup();
    LOG_PROCESS_ERROR(retCode);

    while (!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();
        retCode = Render(glfwGetTime());
        LOG_ASSERT(retCode);
        if (!retCode)
            break;
        
        glfwSwapBuffers(m_window);
    }

    glfwTerminate();

    result = true;
Exit0:
    return result;
}


bool Application::Shutdown() {
    m_closeFlag = true;
    return true;
}

//----------------------------------------------------------------------------------------------------------------------
bool Application::CreateProgram(const std::vector<std::string> shaderSources, const std::vector<GLenum> shaderTypes) {
    bool result = false;
    bool retCode = false;

    m_program = new Program();
    LOG_PROCESS_ERROR(m_program != nullptr);
    retCode = m_program->Init(shaderSources, shaderTypes);
    LOG_PROCESS_ERROR(retCode);

    result = true;
Exit0:
    if (!result) {
        delete m_program;
        m_program = nullptr;
    }
    return result;
}


//----------------------------------------------------------------------------------------------------------------------
bool Application::_InitGlfw() {
    // initialise GLFW
    //glfwSetErrorCallback(this->_OnGLFWError);
    if (!glfwInit()) {
        throw std::runtime_error("glfwInit failed.");
    }

    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_window = glfwCreateWindow(800, 600, "This is Title", NULL, NULL);
    if (m_window == NULL) {
        throw std::runtime_error("Creating window failed.");
    }

    glfwMakeContextCurrent(m_window);
    return true;
}


void Application::_OnGLFWError(int errCode, const char *msg) {
    throw std::runtime_error(msg);
}


//----------------------------------------------------------------------------------------------------------------------
bool Application::_InitGlew() {
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("glewInit failed.");
    }

    return true;
}


//----------------------------------------------------------------------------------------------------------------------
bool Application::_PrintInfo() {
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    return true;
}
