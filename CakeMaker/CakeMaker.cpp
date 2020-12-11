#include "CakeMaker.h"
#include<iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

using namespace std;

CakeMaker::CakeMaker()
{
}

Cake* CakeMaker::takeCommand(RecipeCake* recipe)
{
	cout << "Command received! " << recipe->getName() << " will be done in " << recipe->getTime() / 1000 << " seconds!" << endl;
	
	int timeToCook = recipe->getTime();
	Sleep(timeToCook);

	return new Cake(recipe->getName());
}
