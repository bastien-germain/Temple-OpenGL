#include "moteurJeu/PositionObservable.hpp"

PositionObservable::PositionObservable() 
{
}

PositionObservable::~PositionObservable()
{
}

void PositionObservable::addPositionObserver(PositionObserver *observer) 
{	
	if (observer)
	{
		std::cout << "POSITION_OBSERVER ADDING STARTS..." << std::endl;
		_observers.push_back(observer);
		observer->addPositionObservable(this);
		std::cout << "OBSERVABLES : " << observer->observables().size() << std::endl;
		std::cout << "OBSERVERS : " << _observers.size() << std::endl;
	}
}

void PositionObservable::removePositionObserver(const PositionObserver *observer) 
{
 	std::vector<PositionObserver*>::iterator it;

  	it = find(_observers.begin(), _observers.end(), observer);
 	
 	if (it != _observers.end())
 	{
 		(*it)->removePositionObservable(this);
 		_observers.erase(it);   	
 	}
  	else
  	{
  		THROW_EXCEPTION("OBJECT_NOT_FOUND_ERROR : Can't remove PositionObserver from this PositionObservable (does not exist)");
  	}
}

float PositionObservable::posZ() const 
{
}

int PositionObservable::posX() const
{
}

void PositionObservable::notify()
{
	std::cout << "*** OBSERVABLE NOTIFY " << std::endl;
	std::vector<PositionObserver*>::iterator it;

	std::cout << "### OBSERVER VECTOR SIZE : " << _observers.size()	<< std::endl;

	for (it = _observers.begin(); it!= _observers.end(); ++it) 
	{
		std::cout << "*** OBSERVABLE NOTIFY LAUNCHES UPDATE " << std::endl;
		std::cout << "### OBSERVER POINTER : " << *it << std::endl;
		(*it)->observerUpdate(this);
	}	
}