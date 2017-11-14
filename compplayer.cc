#include "compplayer.h"
#include "gameboard.h"
using namespace std;

//Constructor for CompPlayer class
CompPlayer :: CompPlayer(GameBoard* g, int currentPos, char name, int cash, int numOfProp, bool jailed, bool isComp, string realName) :
	Player(currentPos, name, cash, numOfProp, jailed, isComp, realName), g(g)
{
	this->pa = new Player*[6];
	this->paSize = 0;
	
	for (int i = 0; i < 6; ++i)
	{
		this->pa[i] = NULL;
	}
}

//Destructor for CompPlayer class
CompPlayer :: ~CompPlayer()
{
	delete [] pa;
	pa = NULL;
}

//Adds Player pointers to pa
void CompPlayer :: AddPlayer(Player* p)
{
	this->pa[this->paSize] = p;
	this->paSize += 1;
}

//Finds and returns a pointer to the Player specified by pName
//Returns a NULL pointer otherwise
Player* CompPlayer :: FindPlayer(char pName)
{
	for (int i = 0; i < 6; ++i)
	{
		if (this->pa[i]->GetBankrupt() != true && this->pa[i]->GetName() == pName)
		{
			return this->pa[i];
		}
	}
	
	return NULL;
}

//Bankrupts the current CompPlayer
void CompPlayer :: CompBankrupt()
{
	Player* owedTo;

	//Returns everything to the bank
	if (GetOwedPlayer() == '!')
	{
		SellAllImprovements();
		SetCurrentPos(GetCurrentPos());
		SetBankrupt(true);
		this->g->ChangeBoard(this);
		RemoveAllProp();
		SetCash(0);
		SetOwedPlayer(' ');
		SetDebt(0);
	}
	//Gives all property and cash to owedPlayer
	else
	{
		owedTo = FindPlayer(GetOwedPlayer());
		SetCurrentPos(GetCurrentPos());
		SetBankrupt(true);
		this->g->ChangeBoard(this);
		owedTo->AddCash(GetCash());
		SwapAllProp(owedTo);
		SetCash(0);
		SetOwedPlayer(' ');
		SetDebt(0);
	}
}

//Computer player trades only if it receives value greater than what it gives up
void CompPlayer :: TradeDecision(Player* pg, Property* gp, Property* rp)
{
	if (rp->GetCost() > gp->GetCost())
	{
		cout << "The trade was unsuccessful." << endl;
	}
	else
	{
		RemoveProp(rp->GetName());
		pg->RemoveProp(gp->GetName());
		AddProp(gp);
		pg->AddProp(rp);
		cout << "The trade was successful." << endl;
	}
}	

//Computer player trades only if it receives value greater than what it gives up
void CompPlayer :: TradeDecision(Player* pg, Property* gp, int rm)
{
	if (rm > gp->GetCost())
	{
		cout << "The trade was unsuccessful." << endl;
	}
	else
	{
		AddCash(-1 * rm);
		pg->RemoveProp(gp->GetName());
		AddProp(gp);
		pg->AddCash(rm);
		cout << "The trade was successful." << endl;
	}
}

//Computer player trades only if it receives value greater than what it gives up
void CompPlayer :: TradeDecision(Player* pg, int gm, Property* rp)
{
	if (rp->GetCost() > gm)
	{
		cout << "The trade was unsuccessful." << endl;
	}
	else
	{
		AddCash(gm);
		RemoveProp(rp->GetName());
		pg->AddCash(-1 * gm);
		pg->AddProp(rp);
		cout << "The trade was successful." << endl;
	}
}

//Computer player trades only if it receives value greater than what it gives up
void CompPlayer :: TradeDecision(Player* pg, int gm, int rm)
{
	if (rm > gm)
	{
		cout << "The trade was unsuccessful." << endl;
	}
	else
	{
		AddCash(gm);
		AddCash(-1 * rm);
		pg->AddCash(rm);
		pg->AddCash(-1 * gm);
		cout << "The trade was successful." << endl;
	}
}

//Computer player will only unmortgage a property immediately if it has enough cash
void CompPlayer :: UnmortgageDecision()
{
	if (GetCash() >= this->prop[this->numOfProp - 1]->GetCost() / 2)
	{
		AddCash(-1 * this->prop[this->numOfProp - 1]->GetCost() / 2);
		this->prop[this->numOfProp - 1]->ChangeMortgage();
		cout << GetName() << " has unmortgaged " << this->prop[this->numOfProp - 1]->GetName() << "!" << endl;
	}
}

//Computer player buys a property if it has enough cash
void CompPlayer :: BuyDecision(Property* prpty)
{
	if (GetCash() >= prpty->GetCost() && prpty->GetOwner() == ' ')
	{
		AddCash(-1 * prpty->GetCost());
		AddProp(prpty);
		cout << GetName() << " has just purchased " << prpty->GetName() << "!" << endl;
	}
}

//Computer decides on how to escape jail
void CompPlayer :: JailDecision()
{
	//Checks if it possess a Tim's Card to use
	if (GetTimsCard() > 0)
	{
		SetTimsCard(GetTimsCard() - 1);
		g->RemoveTimsCard();
		srand(time(NULL));
		SetDie1(rand() % 6 + 1);
		SetDie2(rand() % 6 + 1);
		SetRollCount(GetRollCount() + 1);
		cout << GetName() << " has escaped the DC Tim's Line!" << endl;
		cout << GetName() << " has rolled " << GetDie1() << " and " << GetDie2() << "!" << endl;
		g->Move(this);
	}
	//Checks if it possesses enough cash to pay off fine
	else if (GetCash() >= 50)
	{
		AddCash(-50);
		srand(time(NULL));
		SetDie1(rand() % 6 + 1);
		SetDie2(rand() % 6 + 1);
		SetRollCount(GetRollCount() + 1);
		cout << GetName() << " has escaped the DC Tim's Line!" << endl;
		cout << GetName() << " has rolled " << GetDie1() << " and " << GetDie2() << "!" << endl;
		g->Move(this);
	}
	else
	{
		cout << GetName() << " declares bankruptcy!" << endl;
		CompBankrupt();
	}
}

//Plays the game in automation mode based on a very simple algorithm
void CompPlayer :: PlayGame()
{
	bool madeTrade = false;
	Player* owedTo;
	
	if (GetJailed())
	{
		JailDecision();
	}
	else
	{
		//Roll dice for computer player
		srand(time(NULL));
		SetDie1(rand() % 6 + 1);
		SetDie2(rand() % 6 + 1);
		SetRollCount(GetRollCount() + 1);
		cout << GetName() << " has rolled " << GetDie1() << " and " << GetDie2() << "!" << endl;
		g->Move(this);
	}
	
	if (GetDebt() > GetCash())
	{
		CompBankrupt();
	}
	else if (GetDebt() > 0)
	{
		if (GetOwedPlayer() == '!')
		{
			AddCash(-1 * GetDebt());
			SetDebt(0);
		}
		else
		{
			owedTo = FindPlayer(this->GetOwedPlayer());
			AddCash(-1 * GetDebt());
			owedTo->AddCash(GetDebt());
		}
	}
	
	//Build one improvement if possible
	for (int i = 0; i < this->numOfProp; ++i)
	{
		if (prop[i]->CanBuild() && GetCash() >= prop[i]->GetUpgradeCost())
		{
			prop[i]->AddImprovement();
			AddCash(prop[i]->GetUpgradeCost() * -1);
			break;
		}
	}
	
	//Try to make trade for property with cash
	for (int i = 0; i < this->paSize; ++i)
	{
		if (this->pa[i] != this)
		{
			for (int n = 0; n < this->pa[i]->numOfProp; ++n)
			{
			
				if (!(this->pa[i]->prop[n]->IsMortgaged()) && GetCash() >= this->pa[i]->prop[n]->GetCost() * 0.5)
				{
					cout << GetName() << ", would like to trade $" << this->pa[i]->prop[n]->GetCost() * 0.5 << " for " << this->pa[i]->prop[n]->GetName() << "! [accept/reject]" << endl;
					this->pa[i]->TradeDecision(this, this->pa[i]->prop[n]->GetCost() * 0.5, this->pa[i]->prop[n]);
					madeTrade = true;
					break;
				}
				
			}
		}
		
		if (madeTrade)
			break;
	}
}
