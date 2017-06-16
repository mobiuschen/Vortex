//
// Created by mobiuschen on 6/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <assert.h>
#include "Shader.h"


Shader *Shader::ShaderFromFile(const std::string &filePath, GLenum shaderType)
{
    Shader *shader = nullptr;
    std::ifstream ifstream;
    std::stringstream buffer;
    bool retCode = false;
                                                 
    ifstream.open(filePath, std::ios::in | std::ios::binary);
    retCode = ifstream.is_open();
    assert(retCode);
    if (!retCode)
        goto Exit0;

    buffer << ifstream.rdbuf();

    shader = new Shader();
    if (!shader->Init(buffer.str(), shaderType))
    {
        delete shader;
        shader = nullptr;
    }
Exit0:
    return shader;
}

Shader::Shader() :
        m_object(0)
{
}


Shader::~Shader()
{
    if (m_object > 0)
    {
        glDeleteShader(m_object);
        m_object = 0;
    }
}


bool Shader::Init(const std::string &shaderCode, GLenum shaderType)
{
    bool result = false;

    m_object = glCreateShader(shaderType);
    if (m_object == 0)
        goto Exit0;

    {
        const char *str = shaderCode.c_str();
        GLint status;
        glShaderSource(m_object, 1, (const GLchar **) &str, NULL);
        glCompileShader(m_object);
        glGetShaderiv(m_object, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint infoLogLength = 0;
            char *strInfoLog = nullptr;
            glGetShaderiv(m_object, GL_INFO_LOG_LENGTH, &infoLogLength);
            strInfoLog = new char[infoLogLength + 1];
            glGetShaderInfoLog(m_object, infoLogLength, NULL, strInfoLog);
            std::cerr << "Compile failure in shader:" << strInfoLog << std::endl;

            delete[] strInfoLog;
            strInfoLog = nullptr;

            glDeleteShader(m_object);
            m_object = 0;
        }
    }

    result = true;
Exit0:
    return result;
}