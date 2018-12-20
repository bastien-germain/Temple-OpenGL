#pragma once
#ifndef __POSITION_OBSERVABLE_HPP__
#define __POSITION_OBSERVABLE_HPP__

#include <vector>
#include <algorithm>
#include <moteurJeu/PositionObserver.hpp>
#include <moteurJeu/Exception.hpp>
#include <iostream>



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
	virtual unsigned int posX() const;

	inline std::vector<PositionObserver*> observers() const 
	{
		return _observers;
	}

	void notify();
};

#endif