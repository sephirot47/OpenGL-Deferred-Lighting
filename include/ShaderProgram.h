#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#define GL_GLEXT_PROTOTYPES

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#include "glm/glm.hpp"
#include "Texture.h"
#include "Shader.h"
#include "Debug.h"

class ShaderProgram
{
private:

    typedef std::pair<std::string, Texture*> TextureMapPair;
    typedef  std::map<std::string, Texture*> TextureMap;

    TextureMap textureMap;
    GLuint object;

public:

    ShaderProgram();
    ~ShaderProgram();

    void AttachShader(const Shader &shader) const;
    void Link() const;
    void Use() const;
    void UnUse() const;

    void AttachTexture(const std::string name, Texture &texture);
    void DetachTexture(const std::string name);

    GLint GetUniformLocation(const std::string name) const;
    void SetUniform(const std::string name, float value) const;
    void SetUniform(const std::string name, int value) const;
    void SetUniform(const std::string name, const glm::vec2& value) const;
    void SetUniform(const std::string name, const glm::vec3& value) const;
    void SetUniform(const std::string name, const glm::vec4& value) const;
    void SetUniform(const std::string name, const glm::mat4& value, GLboolean normalized = GL_FALSE) const;

    GLuint GetObject() const { return object; }
};

#endif // SHADERPROGRAM_H
