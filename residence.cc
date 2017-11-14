#include "residence.h"
#include <iostream>
#include <string>
#include "player.h"
using namespace std;
void Residence::React(Player * p){
	cout << p->GetName() << " have landed on " << this->GetName() << endl;
	if (this->GetOwner() == ' '){
		cout << p->GetName() << " can buy " << this->GetName() << " for $" << this->GetCost() << endl;
		return;
	}
	if(this->GetOwner() == p->GetName() || this->IsMortgaged()){
		return;
	}
	
	
	int owe = 25;
	if (block1->GetOwner() == this->GetOwner()){
		owe *= 2;
	}
	if (block2->GetOwner() == this->GetOwner()){
		owe *= 2;
	}
	if (block3->GetOwner() == this->GetOwner()){
		owe *= 2;
	}
	cout << p->GetName() <<  " owes " << this->GetOwner() << " $" << owe << endl;
	p->SetDebt(owe);
	p->SetOwedPlayer(this->GetOwner());
}


Residence::Residence(char o, int c, string n):Buyable(o,c,n){}

Residence::~Residence() {}
