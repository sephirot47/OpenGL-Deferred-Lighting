#include "../include/Light.h"

const float Light::screenMesh[12] = {1.0f, -1.0f, 0.0f,
                                     1.0f,  1.0f, 0.0f,
                                    -1.0f,  1.0f, 0.0f,
                                    -1.0f, -1.0f, 0.0f};

const std::string Light::vshaderSource =
    "#version 130\n\r"
    ""
    "in vec3 pos;"
    "out vec2 sceneuv;"
    ""
    "void main()"
    "{"
        "gl_Position = vec4(pos, 1.0);"
        "sceneuv = (pos.xy + vec2(1.0, 1.0))/2.0;"
    "}";


Light::Light(LightType type)
{
    // Create the vertex shader
    vshader = new Shader(); vshader->CreateFromSourceCode(vshaderSource, GL_VERTEX_SHADER);
    fshader = new Shader(); fshader->Create("directionaLightShader.frag", GL_FRAGMENT_SHADER);

    program = new ShaderProgram();
    program->AttachShader(*vshader);
    program->AttachShader(*fshader);
    program->Link();

    screenMeshVbo = new VBO();
    screenMeshVbo->SetData(Light::screenMesh, sizeof(Light::screenMesh));

    screenMeshVao = new VAO();
    screenMeshVao->AddAttribute(*screenMeshVbo, 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    this->type = type;

    pos = vec3(-100, 100, 100);
    dir = vec3(1, -1, -1);
    color = vec3(1, 1, 1);
    intensity = 1.0f;
}

Light::~Light()
{

}

void Light::Apply(GBuffer &gbuffer) const
{
    glDisable(GL_DEPTH_TEST);
    if(type == DirectionalLight)
    {
        gbuffer.Bind();
        screenMeshVao->Bind();
        program->Use();

        program->AttachTexture("colors", *gbuffer.GetColorTexture());
        program->AttachTexture("pos", *gbuffer.GetPositionTexture());
        program->AttachTexture("uvs", *gbuffer.GetUvTexture());
        program->AttachTexture("normals", *gbuffer.GetNormalsTexture());
        program->AttachTexture("depth", *gbuffer.GetDepthTexture());

        program->SetUniform("lightDir", dir);
        program->SetUniform("lightColor", color);
        program->SetUniform("lightIntensity", intensity);
        glDrawArrays(GL_QUADS, 0, 4);

        program->UnUse();
        screenMeshVao->UnBind();
    }
    glEnable(GL_DEPTH_TEST);
}

void Light::SetPosition(glm::vec3 position)
{
    pos = position;
}

void Light::SetDirection(glm::vec3 direction)
{
    dir = direction;
}

void Light::SetColor(glm::vec3 color)
{
    this->color = color;
}

void Light::SetIntensity(float intensity)
{
    this->intensity = intensity;
}


glm::vec3 Light::GetPosition() const
{
    return pos;
}

glm::vec3 Light::GetDirection() const
{
    return dir;
}

glm::vec3 Light::GetColor() const
{
    return color;
}

float Light::GetIntensity() const
{
    return intensity;
}

