#version 120


uniform mat4 MVP;

attribute vec3 position;
attribute vec3 color;


void main()
{
  gl_Position = MVP * vec4( position, 1.0f );

  gl_FrontColor = vec4( color, 1.0f );
}
