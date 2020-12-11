#include "Cake.h"

Cake::Cake(std::string name)
{
	this->name = name;
}

std::string Cake::getName()
{
	return this->name;
}
