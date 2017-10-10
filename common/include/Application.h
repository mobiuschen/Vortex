//
// Created by mobiuschen on 14/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#pragma once

#include <GL/glew.h>
#include <vector>

class GLFWwindow;

class Program;


class Application
{
public:
	Application();

	virtual ~Application();

	virtual bool Init();

	virtual bool Run();

protected:

	virtual bool Startup() { return true; };

	virtual bool Render(double currentTime) { return true; };

	virtual bool Shutdown();

	virtual bool CreateProgram(const std::vector<std::string> shaderSources, const std::vector<GLenum> shaderTypes);

private:
	bool _InitGlew();

	bool _InitGlfw();

	bool _PrintInfo();

	void _OnGLFWError(int errCode, const char *msg);

protected:
	Program *m_program;
	GLFWwindow *m_window;

	bool m_closeFlag;
};

