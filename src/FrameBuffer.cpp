#include "../include/FrameBuffer.h"

FrameBuffer::FrameBuffer(int width, int height)
{
    glGenFramebuffers(1, &object);
    numBuffers = 0;

    this->width = width;
    this->height = height;
}

FrameBuffer::~FrameBuffer()
{
    textures.clear();
    glDeleteFramebuffers(1, &object);
}

void FrameBuffer::Bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, object);
    glDrawBuffers(numBuffers, &drawBuffers[0]);
}

void FrameBuffer::UnBind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::AddDrawingBuffer(GLenum attachment,
                                   GLenum format,
                                   GLenum internalFormat,
                                   GLenum type,
                                   GLenum wrapMode,
                                   GLenum scaleMode)
{
    DeleteDrawingBuffer(attachment); //Borralo si ya existia

    ++numBuffers;
    drawBuffers.push_back(attachment);

    Texture *texture = new Texture();
    texture->SetData(0, width, height, format, internalFormat, type);
    texture->SetWrapMode(wrapMode);
    texture->SetScaleMode(scaleMode);
    textures.push_back(texture);

    Bind(); //Aqui se llama a glDrawBuffers
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture->GetObject(), 0);
    UnBind();
}

bool FrameBuffer::ExistsDrawingBuffer(GLenum attachment)
{
    for(int i = 0; i < numBuffers; ++i)
        if(drawBuffers[i] == attachment) return true;
    return false;
}

void FrameBuffer::DeleteDrawingBuffer(GLenum attachment)
{
    for(int i = 0; i < numBuffers; ++i)
    {
        if(drawBuffers[i] == attachment)
        {
            --numBuffers;
            drawBuffers.erase(drawBuffers.begin() + i);
            delete textures[i];
        }
    }
}


Texture *FrameBuffer::GetTexture(GLenum attachment) const
{
    for(int i = 0; i < numBuffers; ++i)
        if(drawBuffers[i] == attachment)
            return textures[i];
    return 0;
}
