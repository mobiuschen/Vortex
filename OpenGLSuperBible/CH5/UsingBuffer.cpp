//
// Created by mobiuschen on 11/7/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include <vector>
#include <string>
#include <cmath>
#include "UsingBuffer.h"
#include "Utility.h"
#include "Program.h"

UsingBuffer::UsingBuffer() : m_vao(0),
                             m_buffer_obj(0) {
}


UsingBuffer::~UsingBuffer() {

}


bool UsingBuffer::Startup() {
    bool result = true;
    bool retCode = false;
    std::vector<std::string> shaderSources({
            "vertex_1.shader",
            "fragment_1.shader"
    });
    std::vector<GLenum> shaderTypes({
            GL_VERTEX_SHADER,
            GL_FRAGMENT_SHADER
    });
    size_t offsetSize = sizeof(m_vertex_offset);
    size_t colorSize = sizeof(m_vertext_color);

    retCode = CreateProgram(shaderSources, shaderTypes);

    LOG_PROCESS_ERROR(retCode);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_buffer_obj);
    ////////// OpenGL 4.5
//    glCreateBuffers(1, &m_buffer_obj); //opengl 4.5
//    glNamedBufferStorage(m_buffer_obj, posArySize + vsArySize, nullptr, GL_DYNAMIC_STORAGE_BIT);
    //////////

    ////////// OpenGL 4.1
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer_obj);
    glBufferData(GL_ARRAY_BUFFER, offsetSize + colorSize, NULL, GL_DYNAMIC_DRAW);
    //////////

    result = true;
Exit0:
    return result;
}


bool UsingBuffer::Render(double currentTime) {
    const GLfloat bgColor[] = {0.5f, 0.5f, 0.5f, 1.0f};
    size_t offsetSize = 0;
    size_t colorSize = 0;

    glClearBufferfv(GL_COLOR, 0, bgColor);
    glUseProgram(m_program->GetObject());

    for (int i = 0, n = LEN(m_vertex_offset); i < n; i++) {
        int t = i % 4;
        if (t == 0)
            m_vertex_offset[i] = (float) sin(currentTime) * 0.5f;
        else if (t == 1)
            m_vertex_offset[i] = (float) cos(currentTime) * 0.6f;
        else if (t == 2)
            m_vertex_offset[i] = 0.0f;
        else if (t == 3)
            m_vertex_offset[i] = 0.0f;
    }


    for (int i = 0, n = LEN(m_vertext_color); i < n; i++) {
        int t = i % 4;
        if (t == 0)
            m_vertext_color[i] = 1.0f;
        else if (t == 1)
            m_vertext_color[i] = (float) sin(currentTime) * 0.5f;
        else if (t == 2)
            m_vertext_color[i] = (float) cos(currentTime) * 0.5f;
        else if (t == 3)
            m_vertext_color[i] = 1.0f;
    }

    offsetSize = sizeof(m_vertex_offset);
    colorSize = sizeof(m_vertext_color);

    //////// OpenGL 4.5
//    glBufferStorage(GL_ARRAY_BUFFER, posArraySize + vsColorSize, nullptr, GL_DYNAMIC_STORAGE_BIT);
//    glVertexArrayAttribBinding(m_vao, 0, 0);
//    glVertexArrayAttribFormat(m_vao, 0, 4, GL_FLOAT, GL_FALSE, 0);
//    glEnableVertexArrayAttrib(m_vao, 0);

//    glVertexArrayAttribBinding(m_vao, 0, 1);
//    glVertexArrayAttribFormat(m_vao, 1, 4, GL_FLOAT, GL_FALSE, 0);
//    glEnableVertexArrayAttrib(m_vao, 1);
//    glVertexArrayVertexBuffer(m_vao, 0, m_buffer_obj, 0, sizeof(offsetSize));
    //////////

    ////////// OpenGL 4.1
    glBufferSubData(GL_ARRAY_BUFFER, 0, offsetSize, m_vertex_offset);
    glBufferSubData(GL_ARRAY_BUFFER, offsetSize, colorSize, m_vertext_color);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (const GLvoid *) (0));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, 0, (const GLvoid *) (4 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    //////////

    glDrawArrays(GL_TRIANGLES, 0, 3);
    return true;
}