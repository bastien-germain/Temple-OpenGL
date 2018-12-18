#pragma once
#ifndef __OBSERVABLE_HPP__
#define __OBSERVABLE_HPP__

#include <vector>
#include <algorithm>
#include <moteurJeu/Observer.hpp>
#include <moteurJeu/Exception.hpp>

class Observer;

class Observable 
{

protected:
	std::vector<Observer*> _observers;
public:
	Observable();
	virtual ~Observable() = 0;

	void addObserver(Observer *observer);
	void removeObserver(const Observer *observer);

	void notify();
};

#endif