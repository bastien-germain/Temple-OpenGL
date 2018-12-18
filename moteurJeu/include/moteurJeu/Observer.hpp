#pragma once
#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <vector>
#include <algorithm>
#include <moteurJeu/Observable.hpp>
#include <moteurJeu/Exception.hpp>

class Observable;

class Observer 
{

protected:
	std::vector<Observable*> _observables;
public:
	Observer();
	virtual ~Observer() = 0;

	void addObservable(Observable *observable);
	void removeObservable(const Observable *observable);

	virtual void update() const;

};

#endif