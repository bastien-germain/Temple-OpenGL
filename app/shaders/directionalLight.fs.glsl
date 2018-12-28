#version 320 es

precision mediump float;
precision mediump int;

in vec3 vPosition;
in vec3 vNormal;
in vec3 vTexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong()
{	
	vec3 wi = normalize(uLightDir_vs);
    vec3 wo = normalize(-vPosition);
    vec3 halfVector = normalize((wo+wi)/2.0);

	vec3 tmp = uKd*(dot(wi, vNormal)) + uKs*pow(dot(halfVector, vNormal), uShininess);
	//vec3 tmp = uKd*(abs(dot(wi, vNormal))) + uKs*pow(abs(dot(halfVector, vNormal)), uShininess);
	return (uLightIntensity != 0.0) ? uLightIntensity*tmp : tmp;
}

void main() {
	/*fFragColor = texture(uEarthTexture ,vTexCoords).rgb + texture(uCloudTexture ,vTexCoords).rgb;*/

	//fFragColor = blinnPhong() * texture(uTexture, vTexCoords).rgb;
	fFragColor = blinnPhong();
	
}