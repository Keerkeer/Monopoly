#include "slc.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include "player.h"
using namespace std;
Slc::Slc(string n): NotBuyable(n){}
Slc::~Slc(){}

void Slc::React(Player * p){
	int r;
	srand(time(0));
	r = rand() % 100 + 1;
	
	if (NotBuyable::timsCards !=4){
		if (r == 1){
			p->SetTimsCard(p->GetTimsCard() + 1);
			cout << "You have earned a Tim's Card!" << endl;
			return;
		}
	}
	
	r = rand() % 24 + 1;
	if (r <= 3){
		
		p->AddSpaces(-3);				//moving accordingly;
		cout << "You moved back 3 spaces" << endl;

	}
	else if (r <= 7){
		p->AddSpaces(-2);					//moving accordingly;
		cout << "You moved back 2 spaces" << endl;
	}
	else if (r <= 11){
		p->AddSpaces(-1);					//moving accordingly;
		cout << "You moved back 1 spaces" << endl;
	}
	else if (r <= 14){
		p->AddSpaces(1);					//moving accordingly;
		cout << "You moved forward 1 spaces" << endl;
	}
	else if (r <= 18){
		p->AddSpaces(2);				//moving accordingly;
		cout << "You moved forward 2 spaces" << endl;
	}
	else if (r <= 22){
		p->AddSpaces(3);					//moving accordingly;
		cout << "You moved forward 3 spaces" << endl;
	}
	else if (r <= 23){
		p->SetCurrentPos(10);
		p->SetJailed(true);//moving accordingly;
		p->SetRollCount(4);
		cout << p->GetName() << "was sent to DC TIMS LINES!!!!!" << endl;
	}
	else if (r <= 24){
		p->SetCurrentPos(0);					//moving accordingly;
		cout << p->GetName() << "was moved to OSAP!" << endl;	
		p->AddCash(200);
	}
}
