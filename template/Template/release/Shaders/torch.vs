#version 120


uniform mat4 MVP;

in vec3 position;
in vec3 color;
in vec3 velocity;
in vec3 gravity;
in float life;
in float fade;
in float size;
in float tabTransparency;
varying float transparency;


void main()
{
  vec3 pos = position;
  vec3 vel = velocity;
  vec3 grav = gravity;
  vec3 col = color;
  float lifeOut = life;
  transparency = life;

  float deltaTime = (2.0 - life)/fade;

  //transparency -= fade*deltaTime;

  if(life > 0)
  {
    pos.x += (vel.x/500)*deltaTime;
    pos.y += (vel.y/500)*deltaTime;
    pos.z += (vel.z/500)*deltaTime;
  }
    
    
  if(lifeOut < 0)
  {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    lifeOut = 1.0;
  }

  gl_PointSize = size;
  gl_Position = MVP * vec4( pos, 1.0f );
  gl_FrontColor = vec4( col, transparency );
}