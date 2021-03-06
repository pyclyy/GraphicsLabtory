//----------------------------------------------------
// Declaration: Copyright (c), by i_dovelemon, 2017. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2017 / 02 / 18
// Brief: SSAO
//----------------------------------------------------
#version 330

in vec3 glb_Pos;
in vec2 glb_TexCoord;

out vec2 vs_TexCoord;

void main() {
	gl_Position = vec4(glb_Pos, 1.0);
    vs_TexCoord = glb_TexCoord;
}