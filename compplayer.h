#ifndef __COMPPLAYER_H__
#define __COMPPLAYER_H__

#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
class GameBoard;
#include "player.h"
#include "property.h"
using namespace std;

class CompPlayer : public Player
{
	private:
		GameBoard* g;
		Player** pa;
		int paSize;
	
	public:
		CompPlayer(GameBoard* g, int currentPos, char name, int cash, int numOfProp, bool jailed, bool isComp, string realName);
		~CompPlayer();
		void AddPlayer(Player* p);
		Player* FindPlayer(char pName);
		void CompBankrupt();
		void TradeDecision(Player* pg, Property* gp, Property* rp);
		void TradeDecision(Player* pg, Property* gp, int rm);
		void TradeDecision(Player* pg, int gm, Property* rp);
		void TradeDecision(Player* pg, int gm, int rm);
		void UnmortgageDecision();
		void BuyDecision(Property* prpty);
		void JailDecision();
		void PlayGame();
};

#endif
