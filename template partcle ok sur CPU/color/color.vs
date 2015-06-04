#version 120


uniform mat4 MVP;

in vec3 position;
in vec3 color;
in vec3 velocity;
in vec3 gravity;
out vec3 pos;
out vec3 vel;
uniform float time;


void main()
{
  //vec4 v = vec4(gl_Vertex);
  //v.x = v.x * 2;

  gl_PointSize = 1.0;

  pos = position;
  vel = velocity;
  //pos.x = position.x + velocity.x/10.0;
  //pos.y = position.y + velocity.y/10.0;
  //pos.z = position.y + 10.0;
  pos += 0.1;

  gl_Position = MVP * vec4( pos, 1.0f );

  gl_FrontColor = vec4( color, 1.0f );
}
