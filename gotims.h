#ifndef _GOTIMS_H_
#define _GOTIMS_H_

#include "notbuyable.h"
#include <string>
class Player;

class GoTims: public NotBuyable{
	public:
		void React(Player * p);
		GoTims(std::string n);
		~GoTims();
};
#endif