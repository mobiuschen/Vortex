//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//


#include <GL/glew.h>
#include "Application.h"

class TessellationTriangle : Application
{
public:
    bool Startup();

    bool Render(double currentTime);

    bool Run();

    bool Init()
    {
        return Application::Init();
    }

private:

    bool CreateProgram();

    
};

