#version 320 es

precision mediump float;
precision mediump int;

in vec3 vPosition;
in vec3 vNormal;

out vec3 fFragColor;

uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong()
{
	//return uLightIntensity*(uKd*(dot(normalize(uLightDir_vs), vNormal)) + uKs*pow(dot(normalize(-vPosition), vNormal), uShininess));
	return (uKd*(dot(normalize(uLightDir_vs), vNormal)) + uKs*pow(dot(normalize(-vPosition), vNormal), uShininess));
};


void main() {
	/*fFragColor = texture(uEarthTexture ,vTexCoords).rgb + texture(uCloudTexture ,vTexCoords).rgb;*/

	fFragColor = blinnPhong();
	
};