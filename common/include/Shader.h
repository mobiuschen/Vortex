//
// Created by mobiuschen on 6/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
public:
    static Shader *ShaderFromFile(const std::string &filePath, GLenum shaderType);

    Shader();
    ~Shader();

    bool Init(const std::string &shaderCode, GLenum shaderType);
    GLuint inline GetObject() const {return m_object;}

private:

    GLuint m_object;
};

