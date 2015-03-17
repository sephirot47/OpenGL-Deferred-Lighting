#version 130

uniform mat4 projection, model;

in vec3 inpos;
in vec2 inuv;
in vec3 innormal;

out vec3 pos;
out vec2 uv;
out vec3 normal;

void main()  
{  
    pos = (model * vec4(inpos, 1.0)).xyz;
    normal = (model * vec4(innormal, 0.0)).xyz;
    gl_Position = projection * model * vec4(inpos, 1.0);
    uv = inuv;
}

