#version 320 es

precision mediump float;
precision mediump int;

in vec2 vTexCoords;
in vec3 vPosition;
in vec3 vNormal;

out vec3 fFragColor;

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

void main() {
	fFragColor = texture(uEarthTexture ,vTexCoords).rgb + texture(uCloudTexture ,vTexCoords).rgb;
	
};