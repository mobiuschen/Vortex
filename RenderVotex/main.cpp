//
//  main.cpp
//  RenderVotex
//
//  Created by mobiuschen on 2/6/2017.
//  Copyright (c) 2017 mobiuschen. All rights reserved.
//

// third-party libraries

// standard C++ libraries

#include "ch2/DrawTriangle.h"
#include "Utility.h"
#include "ch2/TessellationTriangle.h"
#include "ch2/UseGeometryShader.h"
#include "ch5/UsingBuffer.h"
#include <iostream>


int main(int argc, const char *argv[]) {
    int result = false;
    bool retCode = false;

//    DrawTriangle app;
//    TessellationTriangle app;
//    UseGeometryShader app;
    UsingBuffer app;

    retCode = app.Init();
    LOG_PROCESS_ERROR(retCode);
    app.Run();

    result = true;
Exit0:
    return result;
}
