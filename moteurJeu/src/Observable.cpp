#include <moteurJeu/Observable.hpp>

Observable::Observable() 
{

}

Observable::~Observable()
{

}

void Observable::addObserver(Observer *observer) 
{
	_observers.push_back(observer);	
}

void Observable::removeObserver(const Observer *observer) 
{
 	std::vector<Observer*>::iterator it;

  	it = find(_observers.begin(), _observers.end(), observer);
 	
 	if (it != _observers.end())
 		_observers.erase(it);    	
  	else
  		THROW_EXCEPTION("OBJECT_NOT_FOUND_ERROR : Can't remove Observer from this Observable (does not exist)");
}

void Observable::notify()
{
	std::vector<Observer*>::iterator it;

	for (it = _observers.begin(); it!= _observers.end(); ++it) {
		(*it)->update();
	}	
}