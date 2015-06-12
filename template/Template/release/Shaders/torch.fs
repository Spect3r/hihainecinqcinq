#version 120

varying float transparency;

void main()
{
  gl_FragColor = vec4( gl_Color.rgb, transparency );
}
