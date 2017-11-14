#include "humanplayer.h"
using namespace std;

//Constructor for HumanPlayer class
HumanPlayer :: HumanPlayer(int currentPos, char name, int cash, int numOfProp, bool jailed, bool isComp, string realName) :
	Player(currentPos, name, cash, numOfProp, jailed, isComp, realName) {}

//Displays all cash and assets that current HumanPlayer object owns
void HumanPlayer :: DisplayAssets()
{
	//Displays name and cash on hand
	cout << this->name << " has $" << this->cash << endl;
	
	//Displays name and total worth
	cout << this->name << " has a total worth of $" << this->TotalWorth() << endl;
	
	//Loop prop and display contents
	cout << this->name << " has the following properties (format: name of property, mortgage value of property, number of improvements made on property, and mortgage value of one improvement)." << endl;
	for (int i = 0; i < numOfProp; ++i)
	{
		cout << this->prop[i]->GetName() << " " << this->prop[i]->GetCost() / 2 << " " << this->prop[i]->GetCurrentImprovements() << " " << this->prop[i]->GetUpgradeCost() / 2 << endl;
	}
}

//Accepts or rejects trade and performs required actions for two properties
void HumanPlayer :: TradeDecision(Player* pg, Property* gp, Property* rp)
{
	string input;
	
	while (cin >> input)
	{
		//Ends the function if trade rejected
		if (input == "reject")
		{
			cout << "The trade was unsuccessful." << endl;
			break;
		}
		//Performs trade if accepted
		else if (input == "accept")
		{
			RemoveProp(rp->GetName());
			pg->RemoveProp(gp->GetName());
			AddProp(gp);
			pg->AddProp(rp);
			cout << "The trade has been successfully made!" << endl;
			break;
		}
	}
}

//Accepts or rejects trade and performs required actions for giving up property and receiving money
void HumanPlayer :: TradeDecision(Player* pg, Property* gp, int rm)
{
	string input;
	
	while (cin >> input)
	{
		//Ends the function if trade rejected
		if (input == "reject")
		{
			cout << "The trade was unsuccessful." << endl;
			break;
		}
		//Performs trade if accepted
		else if (input == "accept")
		{
			pg->RemoveProp(gp->GetName());
			AddCash(-1 * rm);
			pg->AddCash(rm);
			AddProp(gp);
			cout << "The trade has been successfully made!" << endl;
			break;
		}
	}
}

//Accepts or rejects trade and performs required actions for giving up property and receiving money
void HumanPlayer :: TradeDecision(Player* pg, int gm, Property* rp)
{
	string input;
	
	while (cin >> input)
	{
		//Ends the function if trade rejected
		if (input == "reject")
		{
			cout << "The trade was unsuccessful." << endl;
			break;
		}
		//Performs trade if accepted
		else if (input == "accept")
		{
			RemoveProp(rp->GetName());
			AddCash(gm);
			pg->AddCash(-1 * gm);
			pg->AddProp(rp);
			cout << "The trade has been successfully made!" << endl;
			break;
		}
	}
}

//Accepts or rejects trade an performs required actions for trading money
void HumanPlayer :: TradeDecision(Player* pg, int gm, int rm)
{
	string input;
	
	while (cin >> input)
	{
		//Ends the function if trade rejected
		if (input == "reject")
		{
			cout << "The trade was unsuccessful." << endl;
			break;
		}
		//Performs trade if accepted
		else if (input == "accept")
		{
			AddCash(gm);
			AddCash(-1 * rm);
			pg->AddCash(rm);
			pg->AddCash(-1 * gm);
			cout << "The trade has been successfully made!" << endl;
			break;
		}
	}
}

//Unmortgages a property immediately if the player chooses to do so
void HumanPlayer :: UnmortgageDecision()
{
	string input;
	
	cout << GetName() << ", would you like to unmortgage " << this->prop[this->numOfProp - 1]->GetName() << " immediately? [yes/no]: ";
	while (cin >> input)
	{
		if (input == "no")
		{
			break;
		}
		else if (input == "yes")
		{
			//Check if player has enough cash to unmortgage
			if (GetCash() < this->prop[this->numOfProp - 1]->GetCost() / 2)
			{
				cout << "Sorry, you do not have enough cash! The unmortgage value has been added to your debt! Please use the pay command afterwards to make a payment to the bank!" << endl;
				SetDebt(GetDebt() + (-1 * this->prop[this->numOfProp - 1]->GetCost() / 2));
				this->prop[this->numOfProp - 1]->ChangeMortgage();
				break;
			}
			else
			{
				AddCash(-1 * this->prop[this->numOfProp - 1]->GetCost() / 2);
				this->prop[this->numOfProp - 1]->ChangeMortgage();
				break;
			}
		}
	}
}
