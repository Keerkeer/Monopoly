#include "acabuilding.h"
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

AcademicBuilding::AcademicBuilding(char o, int c, string n, int up, int zero, int one, int two, int three, int four, int five) : Buyable(o,c,n), upgradeCost(up),zero(zero),one(one),two(two),three(three),four(four),five(five),improvements(0)
{}
void AcademicBuilding :: SetImprovements(int i){
	improvements = i;
}
bool AcademicBuilding::CanBuild(){
	if (this->IsMortgaged()){
		return false;
	}
	if(this->GetOwner() == block1->GetOwner() && block1->GetCurrentImprovements() == 0){
		if (block2){
			if (block2->GetOwner() == this->GetOwner() && block2->GetCurrentImprovements() == 0){
				return true;
			}
		}else {
			return true;
		}
	}
	return false;
}
bool AcademicBuilding::CanTrade(){
	if(this->GetCurrentImprovements() != 0){
		return false;
	}
	if(block1->GetCurrentImprovements() == 0){
		if (block2){
			if (block2->GetCurrentImprovements() == 0){
				return true;
			}
		}else {
			return true;
		}
	}
	return false;
}


void AcademicBuilding::React(Player * p){
	int owe = 0;
	if(improvements == 0){
		owe = zero;
	}
	if(improvements == 1){
		owe = one;
	}
	if(improvements == 2){
		owe = two;
	}
	if(improvements == 3){
		owe = three;
	}
	if(improvements == 4){
		owe = four;
	}
	if(improvements == 5){
		owe = five;
	}
	cout << p->GetName() << " has landed on " << this->GetName() << endl;
	if (this->GetOwner() == ' '){
		cout << p->GetName() << " can buy " << this->GetName() << " for $" << this->GetCost() << endl;
		return;
	}
	else if (this->IsMortgaged() ||this->GetOwner() == p->GetName()){
		return;
	}
	
	if (block1->GetOwner() == this->GetOwner() && block2 && block2->GetOwner() == this->GetOwner()){
		if (block2 && block2->GetCurrentImprovements() == 0){
			owe *= 2;
		}
		if (block1->GetCurrentImprovements() == 0){
			owe *= 2;
		}
	}
	cout << p->GetName() << " owes " << this->GetOwner() << " $" << owe << endl;
	p->SetDebt(owe);
	p->SetOwedPlayer(this->GetOwner());
}
int AcademicBuilding::AddImprovement(Player * p){
	if (p->GetName() == this->GetOwner() && p->GetName() == block1->GetOwner() && block2 && block2->GetOwner()){
		if (p->GetCash() < upgradeCost){
			cout << "You don't have enough money!" << endl;
		} else if (improvements == 5){
			cout << "You have a WAP already on this property" << endl;
		} else {
			this->improvements++;
			p->AddCash(-1 * upgradeCost);
			cout << "You have upgraded " << this->GetName() << endl;
			return 1;
		} 
	} else {
		cout << "You don't own the property" << endl;
	}
	return 0;
}

int AcademicBuilding::RemoveImprovement(Player * p){
	if (p->GetName() == this->GetOwner() && p->GetName() == block1->GetOwner() && block2 && block2->GetOwner()){
		if (improvements == 0){
			cout << "This property has no improvements to downgrade!" << endl;
		} else {
			cout << "You have downgraded your building!" << endl;
			p->AddCash(this->upgradeCost / 2);
			this->improvements--;
			return 1;
		}
	} else {
		cout << "You don't own the property" << endl;
	}
	return 0;
}

AcademicBuilding::~AcademicBuilding(){
	cerr << "start delete";
}

int AcademicBuilding::GetCurrentImprovements(){
	return improvements;
}

int AcademicBuilding :: GetUpgradeCost()
{
	return upgradeCost;
}
