#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "player.h"
#include "property.h"
#include "buyable.h"
#include "notbuyable.h"
#include "acabuilding.h"
#include "residence.h"
#include "gym.h"
#include "osap.h"
#include "gotims.h"
#include "dctimsline.h"
#include "goosenesting.h"
#include "slc.h"
#include "coopfee.h"
#include "tuition.h"
#include "needleshall.h"
using namespace std;

class GameBoard
{
	private:
		Property** prop;
		int numPlayers;
		char **display;
		
	public:
		GameBoard();
		~GameBoard();
		void Move(Player* p);
		void DisplayBoard();
		void ChangeBoard(Player* p);
		void Trade(Player** pa, Player* pg, char rcvrName, string gp, string rp);
		void Trade(Player** pa, Player* pg, char rcvrName, string gp, int rm);
		void Trade(Player** pa, Player* pg, char rcvrName, int gm, string rp);
		void Trade(Player** pa, Player* pg, char rcvrName, int gm, int rm);
		void Mortgage(Player* p, string propName);
		void Unmortgage(Player* p, string propName);
		void RemoveTimsCard();
		void Improve(Player* p, string propName, string action);
		void Buy(Player* p);
		void Load(Player** pa, ifstream* fp);
		void Save(ofstream* savefile, Player** pa);
};
	