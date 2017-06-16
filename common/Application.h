//
// Created by mobiuschen on 14/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#pragma once

class GLFWwindow;

class Application
{
public:
    Application();

    virtual ~Application();

    virtual bool Init();

    virtual bool Run();

protected:

    virtual bool Startup();

    virtual bool Render(double currentTime);

    virtual bool Shutdown();

private:
    bool _InitGlew();

    bool _InitGlfw();

    bool _PrintInfo();

    void _OnGLFWError(int errCode, const char *msg);

private:
    GLFWwindow *m_window;

    bool        m_closeFlag;
};

