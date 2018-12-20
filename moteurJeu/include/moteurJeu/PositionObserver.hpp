#pragma once
#ifndef __POSITION_OBSERVER_HPP__
#define __POSITION_OBSERVER_HPP__

#include <vector>
#include <algorithm>
#include <moteurJeu/PositionObservable.hpp>
#include <moteurJeu/Exception.hpp>

class PositionObservable;

class PositionObserver 
{

protected:
	std::vector<PositionObservable*> _observables;
public:
	PositionObserver();
	virtual ~PositionObserver() = 0;

	void addPositionObservable(PositionObservable *observable);
	void removePositionObservable(const PositionObservable *observable);

	virtual void observerUpdate(const PositionObservable *observable) const;

	inline std::vector<PositionObservable*> observables() const 
	{
		return _observables;
	}

};

#endif