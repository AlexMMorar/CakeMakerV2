#include"RecipeCake.h"

RecipeCake::RecipeCake(std::string name, int time)
{
	this->name = name;
	this->time = time;
}
std::string RecipeCake::getName()
{
	return this->name;
}
int RecipeCake::getTime()
{
	return this->time;
}