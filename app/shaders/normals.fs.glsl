#version 330 core

in vec2 vTexCoords;
in vec3 vPosition;
in vec3 vNormal;

out vec3 fFragColor;

void main() {

	fFragColor = normalize(vNormal);
};