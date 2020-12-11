#include <iostream>
#include "CommandPanel.h"

using namespace std;

int main()
{
	CommandPanel* commandPanel = new CommandPanel();

	int opt;
	string name;
	int number;
	do 
	{
		cout << "1. Show Menu" << endl;
		cout << "2. Show carousel cakes" << endl;
		cout << "3. Select product" << endl;
		cout << "4. Select products" << endl;
		cout << "0. Exit" << endl;
		cout << "Your order is: ";
		cin >> opt;
		switch (opt) {
		case 1:
			commandPanel->showMenu();
			break;
		case 2:
			commandPanel->showProductsInCarousel();
			break;
		case 3:
			cout << "Give the name of the product: ";
			cin >> name;
			commandPanel->selectProduct(name);
			commandPanel->checkForRefill();
			break;
		case 4:
			cout << "Give the name of the product: ";
			cin >> name;
			cout << "Give the number of the products wanted: ";
			cin >> number;
			commandPanel->selectProduct(name, number);
			commandPanel->checkForRefill();
			break;
		default:
			break;
		}	
	} while (opt != 0);
	return 0;
}