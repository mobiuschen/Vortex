//
// Created by mobiuschen on 11/7/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//
#pragma once

#include "GL/glew.h"
#include "Application.h"

class UsingBuffer : public Application
{
public:
    UsingBuffer();

    ~UsingBuffer();

protected:
    virtual bool Startup();

    virtual bool Render(double currentTime);


private:
    GLuint m_vao;
    GLuint m_buffer_obj;

    float m_vertex_offset[12];
    float m_vertext_color[12];
};
