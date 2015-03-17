#version 130	

uniform sampler2D colors, pos, uvs, normals, depth;

uniform vec3 lightDir, lightColor;
uniform float lightIntensity;

in vec2 sceneuv;

out vec4 outcolor;
out vec3 outpos;
out vec2 outuv;
out vec3 outnormal;

void main()  
{  
    vec3 position = texture(pos, sceneuv).xyz;
    vec3 normal = normalize(texture(normals, sceneuv).xyz);

    float brightness = max(0.0, dot(-normalize(lightDir), normal));
    
    float isBg = texture(depth, sceneuv).x > 0.99 ? 1.0 : 0.0;
    if(isBg > 0.98) 
	outcolor = texture(colors, sceneuv);
    else 
	outcolor = vec4(texture(colors, sceneuv).xyz + texture(colors, sceneuv).xyz * lightIntensity * lightColor * brightness, 1.0);
	
    //outcolor = vec4(lightColor, 1.0);
    outpos = texture(pos, sceneuv).xyz;
    outuv = texture(uvs, sceneuv).xy;
    outnormal = texture(normals, sceneuv).xyz;
}

