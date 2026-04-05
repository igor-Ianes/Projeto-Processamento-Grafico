#include "TextureManager.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

std::map<std::string, GLuint> TextureManager::textures;

GLuint TextureManager::LoadTexture(const std::string &path)
{
    // se ja carregou, retorna cache
    if (textures.find(path) != textures.end())
        return textures[path];

    int width, height, channels;

    // inverte imagem
    stbi_set_flip_vertically_on_load(true);

    // evita textura preta
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    if (!data)
    {
        std::cout << "Erro ao carregar textura: " << path << std::endl;
        return 0;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // evita problema com alinhamento de memória
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 width,
                 height,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 data);

    // mipmaps, importante para textura grande
    glGenerateMipmap(GL_TEXTURE_2D);

    // filtros corretos
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // wrap, evita artefatos
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(data);

    textures[path] = texture;

    return texture;
}

void TextureManager::Release()
{
    for (auto &tex : textures)
    {
        glDeleteTextures(1, &tex.second);
    }
    textures.clear();
}