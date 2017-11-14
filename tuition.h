#ifndef _TUITION_H_
#define _TUITION_H_
#include "notbuyable.h"
#include <string>
class Player;

class Tuition: public NotBuyable{
	public:
		void React(Player * p);
		Tuition(std::string n);
		~Tuition();
};

#endif