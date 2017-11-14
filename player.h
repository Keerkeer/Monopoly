#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include <iostream>
#include "property.h"
using namespace std;

class Player
{
	protected:
		int oldPos;
		int currentPos;
		char name;
		int cash;
		int die1;
		int die2;
		int debt;
		int rollCount;
		int timsCard;
		bool jailed;
		bool bankrupt;
		char owedPlayer;
		
	public:
		int numOfProp;
		const bool isComp;
		string realName;
		Property** prop;
	
		Player(int currentPos, char name, int cash, int numOfProp, bool jailed, bool isComp, string realName);
		~Player();
		virtual void TradeDecision(Player* pg, Property* gp, Property* rp) = 0;
		virtual void TradeDecision(Player* pg, Property* gp, int rm) = 0;
		virtual void TradeDecision(Player* pg, int gm, Property* rp) = 0;
		virtual void TradeDecision(Player* pg, int gm, int rm) = 0;
		virtual void UnmortgageDecision() = 0;
		virtual void BuyDecision(Property*);
		void AddProp(Property* newProp);
		void RemoveProp(string propName);
		int GetCurrentPos();
		void SetCurrentPos(int position);
		int GetOldPos();
		void SetOldPos(int position);
		char GetName();
		void SetName(char newName);
		int GetCash();
		void SetCash(int amount);
		int GetDie1();
		void SetDie1(int num);
		int GetDie2();
		void SetDie2(int num);
		void AddPos(int spaces);
		void AddCash(int amount);
		int TotalWorth();
		int GetDebt();
		void SetDebt(int amount);
		int GetRollCount();
		void SetRollCount(int num);
		int GetTimsCard();
		void SetTimsCard(int);
		bool GetJailed();
		void SetJailed(bool);
		bool GetBankrupt();
		void SetBankrupt(bool);
		char GetOwedPlayer();
		void SetOwedPlayer(char name);
		bool HasProp(string propName);
		void SellAllImprovements();
		void RemoveAllProp();
		void SwapAllProp(Player* p);
		virtual void DisplayAssets();
		virtual void PlayGame();
		virtual void AddPlayer(Player* p);
		void AddSpaces(int num);
};

#endif
