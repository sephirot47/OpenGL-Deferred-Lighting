#ifndef GBUFFER_H
#define GBUFFER_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

#include "stb_image.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "FrameBuffer.h"
#include "Texture.h"
#include "Debug.h"
#include "VAO.h"
#include "VBO.h"
#include "glm/glm.hpp"

class GBuffer : public FrameBuffer
{
private:

    static const float screenMesh[12];
    static const std::string vshaderSource;

    enum
    {
        ColorAttachment = GL_COLOR_ATTACHMENT0,
        PositionAttachment = GL_COLOR_ATTACHMENT1,
        UvAttachment = GL_COLOR_ATTACHMENT2,
        NormalsAttachment = GL_COLOR_ATTACHMENT3,
        DepthAttachment = GL_DEPTH_ATTACHMENT
    };

    VAO *screenMeshVao;
    VBO *screenMeshVbo;
    ShaderProgram *program;
    Shader *vshader, *fshader;

public:

    GBuffer(int width, int height, Shader &fshader);
    ~GBuffer();

    void Draw() const;
    void DrawToScreen() const;

    void SetVertexColorLocation(int location, VBO &vbo);
    void SetVertexPositonLocation(int location, VBO &vbo);
    void SetVertexUvLocation(int location, VBO &vbo);
    void SetVertexNormalsLocation(int location, VBO &vbo);

    void SetFragmentColorTextureName(std::string name);
    void SetFragmentPositionTextureName(std::string name);
    void SetFragmentUvTextureName(std::string name);
    void SetFragmentNormalsTextureName(std::string name);
    void SetFragmentDepthTextureName(std::string name);

    VAO *GetVAO() const;
    ShaderProgram *GetShaderProgram() const;
    Texture *GetColorTexture() const;
    Texture *GetPositionTexture() const;
    Texture *GetNormalsTexture() const;
    Texture *GetUvTexture() const;
    Texture *GetDepthTexture() const;
};

#endif // GBUFFER_H
