#ifndef _ACABUILDING_H_
#define _ACABUILDING_H_

#include "buyable.h"
class Player;
#include <string>
class AcademicBuilding: public Buyable{
	int upgradeCost;
	int zero, one, two, three, four, five;
	int improvements;
	public:
	bool CanBuild();
	bool CanTrade();
	void React(Player * p);
	int AddImprovement(Player* p);
	int RemoveImprovement(Player* p);
	int GetCurrentImprovements();
	void SetImprovements(int i);
	int GetUpgradeCost();
	AcademicBuilding(char o, int c, std::string n, int up, int zero, int one, int two, int three, int four, int five);
	~AcademicBuilding();
};
#endif
 
