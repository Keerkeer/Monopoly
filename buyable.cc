#include "buyable.h"
#include "player.h"
#include <string>
void Buyable::ChangeMortgage(){
	if (this->mortgaged == true){
		this->mortgaged = false;
	} else {
		this->mortgaged = true;
	}
}
bool Buyable::CanTrade(){
	return true;
}
void Buyable :: AddNeighbour(Property * b){
	if (block1){
		if (block2){
			block3 = b;
		} else {
			block2 = b;
		}
	} else {
		block1 = b;
	}
}
bool Buyable::IsMortgaged(){
	return this->mortgaged;
}
int Buyable::GetCost(){
	return this->cost;
}
char Buyable::GetOwner(){
	return this->owner;
}

void Buyable :: SetOwner(char c)
{
	this->owner = c;
}

int Buyable::GetCurrentImprovements(){
	return 0;
}

bool Buyable::CanBuild(){
	return false;
}

Buyable::Buyable(char o, int c, std::string n):Property(n), owner(o), cost(c), mortgaged(false), block1(NULL), block2(NULL), block3(NULL){}

Buyable::~Buyable(){}
