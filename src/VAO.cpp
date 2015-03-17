#include "../include/VAO.h"

VAO::VAO()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glGenVertexArrays(1, &object);
    glDisableClientState(GL_VERTEX_ARRAY);
}

VAO::~VAO()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glDeleteVertexArrays(1, &object);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void VAO::AddAttribute(const VBO &vbo, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint offset) const
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindVertexArray(object);

    glEnableVertexAttribArray(index);
    vbo.Bind();
    glVertexAttribPointer(index, size, type, normalized, stride, (void*) offset);
    vbo.UnBind();

    glBindVertexArray(0);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void VAO::Bind() const
{
    glBindVertexArray(object);
}

void VAO::UnBind() const
{
    glBindVertexArray(0);
}

