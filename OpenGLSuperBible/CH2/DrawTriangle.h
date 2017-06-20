//
// Created by mobiuschen on 15/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//
#pragma once

#include <GL/glew.h>
#include "Application.h"

class DrawTriangle : public Application
{
protected:
    virtual bool Startup();

    virtual bool Render(double currentTime);

private :
    GLuint m_vertex_array_object = 0;
};

