#include "CommandTaker.h"
#include <iostream>

bool CommandTaker::checkCarouselOfCakes()
{
	if (carousel->getCurrentCapacity() < carousel->getLowLimit())
		return true;

	return false;
}

bool CommandTaker::refillCarousel()
{
	int cakeToRefill = carousel->getMaxLimit() - carousel->getCurrentCapacity();
	for (int i = 0; i < cakeToRefill; i++)
	{
		Cake* carouselCake = cakeMaker->takeCommand(this->carouselRecipe);
		carousel->addCake(carouselCake);
	}
	return true;
}

CommandTaker::CommandTaker()
{
	this->cakeMaker = new CakeMaker();
	this->carousel = new CarouselOfCakes();
	this->carouselRecipe = new RecipeCake("Savarina", 1000);
	
	for (int i = 0; i < carousel->getMaxLimit(); i++)
	{
		//Cake* cake = cakeMaker->takeCommand(carouselRecipe);
		carousel->addCake(new Cake("Savarina"));
	}
}

Cake* CommandTaker::takeCommand(RecipeCake* recipe)
{
	if (carouselRecipe->getName() == recipe->getName() && carousel->getCurrentCapacity() != 0)
	{
		return carousel->getCake();
	}
	else
	{
		return cakeMaker->takeCommand(recipe);
	}
}

std::list<Cake*> CommandTaker::takeCommand(RecipeCake* recipe, int numberOfProducts)
{
	std::list<Cake*> listOfCommand;
	for (int i = 0; i < numberOfProducts; i++)
	{
		Cake* cake = this->takeCommand(recipe);
		listOfCommand.push_back(cake);
	}

	return listOfCommand;
}

std::list<Cake*> CommandTaker::getCarouselOfCakes()
{
	return this->carousel->getListOfCakes();
}

void CommandTaker::checkForRefill()
{
	if (checkCarouselOfCakes())
	{
		std::cout << "Refill carousel with cakes!" << std::endl;
		refillCarousel();
	}

}
