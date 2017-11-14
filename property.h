#ifndef _PROPERTY_H_
#define _PROPERTY_H_
class Player;
#include <string>
class Property{
	std::string name;
	public:
	std::string GetName();
	virtual char GetOwner();
	virtual void React(Player* p) = 0;
	virtual int GetCost();
	virtual bool CanTrade();
	virtual bool IsMortgaged();
	virtual int AddImprovement();
	virtual int RemoveImprovement();
	virtual int GetCurrentImprovements();
	virtual void SetImprovements(int i);
	virtual bool CanBuild();
	virtual void ChangeMortgage();
	virtual int GetUpgradeCost();
	virtual void AddNeighbour(Property*);
	virtual void DecrementTimsCard();
	virtual void SetOwner(char c);
	Property(std::string s);
	~Property();
};
#endif

