#include "gym.h"
#include <string>
#include <iostream>
#include "player.h"
using namespace std;

Gym::Gym(char o, int c, string n):Buyable(o,c,n) {}
Gym::~Gym() {}

void Gym::React(Player * p){
	int owe = 0;
	cout << p->GetName() << " has landed on " << this->GetName() << endl;
	if (this->GetOwner() == ' '){
		cout << p->GetName() << " can buy "<< this->GetName() << " for $" << this->GetCost() << endl;
		return;
	}
	if (this->GetOwner() == p->GetName() || this->IsMortgaged()){
		return;
	} else {
		if (this->GetOwner() == this->block1->GetOwner()){
			owe = p->GetDie1() * p->GetDie2() * 10;
		} else {
			owe = p->GetDie1() * p->GetDie2() * 4;
		}
	}
	cout << p->GetName() << " owes " << this->GetOwner() << " $" << owe << endl;
	p->SetDebt(owe);
	p->SetOwedPlayer(this->GetOwner());
}
		