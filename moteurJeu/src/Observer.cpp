#include <moteurJeu/Observer.hpp>


Observer::Observer() 
{

}

Observer::~Observer()
{

}

void Observer::addObservable(Observable *observable) 
{
	_observables.push_back(observable);	
}

void Observer::removeObservable(const Observable *observable) 
{
 	std::vector<Observable*>::iterator it;

  	it = find(_observables.begin(), _observables.end(), observable);
 	
 	if (it != _observables.end())
 		_observables.erase(it);    	
  	else
  		THROW_EXCEPTION("OBJECT_NOT_FOUND_ERROR : Can't remove Observable from this Observable (does not exist)");
}

void Observer::update() const 
{
}
