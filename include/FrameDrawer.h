#ifndef FRAMEDRAWER_H
#define FRAMEDRAWER_H
#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#include "VAO.h"
#include "VBO.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "FrameBuffer.h"
#include "Texture.h"
#include "Debug.h"

class FrameDrawer
{
private:

    FrameBuffer *frameBuffer;
    VAO *vao;
    VBO *vbo;
    Shader *fshader, *vshader;
    ShaderProgram *program;

    FrameDrawer(const FrameDrawer&) {}

    static const float screenMesh[12];

public:

    FrameDrawer(FrameBuffer &fb);
    ~FrameDrawer();

    void Draw() const;
    void AttachFragmentShader(Shader &fshader, std::string sceneTextureUniformName, std::string depthTextureUniformName);
    ShaderProgram* GetProgram() const { return program; }
};

#endif // FRAMEDRAWER_H
