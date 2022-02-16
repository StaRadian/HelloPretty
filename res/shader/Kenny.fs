#version 460 core

layout(location = 0) out vec4 color;
uniform sampler2D u_Texture[1];
uniform int u_ViewMode;

in vec4 v_Color;
in vec2 v_TexCoord;
in float v_TexIndex;

void main()
{
   int index = int(v_TexIndex);
   vec4 texColor = texture(u_Texture[index], v_TexCoord);
   if(u_ViewMode == 1)
   {
      if(texColor.a > 0.5f)
         color = v_Color;
      else
         color = vec4(0.0f);
   }
   else
      color = texColor;
};