#pragma once
#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "glimac/glm.hpp"

#include "moteurRendu/Model.hpp"

/// \class Enemy
/// \brief Enemy pursuing the player
class Enemy 
{

private:
	unsigned int _distanceToPlayer; // si = 0 --> fin de partie
	Model *_model;
	//float _size; // à voir si ça sert
	
public:
	Enemy();
	Enemy(const Enemy &copied);
	
	~Enemy();

	/// \brief Getter score
	inline unsigned int distanceToPlayer() const 
	{
		return _distanceToPlayer;
	}

	inline const Model *model() const 
	{
		return _model;
	}

	inline void model(Model *model) 
	{
		_model = model;
	}

};

#endif