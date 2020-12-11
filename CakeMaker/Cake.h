#pragma once
#include<string>


class Cake {
private:
	std::string name;

public:
	Cake(std::string name);
	std::string getName();
};