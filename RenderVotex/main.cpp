//
//  main.cpp
//  RenderVotex
//
//  Created by mobiuschen on 2/6/2017.
//  Copyright (c) 2017 mobiuschen. All rights reserved.
//

#include "platform.hpp"

// third-party libraries
#include <glm/glm.hpp>

// standard C++ libraries
#include <iostream>


#include "Application.h"
#include "DrawTriangle.h"


int main(int argc, const char *argv[])
{
    int result = EXIT_FAILURE;
    bool retCode = false;

    DrawTriangle app;
    app.Init();
    retCode = app.Startup();
    if (!retCode)
        goto Exit0;


    app.Run();


    result = EXIT_SUCCESS;
Exit0:
    return result;

}
