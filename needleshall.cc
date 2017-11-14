#include "needleshall.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "notbuyable.h"
#include <string>
#include "player.h"

using namespace std;
NeedlesHall::NeedlesHall(string n):NotBuyable(n){}
NeedlesHall::~NeedlesHall() {}
void NeedlesHall::React(Player * p){
	
	srand(time(0));
	int r;
	r = rand() % 100 + 1;
	if (timsCards !=4){
		if (r == 1){
			p->SetTimsCard(p->GetTimsCard() + 1);
			cout << "You have earned a Tim's Card!" << endl;
			return;
		}
	}
	
	r = rand() % 18 + 1;
	if (r <= 1){
		p->SetDebt(200);
		p->SetOwedPlayer('!');
		cout << "You owe the university 200 dollars!" << endl;
	}
	else if (r <= 3){
		p->SetDebt(100);
		cout << "You owe the university 100 dollars!" << endl;
		p->SetOwedPlayer('!');
	}
	else if (r <= 6){
		p->SetDebt(50);
		cout << "You owe the university 50 dollars!" << endl;
		p->SetOwedPlayer('!');
	}
	else if (r <= 12){
		cout << "You have received a bursary of $25!" << endl;
		p->AddCash(25);
	}
	else if (r <= 15){
		cout << "You have received a bursary of $50!" << endl;
		p->AddCash(50);
	}
	else if (r <= 17){
		cout << "You have recieved a bursary of $100!" << endl;
		p->AddCash(100);
	}
	else if (r <= 18){
		cout << "You have recieved a bursary of $200!" << endl;
		p->AddCash(200);
	}
}