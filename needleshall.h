#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include "notbuyable.h"
#include <string>
class Player;

class NeedlesHall: public NotBuyable{
	public:
		void React(Player * p);
		NeedlesHall(std::string n);
		~NeedlesHall();
};

#endif