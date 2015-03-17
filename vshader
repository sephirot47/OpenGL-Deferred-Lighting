#version 130

uniform float time;
uniform mat4 projection, model, normalMatrix;

in vec3 inpos;
in vec2 inuv;
in vec3 innormal;

out vec3 fpos;
out vec2 fuv;
out vec3 fnormal;

void main()  
{    
    fpos = (model * vec4(inpos, 1.0)).xyz;
    fuv = inuv;    
    fnormal = normalize((normalMatrix * vec4(innormal, 0.0)).xyz);

    gl_Position = projection * model * vec4(inpos, 1.0);
}

