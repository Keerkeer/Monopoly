#ifndef _BUYABLE_H_
#define _BUYABLE_H_
class Player;
#include "property.h"
#include <string>
class Buyable: public Property{
	char owner;
	int cost;
	bool mortgaged;
	public:
	Property * block1;
	Property * block2; 
	Property * block3;
	bool CanBuild();
	void ChangeMortgage();
	bool IsMortgaged();
	int GetCost();
	bool CanTrade();
	
	int GetCurrentImprovements();
	virtual void React(Player * p)= 0;
	void AddNeighbour(Property * b);
	char GetOwner();
	void SetOwner(char c);
	Buyable(char o, int c, std::string n);
	~Buyable();
};
#endif
