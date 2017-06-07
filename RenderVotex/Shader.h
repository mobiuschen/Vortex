//
// Created by mobiuschen on 6/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#ifndef RENDERVOTEX_SHADER_H
#define RENDERVOTEX_SHADER_H


#include <string>
#include <OpenGL/OpenGL.h>

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


#endif //RENDERVOTEX_SHADER_H
