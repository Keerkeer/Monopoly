#ifndef _GOOSENESTING_H_
#define _GOOSENESTING_H_

#include "notbuyable.h"
#include <string>
class Player;

class GooseNesting: public NotBuyable{
	public:
		void React(Player* p);
		GooseNesting(std::string n);
		~GooseNesting();
};
#endif
