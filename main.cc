#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "humanplayer.h"
#include "gameboard.h"
#include "compplayer.h"
#include "property.h"
using namespace std;

int main(int argc, char* argv[])
{
	const int MAX_PLAYERS = 6;
	int numOfPlayers = 0;
	int currPlayers = 0;
	Player* players[MAX_PLAYERS];
	GameBoard g;
	string input, give, receive;
	int turn = 0;
	int n = 0;
	int hp = 0;
	int cp = 0;
	int index = 0;
	int testDie1, testDie2;
	bool nextTurn = false;
	bool nextRoll = false;
	bool testing = false;
	bool loading = false;
	bool tj;
	char c = ' ';
	char gName = ' ';
	char rName = ' ';
	
	for (int i = 0; i < 6; ++i)
	{
		players[i] = NULL;
	}
	
	//Check for -loading and -testing and set flags
	if (argc == 1)
	{
		loading = false;
		testing = false;
	}
	else if (argc == 2)
	{
		loading = false;
		testing = true;
	}
	else if (argc == 3)
	{
		loading = true;
		testing = false;
		input = argv[2];
	}
	else if (argc == 4)
	{
		loading = true;
		testing = true;
		give = argv[1];
		
		if (give == "-load")
			input = argv[2];
		else
			input = argv[3];
	}
	
	//Load from file
	if (loading)
	{
		ifstream *f = new ifstream(input.c_str());
		(*f) >> numOfPlayers;
		getline((*f), input);
		
		for (int i = 0; i < numOfPlayers; ++i)
		{
			getline((*f), input);
			istringstream iss(input);
			iss >> give;
			iss >> n;
			iss >> cp;
			cerr << give << " " << n << " " << cp << endl;
			if (cp == 10)
			{
				iss >> hp;
				
				if (hp == 0)
				{
					tj = false;
				}
				else if (hp == 1)
				{
					tj = true;
					iss >> hp;
				}
			}
			
			if (i == 0)
				c = 'G';
			else if (i == 1)
				c = 'B';
			else if (i == 2)
				c = 'D';
			else if (i == 3)
				c = 'P';
			else if (i == 4)
				c = 'S';
			else if (i == 5)
				c = '$';
			
			players[i] = new HumanPlayer(cp, c, n, 0, tj, false, give);
			if (tj)
				players[i]->SetRollCount(hp);
		}
		
		g.Load(players, f);
		delete f;
	}
	
	//Loops until a valid number of players is entered
	while (!loading)
	{
		cout << "Enter the number of players in this game: ";
		cin >> n;
		
		if (n >= 2 && n <= 6)
			break;
		
		cout << "Invalid input! The number of players must be between 2 and 6" << endl;
	}
	
	//Loops until a valid number of human players and computer players is entered
	while (!loading)
	{
		cout << "Enter the number of human players in this game: ";
		cin >> hp;
		
		if (hp <= n)
			cp = n - hp;
		
		if ((hp + cp) == n)
			break;
			
		cout << "Invalid input! The sum of human players and computer players must equal the total number of players." << endl;
	}
	
	if (!loading)
	{
		//Collects human player information and adds them to players[]
		for (int i = 0; i < hp; ++i)
		{
			cout << "Enter Human Player " << i + 1 << " name [G,B,D,P,S,$,L,T]: ";
			cin >> c;
			cout << "Enter Human Player " << i + 1 << " real name: ";
			cin >> input;
			players[i] = new HumanPlayer(0, c, 1500, 0, false, false, input);
			++numOfPlayers;
		}
		
		//Collects generates computer player info and adds them to players[]
		for (int i = hp; i < n; ++i)
		{
			if (i == 0)
			{
				c = '@';
				input = "CPU1";
			}
			else if (i == 1)
			{
				c = '#';
				input = "CPU2";
			}
			else if (i == 2)
			{
				c = '%';
				input = "CPU3";
			}
			else if (i == 3)
			{
				c = '&';
				input = "CPU4";
			}
			else if (i == 4)
			{
				c = '*';
				input = "CPU5";
			}
			else if (i == 5)
			{
				c = '+';
				input = "CPU6";
			}
			
			players[i] = new CompPlayer(&g, 0, c, 1500, 0, false, true, input);
			++numOfPlayers;
		}
		
		//Gives computer players pointers to the other players
		for (int cpu = hp; cpu < numOfPlayers; ++cpu)
		{
			for (int i = 0; i < numOfPlayers; ++i)
			{
				players[cpu]->AddPlayer(players[i]);
			}
		}
	}
	
	//Creates initial text display
	for (int i = 0; i < numOfPlayers; ++i)
	{
		g.ChangeBoard(players[i]);
	}
	g.DisplayBoard();
	
	//Loops the turns of the game until only one player is left and wins the game
	currPlayers = numOfPlayers;
	while (currPlayers > 1)
	{
		cout << "Player " << players[turn]->GetName() << "'s turn!" << endl;
		
		//Perform algorithm if it is a CompPlayer
		if (players[turn]->isComp)
		{
			players[turn]->PlayGame();
			
			//Rolls again if doubles occur
			if (players[turn]->GetDie1() == players[turn]->GetDie2() && players[turn]->GetRollCount() < 3 && players[turn]->GetJailed() != true)
				players[turn]->PlayGame();
			if (players[turn]->GetDie1() == players[turn]->GetDie2() && players[turn]->GetRollCount() < 3 && players[turn]->GetJailed() != true)
				players[turn]->PlayGame();
			
			//Check if CompPlayer is bankrupt and reduce currPlayers
			if (players[turn]->GetBankrupt())
				currPlayers -= 1;
				
			//Set rollCount to zero if player is not in jail
			if (!(players[turn]->GetJailed()))
				players[turn]->SetRollCount(0);
			
			//Find the next existing players turn
			do
			{
				++turn;
				turn %= numOfPlayers;
			} while (players[turn]->GetBankrupt() == true);
			
			continue;
		}
		
		cin >> input;
		
		//Increments turn to pass to next player
		if (input == "next")
		{
			//Loops through players to find who has not completed paying off their debt
			//All debt must be cleared before moving on to the next turn
			for (int i = 0; i < numOfPlayers; ++i)
			{
				if (players[i]->GetBankrupt() != true && players[i]->GetDebt() > 0)
				{
					cout << players[i]->GetName() << " owes $" << players[i]->GetDebt() << " to ";
					
					if (players[i]->GetOwedPlayer() == '!')
						cout << "the bank! Please complete all payments first!" << endl;
					else
						cout << players[i]->GetOwedPlayer() << " Please complete all payments first!" << endl;
					
					nextTurn = false;
					break;
				}
				else
				{
					nextTurn = true;
				}
			}
			
			//Check if the player rolled doubles
			if (players[turn]->GetDie1() == players[turn]->GetDie2() && players[turn]->GetRollCount() < 3 && players[turn]->GetRollCount() > 0 &&players[turn]->GetJailed() == false)
			{
				nextTurn = false;
				cout << players[turn]->GetName() << " can still roll the dice!" << endl;
			}
			else if (players[turn]->GetRollCount() == 0)
			{
				nextTurn = false;
				cout << players[turn]->GetName() << " can still roll the dice!" << endl;
			}
			
			if (nextTurn)
			{
				//Set current player's rollCount to 0 if they are not in jail
				if (!(players[turn]->GetJailed()))
					players[turn]->SetRollCount(0);
				//Set current player's rollCount to 0 if they just got sent to jail
				else if (players[turn]->GetRollCount() == 4)
					players[turn]->SetRollCount(0);
			
				//Find the next existing players turn
				do
				{
					++turn;
					turn %= numOfPlayers;
				} while (players[turn]->GetBankrupt() == true);
			}
		}
		//Randomizes die1 and die2 and performs the move function
		else if (input == "roll")
		{
			if (testing)
			{
				cin >> testDie1;
				cin >> testDie2;
			}
		
			//Loops through players to find who has not completed paying off their debt
			//All debt must be cleared before moving on to the next roll
			for (int i = 0; i < numOfPlayers; ++i)
			{
				if (players[i]->GetBankrupt() != true && players[i]->GetDebt() > 0)
				{
					cout << players[i]->GetName() << " owes $" << players[i]->GetDebt() << " to ";
					
					if (players[i]->GetName() == '!')
						cout << "the bank! Please complete all payments first!" << endl;
					else
						cout << players[i]->GetName() << "! Please complete all payments first!" << endl;
					
					nextRoll = false;
					break;
				}
				else
				{
					nextRoll = true;
				}
			}
			
			//Cannot roll over a maximum of 3 times
			if (players[turn]->GetRollCount() >= 3)
			{
				cout << "You cannot roll at this time!" << endl;
				nextRoll = false;
			}
			
			if (nextRoll)
			{
				//Check if they were in jail for less than 2 turns
				if (players[turn]->GetJailed() && players[turn]->GetRollCount() <= 2)
				{
					cout << players[turn]->GetName() << " is currently in DC Tim's Line!" << endl;
					cout << "How would you like to get out of the line: roll, pay $50, or use a Tim's Card? [roll/pay/card]: ";
						
					while (cin >> input)
					{
						//Roll, check if doubles occurred, and react
						if (input == "roll")
						{
							if (!testing)
							{
								//Randomize the roll
								srand(time(NULL));
								players[turn]->SetDie1(rand() % 6 + 1);
								players[turn]->SetDie2(rand() % 6 + 1);
							}
							else
							{
								players[turn]->SetDie1(testDie1);
								players[turn]->SetDie2(testDie2);
							}
							cout << players[turn]->GetName() << " rolled " << players[turn]->GetDie1() << " and " << players[turn]->GetDie2() << endl;
							players[turn]->SetRollCount(players[turn]->GetRollCount() + 1);
							
							//Release player if they rolled doubles
							if (players[turn]->GetDie1() == players[turn]->GetDie1())
							{
								players[turn]->SetJailed(false);
								players[turn]->SetRollCount(4);
								g.Move(players[turn]);
							}
							//Must pay money if they did not roll doubles
							else if (players[turn]->GetRollCount() == 3)
							{
								if (players[turn]->GetTimsCard() > 0)
								{
									cout << players[turn]->GetName() << ", would you like to use a Tim's Card? [yes/no]: ";
									
									while (cin >> input)
									{
										if (input == "yes")
										{
											if (players[turn]->GetTimsCard() > 0)
											{
												players[turn]->SetTimsCard(players[turn]->GetTimsCard() - 1);
												g.RemoveTimsCard();
												players[turn]->SetJailed(false);
												players[turn]->SetRollCount(4);
												g.Move(players[turn]);
												break;
											}
											else
											{
												cout << "Sorry, but you do not have any Tim's Cards!" << endl;
												players[turn]->SetDebt(50);
												players[turn]->SetOwedPlayer('!');
												players[turn]->SetJailed(false);
												players[turn]->SetRollCount(4);
												cout << "Make arrangements and then use the pay comman to make a payment to the bank for $50!" << endl;
												break;
											}
										}
										else if (input == "no")
										{
											players[turn]->SetDebt(50);
											players[turn]->SetOwedPlayer('!');
											players[turn]->SetJailed(false);
											players[turn]->SetRollCount(4);
											cout << "Make arrangements and then use the pay command to make a payment to the bank for $50!" << endl;
											break;
										}
									}
								}
							}
							break;
						}
						//Deduct 50 from cash and allow player to move
						else if (input == "pay")
						{
							//Check if they can pay off the $50 fee immediately
							if (players[turn]->GetCash() < 50)
							{
								if (!testing)
								{
									srand(time(NULL));
									players[turn]->SetDie1(rand() % 6 + 1);
									players[turn]->SetDie2(rand() % 6 + 1);
								}
								else
								{
									players[turn]->SetDie1(testDie1);
									players[turn]->SetDie2(testDie2);
								}
								cout << players[turn]->GetName() << " rolled " << players[turn]->GetDie1() << " and " << players[turn]->GetDie2() << endl;
								players[turn]->SetRollCount(4);
								cout << "You will not move until you use the pay command to pay $50 to the bank!";
								break;
							}
							else
							{
								players[turn]->AddCash(-50);
								players[turn]->SetJailed(false);
								players[turn]->SetRollCount(4);
								
								if (!testing)
								{
									srand(time(NULL));
									players[turn]->SetDie1(rand() % 6 + 1);
									players[turn]->SetDie2(rand() % 6 + 1);
								}
								else
								{
									players[turn]->SetDie1(testDie1);
									players[turn]->SetDie2(testDie2);
								}
								cout << players[turn]->GetName() << " rolled " << players[turn]->GetDie1() << " and " << players[turn]->GetDie2() << endl;
								g.Move(players[turn]);
								break;
							}
						}
						//Remove one use of Tim's Card
						else if (input == "card")
						{
							//Check if they have a Tim's Card
							if (players[turn]->GetTimsCard() > 0)
							{
								players[turn]->SetTimsCard(players[turn]->GetTimsCard() + 1);
								g.RemoveTimsCard();
								players[turn]->SetJailed(false);
								players[turn]->SetRollCount(4);
								
								if (!testing)
								{
									srand(time(NULL));
									players[turn]->SetDie1(rand() % 6 + 1);
									players[turn]->SetDie2(rand() % 6 + 1);
								}
								else
								{
									players[turn]->SetDie1(testDie1);
									players[turn]->SetDie2(testDie2);
								}
								cout << players[turn]->GetName() << " rolled " << players[turn]->GetDie1() << " and " << players[turn]->GetDie2() << endl;
								g.Move(players[turn]);
								break;
							}
							else
							{
								cout << "You do not have any Tim's Cards! Choose another option!" << endl;
							}
						}
					}
				}
			
				//Check that this is their first roll
				if (players[turn]->GetRollCount() == 0)
				{
					if (!testing)
					{
						srand(time(NULL));
						players[turn]->SetDie1(rand() % 6 + 1);
						players[turn]->SetDie2(rand() % 6 + 1);
					}
					else
					{
						players[turn]->SetDie1(testDie1);
						players[turn]->SetDie2(testDie2);
					}
					cout << players[turn]->GetName() << " rolled " << players[turn]->GetDie1() << " and " << players[turn]->GetDie2() << endl;
					players[turn]->SetRollCount(players[turn]->GetRollCount() + 1);
					g.Move(players[turn]);
				}
				//Check if they rolled doubles last turn
				else if (players[turn]->GetRollCount() > 0 && players[turn]->GetRollCount() < 3 && players[turn]->GetDie1() == players[turn]->GetDie2())
				{
					if (!testing)
					{
						srand(time(NULL));
						players[turn]->SetDie1(rand() % 6 + 1);
						srand(time(NULL));
						players[turn]->SetDie2(rand() % 6 + 1);
					}
					else
					{
						players[turn]->SetDie1(testDie1);
						players[turn]->SetDie2(testDie2);
					}
					cout << players[turn]->GetName() << " rolled " << players[turn]->GetDie1() << " and " << players[turn]->GetDie2() << endl;
					players[turn]->SetRollCount(players[turn]->GetRollCount() + 1);
					g.Move(players[turn]);
				}
				else
				{
					cout << players[turn]->GetName() << " cannot roll at this time!" << endl;
				}
			}
		}
		//Performs trade function
		else if (input == "trade")
		{
			cin >> input;
			istringstream iss(input);
			iss >> c;
			
			//Checks for whether money or properties are being traded
			if (!(cin >> n))
			{
				cin.clear();
				cin >> give;
				
				if (!(cin >> hp))
				{
					cin.clear();
					cin >> receive;
					g.Trade(players, players[turn], c, give, receive);
				}
				else
				{
					g.Trade(players, players[turn], c, give, hp);
				}
			}
			else if (!(cin >> hp))
			{
				cin.clear();
				cin >> receive;
				g.Trade(players, players[turn], c, n, receive);
			}
			else
			{
				g.Trade(players, players[turn], c, n, hp);
			}
		}
		//Adds improvements to properties
		else if (input == "improve")
		{
			cin >> input;
			cin >> give;
			g.Improve(players[turn], input, give);
		}
		//Mortgages a property
		else if (input == "mortgage")
		{
			cin >> input;
			g.Mortgage(players[turn], input);
		}
		//Unmortgages a property
		else if (input == "unmortgage")
		{
			cin >> input;
			g.Unmortgage(players[turn], input);
		}
		//The current player declares bankrupt and exits the game
		else if (input == "bankrupt")
		{
			if (players[turn]->GetDebt() < players[turn]->GetCash())
			{
				cout << players[turn]->GetName() << " has enough cash to pay off the debt!" << endl;
			}
			else if (players[turn]->GetOwedPlayer() == '!')
			{
				players[turn]->SellAllImprovements();
				players[turn]->SetCurrentPos(players[turn]->GetCurrentPos());
				players[turn]->SetBankrupt(true);
				g.ChangeBoard(players[turn]);
				players[turn]->RemoveAllProp();
				players[turn]->SetCash(0);
				players[turn]->SetOwedPlayer(' ');
				players[turn]->SetDebt(0);
				currPlayers -= 1;
			}
			else
			{
				for (index = 0; index < numOfPlayers; ++index)
				{
					if (players[index]->GetBankrupt() != true && players[index]->GetName() == players[turn]->GetOwedPlayer())
						break;
				}
				
				players[turn]->SetCurrentPos(players[turn]->GetCurrentPos());
				players[turn]->SetBankrupt(true);
				g.ChangeBoard(players[turn]);
				players[index]->AddCash(players[turn]->GetCash());
				players[turn]->SwapAllProp(players[index]);
				players[turn]->SetCash(0);
				players[turn]->SetOwedPlayer(' ');
				players[turn]->SetDebt(0);
				currPlayers -= 1;
			}
		}
		//Displays assets (doesn't work if player is deciding on how to pay tuition)
		else if (input == "assets")
		{
			if (players[turn]->GetDebt() == 0)
			{
				players[turn]->DisplayAssets();
			}
			else
			{
				cout << players[turn] << " is in debt for $" << players[turn]->GetDebt() << " to ";
				
				if (players[turn]->GetOwedPlayer() == '!')
					cout << "the bank!" << endl;
				else
					cout << players[turn]->GetOwedPlayer() << "!" << endl;
			}
		}
		//Makes a payment to and from specified players
		else if (input == "pay")
		{
			cin >> give;
			cin >> receive;
			cin >> n;
			
			//Makes payment directed towards the bank
			if (receive == "bank")
			{
				istringstream iss(give);
				iss >> gName;
				
				//Searches for the index of the giver
				for (index = 0; index < numOfPlayers; ++index)
				{
					if (players[index]->GetBankrupt() != true && players[index]->GetName() == gName)
						break;
				}
				
				//Output error if giver does not exist
				if (index == numOfPlayers)
				{
					cout << "Please enter correct input!" << endl;
				}
				//Check for negative input
				else if (n < 0)
				{
					cout << "Please enter a positive amount to pay!" << endl;
				}
				//Check for sufficient cash to make payment
				else if (players[index]->GetCash() < n)
				{
					cout << "Not enough cash to make payment!" << endl;
				}
				//Check for overpayment
				else if (players[index]->GetDebt() < n)
				{
					cout << "Entered payment is greater than debt! Please re-enter!" << endl;
				}
				else
				{					
					players[index]->AddCash(-1 * n);
					players[index]->SetDebt(players[index]->GetDebt() - n);
					
					//Reset owedPlayer if debt was paid off
					if (players[index]->GetDebt() == 0)
					{
						players[index]->SetOwedPlayer(' ');
					}
					
					//Allow movement for player released from DC Tim's Line
					if (players[index]->GetRollCount() == 4 && players[index]->GetDebt() == 0)
					{
						g.Move(players[index]);
					}
				}
			}
			//Makes payment towards another player
			else
			{
				istringstream iss(give);
				iss >> gName;
				istringstream niss(receive);
				niss >> rName;
				
				//Searches for the index of the giver
				for (index = 0; index < numOfPlayers; ++index)
				{
					if (players[index]->GetBankrupt() != true && players[index]->GetName() == gName)
						break;
				}
				
				//Searches for the index of the receiver
				for (cp = 0; cp < numOfPlayers; ++cp)
				{
					if (players[cp]->GetBankrupt() != true && players[cp]->GetName() == rName)
						break;
				}
				
				//Output error if giver does not exist
				if (index == numOfPlayers || cp == numOfPlayers)
				{
					cout << "Please enter correct input!" << endl;
				}
				//Check for negative input
				else if (n < 0)
				{
					cout << "Please enter a positive amount to pay!" << endl;
				}
				//Check for sufficient cash to make payment
				else if (players[index]->GetCash() < n)
				{
					cout << "Not enough cash to make payment!" << endl;
				}
				//Check for overpayment
				else if (players[index]->GetDebt() < n)
				{
					cout << "Entered payment is greater than debt! Please re-enter!" << endl;
				}
				else
				{
					players[index]->AddCash(-1 * n);
					players[index]->SetDebt(players[index]->GetDebt() - n);
					players[cp]->AddCash(n);
				}
			}
		}
		//If possible, let's player buy a property
		else if (input == "buy")
		{
			g.Buy(players[turn]);
		}
		//Saves game to a file
		else if (input == "save")
		{
			cin >> input;
			ofstream * savefile = new ofstream(input.c_str());
			*savefile << numOfPlayers << endl;
	
			for (int i = 0; i < numOfPlayers; i++)
			{
				if (players[i]->GetBankrupt())
				{
					continue;
				}
				
				*savefile << players[i]->realName << " " << players[i]->GetCash() << " " << players[i]->GetCurrentPos();
				
				if (players[i]->GetCurrentPos() == 10)
				{
					if(players[i]->GetJailed())
					{
						*savefile << " 1 " << players[i]->GetRollCount();
					}
					else
					{
						*savefile << " 0";
					}
				
				}
				*savefile << endl;
			}
			
			g.Save(savefile,  players);
			delete savefile;
		}
		//Ends the game
		else if (input == "quit")
		{
			break;
		}
		else if (input == "?")
		{
			cout << "Everything is in lower case except for the single char values to be used for name!" << endl;
			cout << "roll: if the player can roll, the player rolls 2 dice and moves the sum and takes action on the square they land on" << endl;
			cout << "next: if the player cannot roll, gives control to the next player" << endl;
			cout << "trade <name> <give> <receive>: offers a trade to name with the current player offering give and requesting receive, where give and receive are either amounts of money or a property name. Responses are accept and reject" << endl;
			cout << "improve <property> buy/sell: attempts to buy or sell a improve for property" << endl;
			cout << "bankrupt: player declares bankruptcy. This command is only available when a player must pay more money then they current have" << endl;
			cout << "assets: displays the assets of the current player. Does not work if the player is deciding how to pay tuition" << endl;
			cout << "save <Filename>: saves the current state of the game (as per the description below) to the given File" << endl;
			cout << "quit: ends the game" << endl;
			cout << "buy: buys current property if possible" << endl;
			cout << "pay <giver> <receiver> <amount>: givers pays the receiver amount to get out of debt, receiver can be bank" << endl;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		delete players[i];
	}
}
