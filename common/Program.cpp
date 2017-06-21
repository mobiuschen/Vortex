//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include "Program.h"
#include "Utility.h"
#include "Shader.h"

Program::Program() : m_object(0) {

}

Program::~Program() {
    if (m_object > 0) {
        glDeleteProgram(m_object);
        m_object = 0;
    }
}

bool Program::Init(const std::vector<std::string> shaderSources, const std::vector<GLenum> shaderTypes) {
    bool result = false;
    std::vector<Shader *> shaders(shaderSources.size());
    LOG_PROCESS_ERROR(shaderSources.size() == shaderTypes.size());

    m_object = glCreateProgram();
    LOG_PROCESS_ERROR(m_object != 0);
    for (int i = 0, n = (int) shaderSources.size(); i < n; i++) {
        Shader *shader = Shader::ShaderFromFile(shaderSources[i], shaderTypes[i]);
        shaders[i] = shader;
        LOG_PROCESS_ERROR(shader != nullptr);
        glAttachShader(m_object, shader->GetObject());
    }
    glLinkProgram(m_object);

    result = true;
Exit0:
    for (int i = 0, n = (int) shaders.size(); i < n; i++) {
        delete shaders[i];
    }
    return result;
}


