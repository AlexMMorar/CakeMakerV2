#pragma once
#include"RecipeCake.h"
#include"Cake.h"
#include<list>

class CarouselOfCakes {

private:
	std::list<Cake*> storage;
	const int maxCapacity = 10;
	const int lowCapacity = 3;

public:
	CarouselOfCakes();
	bool addCake(Cake*);
	Cake* getCake();
	int getCurrentCapacity();
	std::list<Cake*> getListOfCakes();
	int getLowLimit();
	int getMaxLimit();
	
};