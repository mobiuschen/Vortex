//
// Created by mobiuschen on 21/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#pragma once

#include "Application.h"

class UseGeometryShader : public Application
{
public:
    UseGeometryShader();
    ~UseGeometryShader();
protected:
    virtual bool Startup();
    virtual bool Render(double currentTime);

private:
    GLuint m_vao;
};

