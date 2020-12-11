#include "CarouselOfCakes.h"

CarouselOfCakes::CarouselOfCakes()
{
}

bool CarouselOfCakes::addCake(Cake* cake)
{
	if (this->storage.size() < this->maxCapacity)
	{
		this->storage.push_back(cake);
		return true;
	}
	else
	{
		return false;
	}
}

Cake* CarouselOfCakes::getCake()
{
	Cake* cake = storage.front();
	storage.remove(cake);
	return cake;
}

int CarouselOfCakes::getCurrentCapacity()
{
	return storage.size();
}

std::list<Cake*> CarouselOfCakes::getListOfCakes()
{
	return storage;
}

int CarouselOfCakes::getLowLimit()
{
	return this->lowCapacity;
}

int CarouselOfCakes::getMaxLimit()
{
	return this->maxCapacity;
}
