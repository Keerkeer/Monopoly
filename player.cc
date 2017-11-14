#include "player.h"
using namespace std;

//Constructor for Player class
Player :: Player(int currentPos, char name, int cash, int numOfProp, bool jailed, bool isComp, string realName) :
currentPos(currentPos), name(name), cash(cash), jailed(jailed), numOfProp(numOfProp), isComp(isComp), realName(realName)
{
	this->oldPos = 0;
	this->die1 = 0;
	this->die2 = 0;
	this->debt = 0;
	this->rollCount = 0;
	this->bankrupt = false;
	this->owedPlayer = ' ';

	//Set prop to NULL if numOfProp <= 0
	if (this->numOfProp > 0)
		this->prop = new Property*[this->numOfProp];
	else
		this->prop = NULL;
}

//Destructor for Player class
Player :: ~Player()
{
	delete [] this->prop;
	this->prop = NULL;
}

//Increases size of prop and adds pointer to new Property
void Player :: AddProp(Property* newProp)
{
	//Create tmpProp with increased size
	Property** tmpProp = new Property*[this->numOfProp + 1];

	//Copy prop values over to tmpProp along with the newest pointer
	for (int i = 0; i < numOfProp; ++i)
	{
		tmpProp[i] = this->prop[i];
		this->prop[i] = NULL;
	}
	newProp->SetOwner(GetName());
	tmpProp[this->numOfProp] = newProp;

	//Delete prop and set prop to tmpProp
	delete [] this->prop;
	
	this->prop = tmpProp;
	
	this->numOfProp += 1;
	
	
	if (this->prop[this->numOfProp - 1]->IsMortgaged())
	{
		SetDebt(GetDebt() + 0.1 * this->prop[this->numOfProp - 1]->GetCost());
		SetOwedPlayer('!');
		UnmortgageDecision();
	}
}

//Decrease the size of prop
void Player :: RemoveProp(string propName)
{
	Property** tmpProp;
	tmpProp = new Property*[this->numOfProp - 1];
	int index;

	//Find index of Property to be removed and set it to NULL
	for (index = 0; index < this->numOfProp; ++index)
	{
		if (this->prop[index]->GetName() == propName)
		{
			this->prop[index]->SetOwner('!');
			this->prop[index] = NULL;
			break;
		}
	}

	//Copy prop over to tmpProp
	for (int i = 0; i < index; ++i)
		tmpProp[i] = this->prop[i];
	
	for (int i = index + 1; i < this->numOfProp; ++i)
		tmpProp[i - 1] = this->prop[i];

	delete [] this->prop;
	this->prop = tmpProp;
	this->numOfProp -= 1;
}

//Gets currentPos value
int Player :: GetCurrentPos()
{
	return this->currentPos;
}

//Sets currentPos value
void Player :: SetCurrentPos(int position)
{
	this->oldPos = this->currentPos;
	this->currentPos = position;
}

//Gets oldPos value
int Player :: GetOldPos()
{
	return this->oldPos;
}

//Sets oldPos value
void Player :: SetOldPos(int position)
{
	this->oldPos = position;
}

//Gets name value
char Player :: GetName()
{
	return this->name;
}

//Sets name value
void Player :: SetName(char newName)
{
	this->name = newName;
}

//Gets currentPos value
int Player :: GetCash()
{
	return this->cash;
}

//Sets currentPos value
void Player :: SetCash(int amount)
{
	this->cash = amount;
}

//Gets die1 value
int Player :: GetDie1()
{
	return this->die1;
}

//Sets die1 value
void Player :: SetDie1(int num)
{
	this->die1 = num;
}

//Gets die2 value
int Player :: GetDie2()
{
	return this->die2;
}

//Sets die2 value
void Player :: SetDie2(int num)
{
	this->die2 = num;
}

//Adds die1 and die2 to currentPos
void Player :: AddSpaces(int spaces)
{
	this->oldPos = this->currentPos;
	this->currentPos = this->currentPos + spaces;
	
	if (this->currentPos < 0)
		this->currentPos += 40;
	
	if (this->currentPos >= 40)
	{
		cout << GetName() << " gains $200 for passing OSAP!" << endl;
		AddCash(200);
	}
	
	this->currentPos = this->currentPos % 40;
}

//Adds amount to cash
void Player :: AddCash(int amount)
{
	this->cash += amount;
}

//Sums cash, mortgage value of unmortgaged properties, and mortgage values of existing improvements
int Player :: TotalWorth()
{
	int mortgageValue = 0;
	
	//Loops through all properties and sums mortgage value
	for (int i = 0; i < this->numOfProp; ++i)
	{
		if (!(this->prop[i]->IsMortgaged()))
		{
			mortgageValue += this->prop[i]->GetCost() / 2;
			mortgageValue += this->prop[i]->GetCurrentImprovements() * (this->prop[i]->GetUpgradeCost() / 2);
		}
	}
	
	return this->cash + mortgageValue;
}

//Gets debt value
int Player :: GetDebt()
{
	return this->debt;
}

//Sets debt value
void Player :: SetDebt(int amount)
{
	this->debt = amount;
}

//Gets rollCount value
int Player :: GetRollCount()
{
	return this->rollCount;
}

//Sets rollCount value
void Player :: SetRollCount(int num)
{
	this->rollCount = num;
}

//Gets timsCard value
int Player :: GetTimsCard()
{
	return this->timsCard;
}

//Sets timsCard value
void Player :: SetTimsCard(int num)
{
	this->timsCard = num;
}

//Gets jailed value
bool Player :: GetJailed()
{
	return this->jailed;
}

//Sets jailed value
void Player :: SetJailed(bool tmpJailed)
{
	this->jailed = tmpJailed;
}

//Gets bankrupt value
bool Player :: GetBankrupt()
{
	return this->bankrupt;
}

//Sets bankrupt value
void Player :: SetBankrupt(bool tmpBankrupt)
{
	this->bankrupt = tmpBankrupt;
}

//Gets owedPlayer value
char Player :: GetOwedPlayer()
{
	return this->owedPlayer;
}

//Sets bankrupt value
void Player :: SetOwedPlayer(char name)
{
	this->owedPlayer = name;
}

//Checks if the current player has a property named propName
bool Player :: HasProp(string propName)
{
	for (int i = 0; i < numOfProp; ++i)
	{
		if (this->prop[i]->GetName() == propName)
			return true;
	}
	
	return false;
}

//Sells all improvements on all properties
void Player :: SellAllImprovements()
{
	//Loops through each property and sells all improvements
	for (int propCount = 0; propCount < numOfProp; ++propCount)
	{
		for (int impCount = 0; impCount < this->prop[propCount]->GetCurrentImprovements(); ++impCount)
		{
			AddCash(this->prop[propCount]->GetUpgradeCost() / 2);
			this->prop[propCount]->RemoveImprovement();
		}
	}
}

//Removes all property currently owned
void Player :: RemoveAllProp()
{
	for (int i = 0; i < numOfProp; ++i)
	{
		//Sets owner to the bank
		this->prop[i]->SetOwner('!');
		
		//Unmortgages it if it is mortgaged
		if (this->prop[i]->IsMortgaged())
			this->prop[i]->ChangeMortgage();
		
		RemoveProp(this->prop[i]->GetName());
	}
}

//Gives all current player property to p
void Player :: SwapAllProp(Player* p)
{
	Property* tmp;
	int i = 0;
	
	while (this->numOfProp > 0)
	{
		tmp = this->prop[i];
		RemoveProp(this->prop[i]->GetName());
		p->AddProp(tmp);
		
		if (tmp->IsMortgaged() == true)
		{
			p->SetOwedPlayer('!');
			p->SetDebt(p->GetDebt() + tmp->GetCost() * 1);
			p->UnmortgageDecision();
		}
		
		++i;
		tmp = NULL;
	}
}

//Both of these functions are empty
void Player :: DisplayAssets() {}
void Player :: PlayGame() {}
void Player :: BuyDecision(Property* prpty) {}
void Player :: AddPlayer(Player* p) {}
