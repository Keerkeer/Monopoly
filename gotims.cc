#include "gotims.h"
#include <string>
#include <iostream>
#include "player.h"

void GoTims::React(Player * p){
	p->SetCurrentPos(10);
	p->SetJailed(true);
	p->SetRollCount(4);
	cout << p->GetName() << "was sent to DC TIMS LINES!!!!!" << endl;
}
GoTims::GoTims(std::string n):NotBuyable(n){}
GoTims::~GoTims() {}

