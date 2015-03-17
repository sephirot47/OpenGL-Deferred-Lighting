#version 130	

uniform float time;
uniform sampler2D tex;

in vec3 fpos;
in vec2 fuv;
in vec3 fnormal;

out vec4 outcolor;
out vec3 outpos;
out vec2 outuv;
out vec3 outnormal;

vec4 ambient = vec4(0.2, 0.2, 0.2, 1.0);

void main()  
{  
    outcolor = texture(tex, vec2(fuv.x, 1.0 - fuv.y)) * ambient;
    outpos = fpos;
    outuv = fuv;
    outnormal = fnormal;
}

