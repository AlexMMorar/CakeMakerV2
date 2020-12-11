#pragma once
#include"RecipeCake.h"
#include"CakeMaker.h"
#include"Cake.h"
#include"CarouselOfCakes.h"

class CommandTaker {
private:
	RecipeCake* carouselRecipe;
	CakeMaker* cakeMaker;
	CarouselOfCakes* carousel;

	bool checkCarouselOfCakes();
	bool refillCarousel();
public:
	CommandTaker();
	Cake* takeCommand(RecipeCake* recipe);
	std::list<Cake*> takeCommand(RecipeCake* recipe, int numberOfProducts);
	std::list<Cake*> getCarouselOfCakes();
	void checkForRefill();
};