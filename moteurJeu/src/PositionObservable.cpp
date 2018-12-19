#include <moteurJeu/PositionObservable.hpp>

PositionObservable::PositionObservable() 
{
}

PositionObservable::~PositionObservable()
{
}

void PositionObservable::addPositionObserver(PositionObserver *observer) 
{	
	std::cout << "POSITION_OBSERVER ADDING STARTS..." << std::endl;
	_observers.push_back(observer);	
}

void PositionObservable::removePositionObserver(const PositionObserver *observer) 
{
 	std::vector<PositionObserver*>::iterator it;

  	it = find(_observers.begin(), _observers.end(), observer);
 	
 	if (it != _observers.end())
 		_observers.erase(it);    	
  	else
  		THROW_EXCEPTION("OBJECT_NOT_FOUND_ERROR : Can't remove PositionObserver from this PositionObservable (does not exist)");
}

float PositionObservable::posZ() const 
{
}

unsigned int PositionObservable::posX() const
{
}

void PositionObservable::notify()
{
	std::vector<PositionObserver*>::iterator it;
	for (it = _observers.begin(); it!= _observers.end(); ++it) 
	{
		(*it)->observerUpdate(this);
	}	
}