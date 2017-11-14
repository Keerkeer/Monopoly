#include "tuition.h"
#include <string>
#include <iostream>
#include "player.h"

Tuition::Tuition(std::string n):NotBuyable(n){}
Tuition::~Tuition() {}


void Tuition::React(Player * p){
	if (p->isComp){
		p->SetDebt(300);
		return;
	}
	std::cout << "Do you want to pay $300 or 10% (type 1 or 2): ";
	int x;
    std::cin >> x;
	if (x == 1){
		p->SetDebt(300);
	} else {
		p->SetDebt(.1 * p->TotalWorth()); // Don't know how to get;
	}
	p->SetOwedPlayer('!');
	cout << "Ensure that you use the pay command to clear your debt to the bank!" << endl;
}