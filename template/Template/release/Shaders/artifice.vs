#version 120

uniform mat4 MVP;

in vec3 position;
in vec3 velocity;
in vec3 gravity;
in float life;
in float fade;
in float size;
in vec2 uv;

out vec2 fUV;

void main()
{
  vec3 pos = position;
  vec3 vel = velocity;
  vec3 grav = gravity;
  float lifeOut = life;

 
    
  gl_PointSize = size*2;
  gl_Position = MVP * vec4( pos, 1.0f );

  fUV = uv;
}