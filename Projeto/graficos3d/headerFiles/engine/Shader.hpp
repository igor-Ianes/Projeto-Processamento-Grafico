// Copyright (c) 2026 Igor Ianes
// Licensed under the MIT License.

#ifndef _SHADER_H
#define _SHADER_H
#include <string>

class Shader
{
public:
    unsigned int ID;

    void SetUniform1i(const std::string &name, int value);
    Shader(const char *vs, const char *fs);
    void Use();
    ~Shader();
};

#endif