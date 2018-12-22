#version 320 es

#ifdef GL_ES
	precision mediump float;
	precision mediump int;
#endif

in vec3 vColor;

out vec3 fFragColor;

void main() {
    fFragColor = vec3(1,1,1);
}
