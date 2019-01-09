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
		_observers.push_back(observer);
		observer->addPositionObservable(this);
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

float PositionObservable::posZ() const {}

int PositionObservable::posX() const {}

int PositionObservable::sizeX() const {}

int PositionObservable::sizeY() const {}

bool PositionObservable::hasCollided() const {}

void PositionObservable::collide() {}

void PositionObservable::notify()
{
	//std::cout << "*** OBSERVABLE NOTIFY " << std::endl;
	std::vector<PositionObserver*>::iterator it;

	for (it = _observers.begin(); it!= _observers.end(); ++it) 
	{
		//std::cout << "*** OBSERVABLE NOTIFY LAUNCHES UPDATE " << std::endl;
		(*it)->observerUpdate(this);
	}	
}