#ifndef _OSAP_H_
#define _OSAP_H_

#include "notbuyable.h"
#include "player.h"
#include <string>
class Player;

class Osap : public NotBuyable{
	public:
		Osap(std::string n);
		~Osap();
		void React(Player * p);
		void DecrementTimsCard();
};
#endif