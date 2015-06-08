#version 120

//uniform sampler2D texId;

//in vec2 fUV;

//out vec4 fragColor;

void main()
{
 // fragColor = texture2D( texId, fUV );
  gl_FragColor = vec4( gl_Color.rgb, 1.0f );
  //gl_FragColor = vec4(1.0f,0.0f,0.0f,1.0f);
}
