#ifndef LIGHT_H
#define LIGHT_H

#include "stb_image.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "GBuffer.h"
#include "Texture.h"
#include "Debug.h"
#include "VAO.h"
#include "VBO.h"
#include "glm/glm.hpp"


enum LightType
{
    DirectionalLight
};

class Light
{
private:

    static const float screenMesh[12];
    static const std::string vshaderSource;

    VAO *screenMeshVao;
    VBO *screenMeshVbo;
    ShaderProgram *program;
    Shader *vshader, *fshader;

    glm::vec3 pos, dir;
    glm::vec3 color;
    float intensity;

    LightType type;

public:

    Light(LightType type);
    ~Light();

    void Apply(GBuffer &gbuffer) const;

    void SetPosition(glm::vec3 position);
    void SetDirection(glm::vec3 direction);
    void SetColor(glm::vec3 color);
    void SetIntensity(float intensity);

    glm::vec3 GetPosition() const;
    glm::vec3 GetDirection() const;
    glm::vec3 GetColor() const;
    float GetIntensity() const;
};

#endif // LIGHT_H
