#ifndef _DCTIMSLINE_H_
#define _DCTIMSLINE_H_

#include "notbuyable.h"
#include <string>
class Player;

class DCTimsLine : public NotBuyable{
	public:
		DCTimsLine(std::string n);
		~DCTimsLine();
		void React(Player * p);
};

#endif