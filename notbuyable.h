#ifndef _NOTBUYABLE_H_
#define _NOTBUYABLE_H_

#include "property.h"
#include <string>
class Player;

class NotBuyable: public Property{
	public:
		static int timsCards;
		virtual void React(Player * p) = 0;
		NotBuyable(std::string n);
		~NotBuyable();
};

#endif