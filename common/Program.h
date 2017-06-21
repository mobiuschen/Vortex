//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#include <GL/glew.h>
#include <string>
#include <vector>

class Program
{
public:
    Program();
    ~Program();

    bool Init(const std::vector<std::string> shaderSources, const std::vector<GLenum> shaderTypes);

    inline GLuint GetObject() const {
        return m_object;
    }

private:
    GLuint m_object;
};


