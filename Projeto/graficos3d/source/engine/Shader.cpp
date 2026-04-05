// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#include "OpenGL.hpp"
#include "Shader.hpp"
#include <iostream>

Shader::Shader(const char *vs, const char *fs)
{
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vs, NULL);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fs, NULL);
    glCompileShader(fragment);

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetUniform1i(const std::string &name, int value)
{
    int location = glGetUniformLocation(ID, name.c_str());
    glUniform1i(location, value);
}