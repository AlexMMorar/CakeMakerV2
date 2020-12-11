#pragma once
#include<string>


class RecipeCake {
 
private:
	std::string name;
	int time; //milliseconds
public:
	RecipeCake(std::string name, int time);
	std::string getName();
	int getTime();
};