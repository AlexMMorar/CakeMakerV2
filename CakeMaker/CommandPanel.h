#pragma once
#include<list>
#include"RecipeCake.h"
#include"CommandTaker.h"

class CommandPanel {

private:
	std::list<RecipeCake*> menu;
	CommandTaker* commandTaker;

public:
	CommandPanel();
	void showMenu();
	void showProductsInCarousel();
	void selectProduct(std::string name);
	void selectProduct(std::string name, int numberOfProducts);
	void checkForRefill();
};