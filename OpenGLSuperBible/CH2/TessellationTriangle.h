//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//


#include <GL/glew.h>
#include "Application.h"

class TessellationTriangle : public Application
{
public:
    TessellationTriangle();
protected:
    virtual bool Startup();

    virtual bool Render(double currentTime);

private :
    GLuint m_vertex_array_object;
};

