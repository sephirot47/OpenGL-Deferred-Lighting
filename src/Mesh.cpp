#include "../include/Mesh.h"

Mesh::Mesh()
{
    numVertices = 0;
}

Mesh::~Mesh()
{

}

void Mesh::LoadFromFile(const char *filepath)
{
    std::vector<glm::vec3> pos, normals;
    std::vector<glm::vec2> uv;
    bool triangles;

    FileLoader::ReadOBJ(filepath, pos, uv, normals, triangles);

    drawingMode = triangles ? GL_TRIANGLES : GL_QUADS;

    numVertices = pos.size();

    vao = new VAO();
    int index = 0;
    if(pos.size() > 0)
    {
        vboPos = new VBO();
        vboPos->SetData(&pos[0], pos.size() * sizeof(vec3));
        vao->AddAttribute(*vboPos, index++, 3, GL_FLOAT, GL_FALSE, 0, 0);
    }

    if(uv.size() > 0)
    {
        vboUv = new VBO();
        vboUv->SetData(&uv[0], uv.size() * sizeof(vec2));
        vao->AddAttribute(*vboUv, index++, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }

    if(normals.size() > 0)
    {
        vboNormals = new VBO();
        vboNormals->SetData(&normals[0], normals.size() * sizeof(vec3));
        vao->AddAttribute(*vboNormals, index++, 3, GL_FLOAT, GL_FALSE, 0, 0);
    }
}

void Mesh::Draw()
{
    vao->Bind();
    program->Use();

    glDrawArrays(drawingMode, 0, numVertices);

    program->UnUse();
    vao->UnBind();
}

void Mesh::Draw(Texture &texture)
{
    Draw();
}

void Mesh::SetDrawingMode(GLenum drawingMode)
{
    this->drawingMode = drawingMode;
}

void Mesh::SetShaderProgram(ShaderProgram &shaderProgram)
{
    program = &shaderProgram;
}

VAO* Mesh::GetVAO() const
{
    return vao;
}

VBO* Mesh::GetVBOPos() const
{
    return vboPos;
}

VBO* Mesh::GetVBOUv() const
{
    return vboUv;
}

VBO* Mesh::GetVBONormals() const
{
    return vboNormals;
}

Shader* Mesh::GetFragmentShader() const
{
    return fshader;
}

Shader* Mesh::GetVertexShader() const
{
    return vshader;
}

ShaderProgram* Mesh::GetShaderProgram() const
{
    return program;
}
