#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <string>
#include <map>
#include <glad/glad.h>

class TextureManager
{
public:
    static GLuint LoadTexture(const std::string &path);
    static void Release();

private:
    static std::map<std::string, GLuint> textures;
};

#endif