#ifndef _SLC_H_
#define _SLC_H_
#include "notbuyable.h"
#include <string>
class Player;

class Slc: public NotBuyable{
	public:
	void React(Player* p);
	Slc(std::string s);
	~Slc();
};

#endif