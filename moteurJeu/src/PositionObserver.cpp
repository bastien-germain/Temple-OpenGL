#include "moteurJeu/PositionObserver.hpp"

PositionObserver::PositionObserver() 
{

}

PositionObserver::~PositionObserver()
{

}

void PositionObserver::addPositionObservable(PositionObservable *observable) 
{
	if(observable)
		_observables.push_back(observable);	
}

void PositionObserver::removePositionObservable(const PositionObservable *observable) 
{
 	std::vector<PositionObservable*>::iterator it;

  	it = find(_observables.begin(), _observables.end(), observable);
 	
 	if (it != _observables.end())
 		_observables.erase(it);    	
  	else
  		THROW_EXCEPTION("OBJECT_NOT_FOUND_ERROR : Can't remove PositionObservable from this PositionObservable (does not exist)");
}

void PositionObserver::observerUpdate(const PositionObservable *observable) const 
{
	//std::cout << "*** OBSERVER UPDATE " << std::endl;	
}
