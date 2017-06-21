//
// Created by mobiuschen on 21/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include <GL/glew.h>
#include "UseGeometryShader.h"
#include "Program.h"
#include "Utility.h"

UseGeometryShader::UseGeometryShader() : m_vao(0) {
}


UseGeometryShader::~UseGeometryShader() {
    if (m_vao > 0) {
        glDeleteVertexArrays(1, &m_vao);
        m_vao = 0;
    }
}


bool UseGeometryShader::Startup() {
    bool result = false;
    bool retCode = false;

    const std::vector<std::string> sources = {
            "triangle_vertex.shader",
            "fragment_constant_color.shader",
            "tess_control.shader",
            "tess_evaluation.shader",
            "geometry.shader"
    };
    const std::vector<GLenum> shaderTypes = {
            GL_VERTEX_SHADER,
            GL_FRAGMENT_SHADER,
            GL_TESS_CONTROL_SHADER,
            GL_TESS_EVALUATION_SHADER,
            GL_GEOMETRY_SHADER
    };

    retCode = CreateProgram(sources, shaderTypes);
    LOG_PROCESS_ERROR(retCode);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glPointSize(5);

    result = true;
Exit0:
    return result;
}


bool UseGeometryShader::Render(double currentTime) {
    const GLfloat bgColor[] = {0.1, 0.1, 0.1, 1};
    glClearBufferfv(GL_COLOR, 0, bgColor);

    glUseProgram(m_program->GetObject());
    glDrawArrays(GL_PATCHES, 0, 3);

    return true;
}
