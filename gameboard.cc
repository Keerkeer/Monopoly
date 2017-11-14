#include "gameboard.h"

//Constructor for GameBoard class
GameBoard :: GameBoard()
{
	prop = new Property *[40];
	
	//Making Properties;
	prop[0] = new Osap("OSAP");
	prop[1] = new AcademicBuilding(' ', 40,"AL",50,2,10,30,90,160,250);
	prop[2] = new Slc("SLC");
	prop[3] = new AcademicBuilding(' ',60,"ML",50,4,20,60,180,320,450);
	prop[4] = new Tuition("Tuition");
	prop[5] = new Residence(' ',200,"MKV");
	prop[6] = new AcademicBuilding(' ',100,"ECH",50,6,30,90,270,400,550);
	prop[7] = new NeedlesHall("NeedlesHall");
	prop[8] = new AcademicBuilding(' ',100,"PAS",50,6,30,90,270,400,550);
	prop[9] = new AcademicBuilding(' ',120,"HH",50,8,40,100,300,450,600);
	prop[10] = new DCTimsLine("Tims Line");
	prop[11] = new AcademicBuilding(' ',140,"RCH",100,10,50,150,450,625,750);
	prop[12] = new Gym(' ',150,"PAC");
	prop[13] = new AcademicBuilding(' ',140,"DWE",100,10,50,150,450,625,750);
	prop[14] = new AcademicBuilding(' ',160,"CPH",100,12,60,180,500,700,900);
	prop[15] = new Residence(' ',200,"UWP");
	prop[16] = new AcademicBuilding(' ',180,"LHI",100,14,70,200,550,750,950);
	prop[17] = new Slc("SLC");
	prop[18] = new AcademicBuilding(' ',180,"BMH",100,14,70,200,550,750,950);
	prop[19] = new AcademicBuilding(' ',200,"OPT",100,16,80,220,600,800,1000);
	prop[20] = new GooseNesting("GooseNesting");
	prop[21] = new AcademicBuilding(' ',220,"EV1",150,18,90,250,700,875,1050);
	prop[22] = new NeedlesHall("NeedlesHall");
	prop[23] = new AcademicBuilding(' ',220,"EV2",150,18,90,250,700,875,1050);
	prop[24] = new AcademicBuilding(' ',240,"EV3", 150,20,100,300,750,925,1100);
	prop[25] = new Residence(' ',200,"V1");
	prop[26] = new AcademicBuilding(' ',260,"PHYS",150,22,110,330,800,975,1150);
	prop[27] = new AcademicBuilding(' ',260,"B1",150, 22, 110, 330, 800, 975, 1150);
	prop[28] = new Gym(' ', 150, "CIF");
	prop[29] = new AcademicBuilding(' ',280,"B2",150,24,120,360,850,1025,1200);
	prop[30] = new GoTims("Go To Tims");
	prop[31] = new AcademicBuilding(' ', 300,"EIT",200,26,130,390,900,1110,1275);
	prop[32] = new AcademicBuilding(' ',300,"ESC", 200,26,130,390,900,1110,1275);
	prop[33] = new Slc("SLC");
	prop[34] = new AcademicBuilding(' ',320,"C2", 200, 28, 150, 450, 1000, 1200, 1400);
	prop[35] = new Residence(' ', 200, "REV");
	prop[36] = new NeedlesHall("NeedlesHall");
	prop[37] = new AcademicBuilding(' ',350,"MC",200,35,175,500,1100,1300,1500);
	prop[38] = new CoopFee("COOP FEE");
	prop[39] = new AcademicBuilding(' ',400,"DC",200,50,200,600,1400,1700,2000);
	
	//Arts1
	prop[1]->AddNeighbour(prop[3]);
	prop[3]->AddNeighbour(prop[1]);
	
	//Arts2
	prop[6]->AddNeighbour(prop[8]);
	prop[6]->AddNeighbour(prop[9]);
	prop[8]->AddNeighbour(prop[6]);
	prop[8]->AddNeighbour(prop[9]);
	prop[9]->AddNeighbour(prop[8]);
	prop[9]->AddNeighbour(prop[6]);
	
	//Eng
	prop[11]->AddNeighbour(prop[13]);
	prop[11]->AddNeighbour(prop[14]);
	prop[13]->AddNeighbour(prop[11]);
	prop[13]->AddNeighbour(prop[14]);
	prop[14]->AddNeighbour(prop[13]);
	prop[14]->AddNeighbour(prop[11]);
	
	//Health
	prop[16]->AddNeighbour(prop[18]);
	prop[16]->AddNeighbour(prop[19]);
	prop[18]->AddNeighbour(prop[16]);
	prop[18]->AddNeighbour(prop[19]);
	prop[19]->AddNeighbour(prop[16]);
	prop[19]->AddNeighbour(prop[18]);
	
	//Env
	prop[21]->AddNeighbour(prop[24]);
	prop[21]->AddNeighbour(prop[23]);
	prop[23]->AddNeighbour(prop[21]);
	prop[23]->AddNeighbour(prop[24]);
	prop[24]->AddNeighbour(prop[23]);
	prop[24]->AddNeighbour(prop[21]);
	
	//Sci1
	prop[26]->AddNeighbour(prop[28]);
	prop[26]->AddNeighbour(prop[29]);
	prop[28]->AddNeighbour(prop[26]);
	prop[28]->AddNeighbour(prop[29]);
	prop[29]->AddNeighbour(prop[26]);
	prop[29]->AddNeighbour(prop[28]);
	
	//Sci2
	prop[31]->AddNeighbour(prop[33]);
	prop[31]->AddNeighbour(prop[34]);
	prop[33]->AddNeighbour(prop[34]);
	prop[33]->AddNeighbour(prop[31]);
	prop[34]->AddNeighbour(prop[31]);
	prop[34]->AddNeighbour(prop[33]);
	
	//Math
	prop[37]->AddNeighbour(prop[39]);
	prop[39]->AddNeighbour(prop[37]);
	
	
	//Residences
	prop[5]->AddNeighbour(prop[15]);
	prop[5]->AddNeighbour(prop[25]);
	prop[5]->AddNeighbour(prop[35]);
	
	prop[15]->AddNeighbour(prop[5]);
	prop[15]->AddNeighbour(prop[25]);
	prop[15]->AddNeighbour(prop[35]);
	
	prop[25]->AddNeighbour(prop[15]);
	prop[25]->AddNeighbour(prop[5]);
	prop[25]->AddNeighbour(prop[35]);
	
	prop[35]->AddNeighbour(prop[15]);
	prop[35]->AddNeighbour(prop[25]);
	prop[35]->AddNeighbour(prop[5]);
	
	//Gyms
	prop[12]->AddNeighbour(prop[28]);
	prop[28]->AddNeighbour(prop[12]);
	
	//Assigning board text to file stream
	ifstream f("display.txt");
    
	//Creates the board to be displayed
	display = new char *[56];
	for (int i = 0; i < 56; i++)
	{
		display[i] = new char[100];
		
		for (int j = 0; j < 101; j++){
			char c;
			f >> noskipws >> c;
			if (c != '\n')
				display[i][j] = c;
		}
	}
}

GameBoard :: ~GameBoard()
{
	//Deletes prop[]
	for (int i = 0; i < 40; ++i)
	{
		delete prop[i];
	}
	delete [] prop;
	prop = NULL;
	
	//Deletes display
	for (int row = 0; row < 56; ++row)
	{
		delete [] display[row];
	}
	delete [] display;
}

//Moves the player after the roll and performs actions on landed property.
void GameBoard :: Move(Player* p)
{
	int tmpPos;

	if (p->GetRollCount() == 3 && p->GetDie1() == p->GetDie2())
	{
		p->SetRollCount(4);
		p->SetJailed(true);
		p->SetCurrentPos(10);
		ChangeBoard(p);
		DisplayBoard();
		cout << p->GetName() << " has been sent DC Tim's Line!" << endl;
		return;
	}

	//Moves the computer player and performs action on property
	if (p->isComp)
	{
		p->AddSpaces(p->GetDie1() + p->GetDie2());
		tmpPos = p->GetCurrentPos();
		ChangeBoard(p);
		DisplayBoard();
		this->prop[p->GetCurrentPos()]->React(p);
		
		if (tmpPos != p->GetCurrentPos())
		{
			ChangeBoard(p);
			DisplayBoard();
			tmpPos = p->GetCurrentPos();
			this->prop[p->GetCurrentPos()]->React(p);
			
			if (tmpPos != p->GetCurrentPos())
			{
				ChangeBoard(p);
				DisplayBoard();
			}
		}
		
		p->BuyDecision(this->prop[p->GetCurrentPos()]);
		return;
	}
	
	//Moves the human player and performs action on property
	p->AddSpaces(p->GetDie1() + p->GetDie2());
	tmpPos = p->GetCurrentPos();
	ChangeBoard(p);
	DisplayBoard();
	this->prop[p->GetCurrentPos()]->React(p);
	
	if (tmpPos != p->GetCurrentPos())
	{
		ChangeBoard(p);
		DisplayBoard();
		tmpPos = p->GetCurrentPos();
		this->prop[p->GetCurrentPos()]->React(p);
		
		if (tmpPos != p->GetCurrentPos())
		{
			ChangeBoard(p);
			DisplayBoard();
		}
	}
}

//Performs a trade of properties between two players. pa is an array of players, gp is the name of the
//property being given up by the current player, rp is the name of the property asked to be received, pg is a 
//pointer to the player initiating the trade, and rcvrName is the name of the player to which the 
//trade is being directed towards.
void GameBoard :: Trade(Player** pa, Player* pg, char rcvrName, string gp, string rp)
{
	Player* pr;
	string input;
	Property* giveProp;
	Property* receiveProp;

	//Assign pr to point at targeted player
	for (int i = 0; i < 6; ++i)
	{
		if (pa[i] != NULL && pa[i]->GetName() == rcvrName)
		{
			pr = pa[i];
			break;
		}
	}
	
	//Check if pg has property to be given up and pr has property to be received
	if (!(pg->HasProp(gp)))
	{
		cout << pg->GetName() << " does not have property " << gp << endl;
		return;
	}
	else if (!(pr->HasProp(rp)))
	{
		cout << pr->GetName() << " does not have property " << rp << endl;
		return;
	}
	
	//Assign pointers to properties being traded
	for (int i = 0; i < 40; ++i)
	{
		if (this->prop[i]->GetName() == gp)
		{
			giveProp = this->prop[i];
		}
		else if (this->prop[i]->GetName() == rp)
		{
			receiveProp = this->prop[i];
		}
	}
	
	//Check if it is possible to trade giveProp and receiveProp
	if (!(giveProp->CanTrade()))
	{
		cout << "Cannot trade " << giveProp->GetName() << " without selling all improvements on monopoly!" << endl;
		return;
	}
	if (!(receiveProp->CanTrade()))
	{
		cout << "Cannot trade " << receiveProp->GetName() << " without selling all improvements on monopoly!" << endl;
		return;
	}
	
	cout << rcvrName << ", would you like to accept or reject the trade? [accept/reject]: ";
	pr->TradeDecision(pg, giveProp, receiveProp);
	return;
}

//Performs a trade of money for property between two players. pa is an array of players, gp is the name of the
//property being given up by the current player, rm is the amount of money asked to be received, pg is a 
//pointer to the player initiating the trade, and rcvrName is the name of the player to which the 
//trade is being directed towards.
void GameBoard :: Trade(Player** pa, Player* pg, char rcvrName, string gp, int rm)
{
	Player* pr;
	string input;
	Property* giveProp;

	//Assign pr to point at targeted player
	for (int i = 0; i < 6; ++i)
	{
		if (pa[i] != NULL && pa[i]->GetName() == rcvrName)
		{
			pr = pa[i];
			break;
		}
	}
	
	//Check if pg has property to be given up and pr has enough money to give
	if (!(pg->HasProp(gp)))
	{
		cout << pg->GetName() << " does not have property " << gp << endl;
		return;
	}
	else if (pr->GetCash() < rm)
	{
		cout << pr->GetName() << " does not have enough money!" << endl;
		return;
	}
	
	cout << rcvrName << ", would you like to accept or reject the trade? ";
	
	//Assign pointer to property being traded
	for (int i = 0; i < 40; ++i)
	{
		if (this->prop[i]->GetName() == gp)
		{
			giveProp = this->prop[i];
		}
	}
	
	//Check if it is possible to trade giveProp
	if (!(giveProp->CanTrade()))
	{
		cout << "Cannot trade " << giveProp->GetName() << " without selling all improvements on monopoly!" << endl;
		return;
	}
	
	pr->TradeDecision(pg, giveProp, rm);
	return;
}

//Performs a trade of money for property between two players. pa is an array of players, rp is the name of the
//property being to be received by the current player, gm is the amount of money to be given up, pg is a 
//pointer to the player initiating the trade, and rcvrName is the name of the player to which the 
//trade is being directed towards.
void GameBoard :: Trade(Player** pa, Player* pg, char rcvrName, int gm, string rp)
{
	Player* pr;
	string input;
	Property* receiveProp;
	
	//Assign pr to point at targeted player
	for (int i = 0; i < 6; ++i)
	{
		if (pa[i] != NULL && pa[i]->GetName() == rcvrName)
		{
			pr = pa[i];
			break;
		}
	}
	
	//Check if pr has property to be given up and pg has enough money to give
	if (!(pr->HasProp(rp)))
	{
		cout << pr->GetName() << " does not have property " << rp << endl;
		return;
	}
	else if (pg->GetCash() < gm)
	{
		cout << pg->GetName() << " does not have enough money!" << endl;
		return;
	}
	
	cout << rcvrName << ", would you like to accept or reject the trade? ";
	
	//Assign pointer to property being traded
	for (int i = 0; i < 40; ++i)
	{
		if (this->prop[i]->GetName() == rp)
		{
			receiveProp = this->prop[i];
		}
	}
	
	//Check if it is possible to trade receiveProp
	if (!(receiveProp->CanTrade()))
	{
		cout << "Cannot trade " << receiveProp->GetName() << " without selling all improvements on monopoly!" << endl;
		return;
	}
	
	pr->TradeDecision(pg, gm, receiveProp);
	return;
}

//Performs a trade of money between two players. pa is an array of players, gm is the amount of money
//being given up by the current player, rm is the amount of money asked to be received, pg is a 
//pointer to the player initiating the trade, and rcvrName is the name of the player to which the 
//trade is being directed towards.
void GameBoard :: Trade(Player** pa, Player* pg, char rcvrName, int gm, int rm)
{
	Player* pr;
	string input;

	//Assign pr to point at targeted player
	for (int i = 0; i < 6; ++i)
	{
		if (pa[i] != NULL && pa[i]->GetName() == rcvrName)
		{
			pr = pa[i];
			break;
		}
	}
	
	//Check if pg has enough money to give up and pr has enough money to give
	if (!(pg->GetCash() < gm))
	{
		cout << pg->GetName() << " does not have enough money!" << endl;
		return;
	}
	else if (pr->GetCash() < rm)
	{
		cout << pr->GetName() << " does not have enough money!" << endl;
		return;
	}
	
	cout << rcvrName << ", would you like to accept or reject the trade? ";
	
	pr->TradeDecision(pg, gm, rm);	
	return;
}

//Buys or sells an improvement for propName based on action
void GameBoard :: Improve(Player* p, string propName, string action)
{
	//Index of property being improved
	int index;
	
	//Checks if player has propName
	if (!(p->HasProp(propName)))
	{
		cout << p->GetName() << " does not own this property!" << endl;
		return;
	}
	
	//Assigns index
	for (index = 0; index < 40; ++index)
	{
		if (this->prop[index]->GetName() == propName)
		{
			break;
		}
	}
	
	//Perform buy or sell based on action
	if (action == "buy")
	{
		if (!(this->prop[index]->CanBuild()))
		{
			cout << "Cannot build on this property!" << endl;
		}
		else if (this->prop[index]->GetCurrentImprovements() == 5)
		{
			cout << propName << " already has the max number of improvements!" << endl;
		}
		else if (this->prop[index]->GetUpgradeCost() > p->GetCash())
		{
			cout << p->GetName() << " does not have enough money!" << endl;
		}
		else
		{
			p->AddCash(-1 * this->prop[index]->GetUpgradeCost());
			
			//Displays board with improvements
			if (this->prop[index]->AddImprovement())
			{
				ChangeBoard(p);
				DisplayBoard();
			}
		}
	}
	else if (action == "sell")
	{
		if (this->prop[index]->GetCurrentImprovements() == 0)
		{
			cout << propName << " does not have any improvements to sell!" << endl;
		}
		else
		{
			p->AddCash(this->prop[index]->GetUpgradeCost() / 2);
			
			//Displays board with improvements
			if (this->prop[index]->AddImprovement())
			{
				ChangeBoard(p);
				DisplayBoard();
			}
		}
	}
	
	return;
}

//Attempts to mortgage propName
void GameBoard :: Mortgage(Player* p, string propName)
{
	//Index of property being improved
	int index;

	//Checks if p owns propName
	if (!(p->HasProp(propName)))
	{
		cout << p->GetName() << " does not own " << propName << "!" << endl;
		return;
	}
	
	//Assigns index
	for (index = 0; index < 40; ++index)
	{
		if (this->prop[index]->GetName() == propName)
		{
			break;
		}
	}
	
	//Checks if it is possible to mortgage the property
	if (!(this->prop[index]->CanTrade()))
	{
		cout << "Cannot trade this property without selling all improvements on monopoly!" << endl;
	}
	
	//Cannot mortgage if property still has improvements on it
	if (this->prop[index]->GetCurrentImprovements() != 0)
	{
		cout << propName << " cannot be mortgaged without first selling all improvements!" << endl;
	}
	//Cannot mortgage if propety is already mortgaged
	else if (this->prop[index]->IsMortgaged() == true)
	{
		cout << propName << " is already mortgaged!" << endl;
	}
	else
	{
		this->prop[index]->ChangeMortgage();
		p->AddCash(this->prop[index]->GetCost() / 2);
		cout << p->GetName() << " has successfully mortgaged " << propName << "!" << endl;
	}
	
	return;
}

//Attempts to unmortgage propName
void GameBoard :: Unmortgage(Player* p, string propName)
{
	//Index of property being improved
	int index;

	//Checks if p owns propName
	if (!(p->HasProp(propName)))
	{
		cout << p->GetName() << " does not own " << propName << "!" << endl;
		return;
	}
	
	//Assigns index
	for (index = 0; index < 40; ++index)
	{
		if (this->prop[index]->GetName() == propName)
		{
			break;
		}
	}
	
	//Cannot mortgage if property still has improvements on it
	if (p->GetCash() < (0.1 * this->prop[index]->GetCost() + this->prop[index]->GetCost() / 2))
	{
		cout << p->GetName() << " does not have enough money to unmortgage!" << endl;
	}
	//Cannot mortgage if propety is already mortgaged
	else if (this->prop[index]->IsMortgaged() == false)
	{
		cout << propName << " is not mortgaged!" << endl;
	}
	else
	{
		this->prop[index]->ChangeMortgage();
		p->AddCash(-1 * this->prop[index]->GetCost() / 2);
		cout << p->GetName() << " has successfully unmortgaged " << propName << "!" << endl;
	}
	
	return;
}

//Removes a Tim's Card from the total
void GameBoard :: RemoveTimsCard()
{
	this->prop[0]->DecrementTimsCard();
}

//Changes the char text display
void GameBoard :: ChangeBoard(Player * p)
{
	//Algorithm to Remove Player from board;
	int oPos = p->GetOldPos();
	char n = p->GetName();
	int cPos = p->GetCurrentPos();
	
	if (oPos < 10)
	{
	    //formula for bottom row position for the array
		int col = 99 - ( 9 * (oPos + 1));
		
		for (int i = col + 1; i < col + 7; ++i)
		{
			if (this->display[54][i] == n)
			{
				this->display[54][i] = ' ';
				break;
			}
		}
	}
	else if (oPos < 20){
		//formula for the left side position for the array
		int row = 55 - (5 * (oPos % 10)) -1;
		for (int i = 1; i < 7; i++){
			if (display[row][i] == n){
				display[row][i] = ' ';
				break;
			}
		}
	}
	else if (oPos < 30){
		//formula for the top row position for the array
		int col = 9 * (oPos % 10);
		for (int i = col + 1; i < col + 7; i++){
			if (display[4][i] == n){
				display[4][i] = ' ';
				break;
			}
		}
	} else {
		//formula for the side row position for the array
		int row = 4 + ((oPos % 10) * 5);
		for(int i = 91; i < 97; i++){
			if(display[row][i] == n){
				display[row][i] = ' ';
				break;
			}
		}
	}
	//Algorithm to move player
	if (!(p->GetBankrupt())){
		if (cPos < 10){
			int col = 99 - (9 * (cPos + 1));
			for(int i = col+1; i < col + 7 ; i++){
				if (display[54][i] == ' '){
					display[54][i] = n;
					break;
				}
			}
		}	
	
		else if (cPos < 20){
			int row = 55-(5*(cPos % 10)) - 1;
			for(int i = 1; i < 7; i++){
				if(display[row][i] == ' '){
					display[row][i] = n;
					break;
				}
			}
		}
		else if (cPos < 30){
			int col = 9 * (cPos % 10);
			for(int i = col + 1; i < col + 7; i ++){
				if(display[4][i] == ' '){
					display[4][i] = n;
					break;
				}
			}	
		}
		else {
			int row = 4 + ((cPos % 10) * 5);
			for (int i = 91; i < 97; i++){
				if (display[row][i] == ' '){
					display[row][i] = n;
					break;
				}
			}
	 	}
	}
	//Algorithm for adding improvements;
	for(int i = 0; i < 40; i++){
		int ci = 0;
		if (prop[i]->GetOwner() == '!'){
			continue;
		}
		if (i % 10 == 5 || i == 12 || i == 28){
			continue;
		}
			
				ci = prop[i]->GetCurrentImprovements();
				
			if (i < 10){
				int col = 99 - (9 * (i + 1));
				for(int j = col+1; j < col + 1 + ci ; j++){
					display[51][j] = 'i';
				}
				for (int j = col + 1 + ci; j < col + 7; ++j)
				{
					display[51][j] = ' ';
				}		
			}
			else if (i < 20){
				int row = 52-(5*(i % 10)) -1;
				for(int j = 1; j < 1 + ci; j++){
					display[row][j] = 'i';
				}
				for(int j = 1 + ci; j < 7; j++){
					display[row][j] = ' ';
				}
			}
			else if (i < 30){
				int col = 9 * (i % 10);
				for(int j = col + 1; j < col + 1 + ci; j++){
					display[1][j] = 'i';
				}
				for(int j = col + 1 + ci; j < col + 7; j++){
					display[1][j] = ' ';
				}
			}
			else {
				int row = 1 + ((i % 10) * 5);
				for (int j = 91; j < 91 + ci; j++){
					display[row][j] = 'i';
				}
				for(int j = 91 + ci; j < 97; ++j){
					display[row][j] = ' ';
				}
			}
		}
	}

//Displays the text display
void GameBoard :: DisplayBoard() {
	for (int i = 0; i < 56; i++){
		for(int j=0; j < 100; j++){
			cout << display[i][j];
		}
		cout << endl;
	}
}

//Facilitates the purchasing of properties
void GameBoard :: Buy(Player* p)
{
	//The property can be bought if no one owns it already and if the current player has enough cash
	if (this->prop[p->GetCurrentPos()]->GetOwner() == ' ')
	{
		if (p->GetCash() >= this->prop[p->GetCurrentPos()]->GetCost())
		{
			p->AddCash(-1 * this->prop[p->GetCurrentPos()]->GetCost());
			p->AddProp(this->prop[p->GetCurrentPos()]);
			cout << p->GetName() << " has successfully bought " << this->prop[p->GetCurrentPos()]->GetName() << "!" << endl;
		}
		else
		{
			cout << "You do not have enough money to buy this property!" << endl;
		}
	}
	else
	{
		cout << "Sorry, but this property is already owned by " << this->prop[p->GetCurrentPos()]->GetOwner() << "!" << endl;
	}
}

//Loads property settings from file
void GameBoard :: Load(Player** pa, ifstream* fp)
{
	int houses;
	string propName;
	string ownerFullName;
	
	for (int i = 0; i < 40; ++i)
	{
		
		if (this->prop[i]->GetOwner() != '!')
		{
			(*fp) >> propName;
			(*fp) >> ownerFullName;
			(*fp) >> houses;
			
			for (int p = 0; p < 6; ++p)
			{
			
				if (pa[p] != NULL && pa[p]->realName == ownerFullName)
				{
				
					pa[p]->AddProp(this->prop[i]);
					
					if (houses == -1)
						this->prop[i]->ChangeMortgage();
					else
						this->prop[i]->SetImprovements(houses);
				}
			}
		}
	}
}

//Saves current game
void GameBoard :: Save(ofstream* savefile, Player** pa)
{
	for (int i = 0; i < 40; i++)
	{
		if (prop[i]->GetOwner() != '!')
		{
			*savefile << prop[i]->GetName() << " " ;
			
			if (prop[i]->GetOwner() == ' ')
			{
				*savefile << "BANK"; 
			}
			else
			{
				for(int j = 0; j < 6; j++)
				{
					if (prop[i]->GetOwner() == pa[j]->GetName())
					{
						*savefile << pa[j]->realName ;
						break;
					}
				}
			}
		
			if (!(i == 5 || i == 15 || i == 25 || i == 35 || i == 12 || i == 28))
			{
				if (prop[i]->IsMortgaged())
				{
					*savefile << " -1";
				} 
				else
				{
					*savefile << " " << prop[i]->GetCurrentImprovements();
				}
			}
			else 
			{
				*savefile << " 0";
			}
			*savefile << endl;
		}
	}
}
