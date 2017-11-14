#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include <string>
#include <iostream>
#include "player.h"
#include "property.h"
using namespace std;

class HumanPlayer : public Player
{
	public:
		HumanPlayer(int currentPos, char name, int cash, int numOfProp, bool jailed, bool isComp, string realName);
		void DisplayAssets();
		void TradeDecision(Player* pg, Property* gp, Property* rp);
		void TradeDecision(Player* pg, Property* gp, int rm);
		void TradeDecision(Player* pg, int gm, Property* rp);
		void TradeDecision(Player* pg, int gm, int rm);
		void UnmortgageDecision();
};

#endif
