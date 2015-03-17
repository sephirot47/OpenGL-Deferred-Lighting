#include "../include/Texture.h"

Texture::Texture()
{
    glGenTextures(1, &object);
    SetWrapMode(GL_REPEAT);
    SetScaleMode(GL_LINEAR);
}

Texture::~Texture()
{
    glDeleteTextures(1, &object);
}

void Texture::SetWrapMode(GLenum mode) const
{
    Bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mode);
    UnBind();
}

void Texture::SetScaleMode(GLenum mode) const
{
    Bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mode);
    UnBind();
}

void Texture::SetData(const void *data, int width, int height, GLenum format, GLenum internalFormat, GLenum type) const
{
    Bind();
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, internalFormat, type, data);
    UnBind();
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, object);
}

void Texture::UnBind() const
{
    glBindTexture(GL_TEXTURE_2D, object);
}

void Texture::Bind(GLuint slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, object);
}

void Texture::UnBind(GLuint slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, 0);
}
