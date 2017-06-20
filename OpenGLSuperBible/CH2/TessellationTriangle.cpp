//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include <string>
#include <vector>
#include "TessellationTriangle.h"
#include "Utility.h"

#include "Program.h"

TessellationTriangle::TessellationTriangle() :
        m_vertex_array_object(0) {

}


TessellationTriangle::~TessellationTriangle() {

}

bool TessellationTriangle::Startup() {
    bool result = false;
    bool retCode = false;

    std::vector<std::string> sources = {
            "triangle_vertex.shader",
            "simple_fragment.shader",
            "tessControl.shader",
            "tessEvaluation.shader"
    };
    std::vector<GLenum> shaderTypes = {
            GL_VERTEX_SHADER,
            GL_FRAGMENT_SHADER,
            GL_TESS_CONTROL_SHADER,
            GL_TESS_EVALUATION_SHADER
    };
    retCode = CreateProgram(sources, shaderTypes);
    LOG_PROCESS_ERROR(retCode);

    glGenVertexArrays(1, &m_vertex_array_object);
    glBindVertexArray(m_vertex_array_object);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    result = true;
Exit0:
    return result;
}

bool TessellationTriangle::Render(double currentTime) {
    const GLfloat bgColor[] = {0.5f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    glUseProgram(m_program->GetObject());
    
    glDrawArrays(GL_PATCHES, 0, 3);
    glPointSize(5.0f);
    return true;
}

