#include "../include/FrameDrawer.h"

const float FrameDrawer::screenMesh[12] = {1.0f, -1.0f, 0.0f,
                                           1.0f,  1.0f, 0.0f,
                                          -1.0f,  1.0f, 0.0f,
                                          -1.0f, -1.0f, 0.0f};

FrameDrawer::FrameDrawer(FrameBuffer &fb)
{
    frameBuffer = &fb;

    vbo = new VBO();
    vbo->SetData(FrameDrawer::screenMesh, sizeof(FrameDrawer::screenMesh));

    vao = new VAO();
    vao->AddAttribute(*vbo, 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    fshader = 0;
    vshader = new Shader(); vshader->Create("fbvshader", GL_VERTEX_SHADER);
}

FrameDrawer::~FrameDrawer()
{
}

void FrameDrawer::Draw() const
{
    if(!fshader)
    {
        DbgError("You must attach a created fragment shader to the frame drawer in order to draw something");
        return;
    }

    frameBuffer->UnBind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vao->Bind();
    program->Use();

    //program->SetUniform("width",  float(frameBuffer->GetWidth()));
    //program->SetUniform("height", float(frameBuffer->GetHeight()));

    glDrawArrays(GL_QUADS, 0, 4);

    program->UnUse();
    vao->UnBind();
}

void FrameDrawer::AttachFragmentShader(Shader &fshader, std::string sceneTextureUniformName, std::string depthTextureUniformName)
{
    this->fshader = &fshader;

    program = new ShaderProgram();
    program->AttachShader(*vshader);
    program->AttachShader(fshader);
    program->Link();

    //program->AttachTexture(sceneTextureUniformName, *frameBuffer->GetColorTexture());
    //program->AttachTexture(depthTextureUniformName, *frameBuffer->GetDepthTexture());
}

