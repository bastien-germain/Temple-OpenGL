#version 320 es

precision mediump float;
precision mediump int;

in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexCoords;

out vec3 fFragColor;

const int MAX_NB_LIGHTS = 15;

struct Light {
	bool _isPoint;
	vec3 _posOrDir;
	vec3 _Kd;
	vec3 _Ks;
	float _shininess;
	vec3 _lightIntensity;
};

uniform sampler2D uTexture;

uniform Light uLights[MAX_NB_LIGHTS];
uniform int uNbLights;
uniform int uLightOn;
uniform vec3 uAmbientLight;


vec3 blinnPhong()
{	
	vec3 wi, halfVector, specular, diffuse; 

	vec3 resultingLight = vec3(0.0, 0.0, 0.0);
	vec3 wo = normalize(-vPosition);
	vec3 posOrDir;

    float d;

	for (int i = 0; i < uNbLights; ++i)
	{	
		if (uLights[i]._isPoint) 
		{
			wi = normalize(uLights[i]._posOrDir - vPosition);
	    	halfVector = normalize((wo+wi)/2.0);
	    	d = distance(vPosition, uLights[i]._posOrDir);

	    	diffuse = uLights[i]._Kd*max(0.0, dot(wi, vNormal));
	    	specular = uLights[i]._Ks*pow(max(0.0, dot(halfVector, vNormal)), uLights[i]._shininess);

			resultingLight += uLights[i]._lightIntensity * (diffuse + specular) / (d * d);
		}
		else 
		{
			wi = normalize(uLights[i]._posOrDir);
    		halfVector = normalize((wo+wi)/2.0);

    		diffuse = uLights[i]._Kd*max(0.0, dot(wi, vNormal));
			specular = uLights[i]._Ks*pow(max(0.0, dot(halfVector, vNormal)), uLights[i]._shininess);

			resultingLight += uLights[i]._lightIntensity*(diffuse + specular);
		}
	}
	
    return resultingLight;
}


void main() 
{	
	if (uLightOn == 1)
		fFragColor = (uAmbientLight + blinnPhong() ) * (texture(uTexture ,vTexCoords).rgb);
	else 
		fFragColor = texture(uTexture ,vTexCoords).rgb;

}
