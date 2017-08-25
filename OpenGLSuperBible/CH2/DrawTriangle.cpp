
#include "DrawTriangle.h"
#include <cmath>
#import "Shader.h"
#include "Utility.h"
#include "Program.h"

bool DrawTriangle::Startup() {
    bool result = false;
    bool retCode = false;

    std::vector<std::string> sources({
            "vertex.shader",
//            "fragment.shader"
            "fragment_position_color.shader"
    });
    std::vector<GLenum> shaderTypes({GL_VERTEX_SHADER, GL_FRAGMENT_SHADER});
    retCode = CreateProgram(sources, shaderTypes);
    LOG_PROCESS_ERROR(retCode);

    glGenVertexArrays(1, &m_vertex_array_object);
    glBindVertexArray(m_vertex_array_object);
    result = true;
Exit0:
    return result;
}


bool DrawTriangle::Render(double currentTime) {

    const GLfloat bgColor[] = {0.5f, 0.0f, 0.0f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    glUseProgram(m_program->GetObject());

    const float offset[4] = {                                                                       
            (float) sin(currentTime) * 0.5f,
            (float) cos(currentTime) * 0.6f,
            0.0f, 0.0f};
    const float vsColor[] = {
            0.0f,
            (float) sin(currentTime) * 0.5f,
            (float) cos(currentTime) * 0.5f,
            0.0f
    };

    glVertexAttrib4fv(0, offset);
    glVertexAttrib4fv(1, vsColor);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    return true;
}
