#include "CommandPanel.h"
#include <iostream>

using namespace std;

CommandPanel::CommandPanel()
{
	this->commandTaker = new CommandTaker();
	menu.push_back(new RecipeCake("Diplomat", 3000));
	menu.push_back(new RecipeCake("Budinca", 2000));
	menu.push_back(new RecipeCake("Rafaelo", 2000));
	menu.push_back(new RecipeCake("Savarina", 2000));
}

void CommandPanel::showMenu()
{
	for (auto it = menu.begin(); it != menu.end(); it++)
	{
		cout << (*it)->getName() << endl;
	}
}

void CommandPanel::showProductsInCarousel()
{
	std::list<Cake*> carouselCakes = commandTaker->getCarouselOfCakes();
	cout << "We have " << carouselCakes.size() << " of " << carouselCakes.front()->getName() << endl;
}

void CommandPanel::selectProduct(std::string name)
{
	RecipeCake* product = NULL;
	for (auto it = menu.begin(); it != menu.end(); it++)
	{
		if ((*it)->getName() == name)
		{
			product = (*it);
			break;
		}
	}
	Cake* cake = NULL;
	if (product != NULL)
	{
		cake = commandTaker->takeCommand(product);
	}
	else
	{
		cout << "The product " << name << " wasn't found!" << endl;
	}

	if(cake != NULL)
		cout << "Command " << cake->getName() << " it's ready to be served! " << endl;
}

void CommandPanel::selectProduct(std::string name, int numberOfProducts)
{
	RecipeCake* product = NULL;
	for (auto it = menu.begin(); it != menu.end(); it++)
	{
		if ((*it)->getName() == name)
		{
			product = (*it);
			break;
		}
	}
	std::list<Cake*> cakes;
	if (product != NULL)
	{
		cakes = commandTaker->takeCommand(product, numberOfProducts);
	}

	cout << "Command of " << numberOfProducts << " cakes are ready to be served!" << endl;
}

void CommandPanel::checkForRefill()
{
	this->commandTaker->checkForRefill();
}
