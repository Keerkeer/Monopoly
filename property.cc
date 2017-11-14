#include "property.h"
#include "player.h"

Property::Property(std::string s){

	name = s;
}
void Property :: SetImprovements(int i){}
	
Property::~Property(){}

std::string Property::GetName(){
	return name;
}
char Property::GetOwner(){
	return '!';
}

int Property:: GetCost()
{
	return 0;
}
 bool Property::CanTrade(){
	return false;
}
bool Property::IsMortgaged(){
	return false;
}
int Property::AddImprovement(){
	cout << "You can not upgrade a residence or gym " << endl;
	return 0;
}
int Property::RemoveImprovement(){
	cout << "You can not downgrade a residence or gym " << endl;
	return 0;
}
 int Property::GetCurrentImprovements(){
	return 0;
}
bool Property::CanBuild(){
	return false;
}

void Property::ChangeMortgage(){}

int Property :: GetUpgradeCost(){
	return 0;
}

void Property :: AddNeighbour(Property* prpty) {}
void Property :: DecrementTimsCard() {}
void Property :: SetOwner(char c) {}
