#include "dctimsline.h"
#include <iostream>
#include <string>
#include "player.h"

void DCTimsLine::React(Player *p){
	std::cout << "Starbucks is better" << std::endl;
}
DCTimsLine :: DCTimsLine(std::string n) : NotBuyable(n) {}
DCTimsLine::~DCTimsLine() {}
