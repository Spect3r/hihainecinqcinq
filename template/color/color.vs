#version 120


uniform mat4 MVP;

in vec3 position;
in vec3 color;
in vec3 velocity;
in vec3 gravity;
in float life;
in float fade;
varying float time;


void main()
{
  vec3 pos = position;
  vec3 vel = velocity;
  vec3 grav = gravity;
  float lifeOut = life;

//if(life > 0)
//{
  float deltaTime = (2.0 - life)/fade;

  pos.x += (vel.x/1000)*deltaTime;
  pos.y += (vel.y/1000)*deltaTime;
  pos.z += (vel.z/1000)*deltaTime;

  vel.x += grav.x*deltaTime;
  vel.y += grav.y*deltaTime;
  vel.z += grav.z*deltaTime;
// }
//else
  if(lifeOut < 0)
  {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    lifeOut = 1.0;
  }

  //pos.y += life;
  gl_PointSize = 1.0;
  gl_Position = MVP * vec4( pos, 1.0f );
  gl_FrontColor = vec4( color, 1.0f );
}