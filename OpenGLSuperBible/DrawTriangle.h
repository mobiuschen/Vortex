//
// Created by mobiuschen on 15/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//
#pragma once

#include "Application.h"
#include "GL/glew.h"

class DrawTriangle : Application
{
public :
    bool Startup();

    bool Render(double currentTime);

    bool Run();

    bool Init()
    {
        return Application::Init();
    }

private :

    bool CreateProgram();

private :
    GLuint m_program = 0;
    GLuint m_vertex_array_object = 0;
};

