//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include <string>
#include <vector>
#include <complex>
#include "TessellationTriangle.h"
#include "Utility.h"

#include "Program.h"

TessellationTriangle::TessellationTriangle() :
        m_vertex_array_object(0) {

}


bool TessellationTriangle::Startup() {
    bool result = false;
    bool retCode = false;

    std::vector<std::string> sources = {
            "triangle_vertex.shader",
            "fragment_constant_color.shader",
            "tess_control.shader",
            "tess_evaluation.shader"
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
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    result = true;
Exit0:
    return result;
}

bool TessellationTriangle::Render(double currentTime) {
    const GLfloat bgColor[] = {0.1f, 0.1f, 0.1f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    glUseProgram(m_program->GetObject());

//    const float offset[4] = {0, 0, 0, 0};
    const float offset[4] = {
            (float) sin(currentTime) * 0.5f,
            (float) cos(currentTime) * 0.6f,
            0.0f,
            0.0f
    };


    glVertexAttrib4fv(0, offset);

    glDrawArrays(GL_PATCHES, 0, 3);
    glPointSize(5.0f);
    return true;
}

