#pragma once
#ifndef __LIGHTING_MODEL_HPP__
#define __LIGHTING_MODEL_HPP__

#include "moteurRendu/Light.hpp"
#include "moteurRendu/Model.hpp"

/// \class LightingModel
/// \brief Class defining a LightingModel : inherits Model
class LightingModel : public Model
{

private:
	Light _light; /*! The Light used for this LightingModel */
	
public:
	/// \brief Default constructor
	LightingModel();

	/// \brief Constructor from a VBO, a VAO, a Light, and a Texture
	/// \param vbo : the vbo of the model
	/// \param light : the light of the model
	/// \param texture : the texture of the model
	LightingModel(const VBO &vbo, const Light &light, const Texture &texture);

	/// \brief Copy constructor using another LightingModel
	/// \param copied : the copied LightingModel
	LightingModel(const LightingModel &copied);

	inline LightingModel &operator = (const LightingModel &toAssign) {

		if (&toAssign != this) 
		{
			_vbo = toAssign._vbo;
			_light = toAssign._light;
			_texture = toAssign._texture;
		}

		return *this;
	}

	/// \brief Destructor
	~LightingModel();

};

#endif