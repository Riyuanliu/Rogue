#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;
			
out vec2 TexCoord;
uniform ivec2 ScreenSize;

void main()
{	
	   //gl_Position = vec4(aPos.x,aPos.y,1.0 , 1.0);
	   gl_Position = vec4((aPos.x*2)/ScreenSize.x-1, (aPos.y*2)/ScreenSize.y-1, 1.0, 1.0);
	   TexCoord = aTexCoord;
}