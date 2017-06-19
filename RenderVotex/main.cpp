//
//  main.cpp
//  RenderVotex
//
//  Created by mobiuschen on 2/6/2017.
//  Copyright (c) 2017 mobiuschen. All rights reserved.
//

// third-party libraries

// standard C++ libraries

#include "platform.hpp"
#include "DrawTriangle.h"
#include <glm/glm.hpp>
#include <iostream>


int main(int argc, const char *argv[]) {
    int result = false;
    bool retCode = false;

    std::cout << "Hello world" << std::endl;
    DrawTriangle app;

    retCode = app.Init();
    if (!retCode)
        goto Exit0;

    app.Run();


    result = true;
Exit0:
    return result;

}
