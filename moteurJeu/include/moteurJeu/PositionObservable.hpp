#pragma once
#ifndef __POSITION_OBSERVABLE_HPP__
#define __POSITION_OBSERVABLE_HPP__

#include <vector>
#include <algorithm>
#include <iostream>

#include "moteurJeu/PositionObserver.hpp"
#include "moteurJeu/Exception.hpp"

class PositionObserver;

class PositionObservable 
{

protected:
	std::vector<PositionObserver*> _observers;
public:
	PositionObservable();
	virtual ~PositionObservable();

	void addPositionObserver(PositionObserver *observer);
	void removePositionObserver(const PositionObserver *observer);

	virtual float posZ() const;
	virtual int posX() const;
	virtual int sizeX() const;
	virtual int sizeY() const;

	virtual bool hasCollided() const;
	virtual void collide();

	inline std::vector<PositionObserver*> observers() const 
	{
		return _observers;
	}

	void notify();
};

#endif