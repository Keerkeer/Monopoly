#ifndef _RESIDENCE_H_
#define _RESIDENCE_H_

#include "buyable.h"
#include <string>
class Player;

class Residence: public Buyable{
	public:
	void React(Player * p);
	
	Residence(char o, int c, std::string n);
	~Residence();
};

#endif	
