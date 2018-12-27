#pragma once
#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include "../../moteurRendu/include/moteurRendu/VAO.hpp"
#include "../../moteurRendu/include/moteurRendu/VBO.hpp"
#include "../../moteurRendu/include/moteurRendu/Light.hpp"
#include "../../moteurRendu/include/moteurRendu/Texture.hpp"

/// \class Model
/// \brief Class defining a Model
///  - A Model represents a 3D entity that will be displayed ;
class Model 
{

protected:
	VBO _vbo; /*! The VBO used for this Model */
	Texture _texture; /*! The Texture used for this Model */
	
public:
	/// \brief Default constructor
	Model();

	/// \brief Constructor from a VBO, a VAO, and a Texture
	/// \param vbo : the vbo of the model
	/// \param texture : the texture of the model
	Model(const VBO &vbo, const Texture &texture);

	/// \brief Copy constructor using another Model
	/// \param copied : the copied Model
	Model(const Model &copied);

	inline Model &operator = (const Model &toAssign) {

		if (&toAssign != this) 
		{
			_vbo = toAssign._vbo;
			_texture = toAssign._texture;
		}

		return *this;
	}

	/// \brief Destructor
	~Model();

};

#endif