#include "osap.h"
#include <iostream>
#include <string>
#include "player.h"

void Osap::React(Player * player){
	std::cout << "You have landed on OSAP" << std::endl;
}
Osap::Osap(std::string n):NotBuyable(n){}
Osap::~Osap() {}
void Osap::DecrementTimsCard(){
	NotBuyable::timsCards--;
}
