#version 120


uniform mat4 MVP;

in vec3 position;
in vec3 color;
in vec3 velocity;
in vec3 gravity;
in float life;
in float fade;
in float size;
varying float time;


void main()
{
  vec3 pos = position;
  vec3 vel = velocity;
  vec3 grav = gravity;
  vec3 col = color;
  float lifeOut = life;

  float deltaTime = (2.0 - life)/fade;

  if(life > 0)
  {

    if(col.x < 1.0f)
        col.x += 0.03f*deltaTime/3.5;

    else
        col.x = 1.0f;

    if(col.y < 1.0f)
        col.y += 0.03f*deltaTime/3.5;

    else
        col.y = 1.0f;

    if(col.z < 1.0f)
        col.z += 0.03f*deltaTime/3.5;

    else
        col.z = 1.0f;

    vel.y += -0.08*deltaTime;//grav.y*deltaTime;

    pos.x += (vel.x/1000)*deltaTime;
    pos.y += (vel.y/1000)*deltaTime;
    pos.z += (vel.z/1000)*deltaTime;
  }
    
    
  if(lifeOut < 0)
  {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    col.x = 0.41f;
    col.y = 0.5f;
    col.z = 0.71f;
    lifeOut = 1.0;
  }

  //pos.y += life;
  gl_PointSize = size;
  gl_Position = MVP * vec4( pos, 1.0f );
  gl_FrontColor = vec4( col, 1.0f );
}