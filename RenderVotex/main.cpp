//
//  main.cpp
//  RenderVotex
//
//  Created by mobiuschen on 2/6/2017.
//  Copyright (c) 2017 mobiuschen. All rights reserved.
//

// third-party libraries

// standard C++ libraries

#include "DrawTriangle.h"
#include "Utility.h"
#include "TessellationTriangle.h"
#include <iostream>


int main(int argc, const char *argv[]) {
    int result = false;
    bool retCode = false;

//    DrawTriangle app;
    TessellationTriangle app;
    retCode = app.Init();
    LOG_PROCESS_ERROR(retCode);
    app.Run();

    result = true;
Exit0:
    return result;

}
