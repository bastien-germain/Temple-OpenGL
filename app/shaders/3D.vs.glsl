#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec2 vTexCoords;
out vec3 vPosition;
out vec3 vNormal;

void main() {
  	// Passage en coordonnées homogènes
    vec4 vertexPosition = vec4(aVertexPosition, 1);
    vec4 vertexNormal = vec4(aVertexNormal, 0);

    // Calcul des valeurs de sortie
    vPosition = vec3(uMVMatrix * vertexPosition);
    vNormal = vec3(uNormalMatrix * vertexNormal);
    vTexCoords = aVertexTexCoords;

    // Calcul de la position projetée
    gl_Position = uMVPMatrix * vertexPosition;
}
