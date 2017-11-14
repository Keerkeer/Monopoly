#include "coopfee.h"
#include <string>
#include "player.h"

void CoopFee::React(Player * p){
	p->SetDebt(150);
	p->SetOwedPlayer('!');
}

CoopFee::CoopFee(std::string n):NotBuyable(n){}
CoopFee::~CoopFee() {}