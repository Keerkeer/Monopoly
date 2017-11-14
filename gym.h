#ifndef _GYM_H_
#define _GYM_H_
#include <string>
#include "buyable.h"
class Player;

class Gym: public Buyable{
	
	
	public:
		void React(Player * p);
		Gym(char o, int c, std::string n);
		~Gym();
};

#endif