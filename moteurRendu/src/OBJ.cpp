#include "moteurRendu/OBJ.hpp"

OBJ::OBJ(const glimac::FilePath &path) : _path(path)
{	
}

OBJ::~OBJ()
{
}

const bool OBJ::loadAssimp(std::vector<uint32_t> indexes, std::vector<glimac::ShapeVertex> &vertices) const 
{

	Assimp::Importer importer;
    std::cout << "importer ok" << std::endl;

	const aiScene* scene = importer.ReadFile(_path, 0/*aiProcess_JoinIdenticalVertices | aiProcess_SortByPType*/);
    std::cout << "imported into scene ok" << std::endl;

	if( !scene) 
	{
		fprintf( stderr, importer.GetErrorString());
		getchar();
		return false;
	}

    std::cout << "mesh created ok" << std::endl;
	const aiMesh* mesh = scene->mMeshes[0]; // In this simple example code we always use the 1rst mesh (in OBJ files there is often only one anyway)

	// Fill vertices positions
	vertices.reserve(mesh->mNumVertices);
    std::cout << "vertices reserved" << std::endl;

	glimac::ShapeVertex tmp;

	aiVector3D pos;
	aiVector3D n;
	aiVector3D UVW;

	for(unsigned int i=0; i<mesh->mNumVertices; i++)
	{
    	std::cout << "boucle for vertices" << std::endl;
		pos = mesh->mVertices[i];
    	std::cout << "pos ok" << std::endl;
		if (mesh->mTextureCoords[0])
			UVW = mesh->mTextureCoords[0][i]; // Assume only 1 set of UV coords; AssImp supports 8 UV sets.
    	std::cout << "uvw ok" << std::endl;
		n = mesh->mNormals[i];
    	std::cout << " n ok" << std::endl;

		tmp.m_Position = glm::vec3(pos.x, pos.y, pos.z);
    	std::cout << tmp.m_Position << std::endl;
		tmp.m_TexCoords = glm::vec2(UVW.x, UVW.y);
		tmp.m_Normal = glm::vec3(n.x, n.y, n.z);

		vertices.push_back(tmp);
	}
    std::cout << "pushed back vertices" << std::endl;

	// Fill face indexes
	indexes.reserve(3*mesh->mNumFaces);

	for (unsigned int i=0; i<mesh->mNumFaces; i++)
	{
		// Assume the model has only triangles.
		indexes.push_back(mesh->mFaces[i].mIndices[0]);
		indexes.push_back(mesh->mFaces[i].mIndices[1]);
		indexes.push_back(mesh->mFaces[i].mIndices[2]);
	}
	
	// The "scene" pointer will be deleted automatically by "importer"
	return true;
}
