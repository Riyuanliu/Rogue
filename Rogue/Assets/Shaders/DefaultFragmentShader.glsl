#version 330 core
out vec4 FragColor;

in vec2 TexCoord; // or in vec2 TexCoord;

uniform sampler2D myTex;

void main(){
    //FragColor = vec4(1.0, 0, 0, 1);
    FragColor = texture(myTex, TexCoord);
}
