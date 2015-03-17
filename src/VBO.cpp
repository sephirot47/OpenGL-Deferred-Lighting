#include "../include/VBO.h"

VBO::VBO()
{
    glGenBuffers(1, &object);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &object);
}

void VBO::SetData(const void *data, int size) const
{
    glBindBuffer(GL_ARRAY_BUFFER, object);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, object);
}

void VBO::UnBind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
