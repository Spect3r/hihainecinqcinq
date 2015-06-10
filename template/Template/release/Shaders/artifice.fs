#version 120

uniform sampler2D texId;

in vec2 fUV;

out vec4 fragColor;

void main()
{
  fragColor = texture2D( texId, fUV );
}
