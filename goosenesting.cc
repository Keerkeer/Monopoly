#include "goosenesting.h"
#include <iostream>
#include <string>
#include "player.h"

void GooseNesting::React(Player * p){
	std::cout << "You have landed on a goose nesting " << std::endl;
	std::cout << "You have been attacked LULULULUCAWCAWCAWCAW" << std::endl;
}
GooseNesting::GooseNesting(std::string n):NotBuyable(n){}
GooseNesting::~GooseNesting() {}
