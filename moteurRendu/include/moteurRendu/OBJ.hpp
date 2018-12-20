#pragma once
#ifndef __OBJ_HPP__
#define __OBJ_HPP__

// Include AssImp
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h> 	// Post processing flags
#include <vector>
#include <iostream>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"
#include <glimac/FilePath.hpp>


/// \class OBJ
class OBJ 
{

private:
	const glimac::FilePath _path;
public:
	OBJ(const glimac::FilePath &path);

	~OBJ();

	const bool loadAssimp(std::vector<uint32_t> indexes, std::vector<glimac::ShapeVertex> &vertices) const;


private:

};

#endif