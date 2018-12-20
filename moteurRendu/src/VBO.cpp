#include "moteurRendu/VBO.hpp"

VBO::VBO() : _id(0)
{
	std::cout << " *** VBO DEFAULT CONSTRUCTOR" << std::endl;
}

// On passe un vetceur de point (3c oord)
VBO::VBO(const std::vector<glimac::ShapeVertex> &vertices, const GLuint &id, const size_t size, const uint32_t* indexes, const glimac::Geometry g)
: _vertices(vertices), _nbVertices(vertices.size()), _id(id), _geo(g)
{
	glGenBuffers(1,&_id);
	_vao = VAO(_id);
	_ibo = IBO(size, indexes, id);
	
}

VBO::VBO(const VBO &copied) : _id(copied._id), _vao(copied._vao)
{

}

VBO::~VBO()
{}

void VBO::debind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VBO::specifyVAO() const
{
	_ibo.fillIbo();
	_vao.bind();
	_ibo.bind();
	bind();
	_vao.specifyAttributes();
	debind();
	_vao.debind();

}

void VBO::sendData() const
{
	bind();
	// glBufferData(GL_ARRAY_BUFFER,  _nbVertices * sizeof(glimac::ShapeVertex), &_vertices[0], GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER,  _geo.getVertexCount() * sizeof(glimac::ShapeVertex), _geo.getVertexBuffer(), GL_STATIC_DRAW);
// 
	debind();

	specifyVAO();
}

void VBO::deleteBuf() const 
{

	_vao.deleteBuf();
	glDeleteBuffers(1, &_id);
}


void VBO::draw() const
{
    glDrawElements(GL_TRIANGLES, _geo.getIndexCount(), GL_UNSIGNED_INT, 0);
}


void VBO::sendLightShader(GLint &uKd, GLint &uKs, GLint &uShininess, GLint &uLightDir_vs, GLint &uLightIntensity, TrackballCamera &track) const 
{
	_geo.getMaterials();
	glUniform3f(uKd,_geo.getMaterials().m_Kd.x,_geo.getMaterials().m_Kd.y,_geo.getMaterials().m_Kd.z); //Couleur des boules
    glUniform3f(uKs, _geo.getMaterials().m_Ks.x,_geo.getMaterials().m_Ks.y,_geo.getMaterials().m_Ks.z);
    glUniform1f(uShininess, _geo.getMaterials().m_Shininess);
    glm::vec4 LightDir = track.getViewMatrix() * glm::vec4(1.0, 1.0, 1.0, 0.0);
    glUniform3f(uLightDir_vs, LightDir.x, LightDir.y, LightDir.z);
    glUniform3f(uLightIntensity,_geo.getMaterials().m_Le.x,_geo.getMaterials().m_Le.y,_geo.getMaterials().m_Le.z);

    // glUniform3f(uKd, 0.1, 0.2, 0.3); //Couleur des boules
    // glUniform3f(uKs, 0.5, 0.0, 0.0);
    // glUniform1f(uShininess, 32.0);
    // glm::vec4 LightDir = fly.getViewMatrix() * glm::vec4(1.0, 1.0, 1.0, 0.0);
    // glUniform3f(uLightDir_vs, LightDir.x, LightDir.y, LightDir.z);
    // glUniform3f(uLightIntensi

}