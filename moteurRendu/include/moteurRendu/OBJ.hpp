#pragma once
#ifndef __OBJ_HPP__
#define __OBJ_HPP__

// Include AssImp
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
};

#endif