#ifndef _COOPFEE_H_
#define _COOPFEE_H_
#include "notbuyable.h"
#include <string>
class Player;
class CoopFee: public NotBuyable{

	public:
		void React(Player * p);
		CoopFee(std::string n);
		~CoopFee();
};

#endif