/*
	Avila, Anthony

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

void displayMenu()
{
	cout << string(45, '*') << endl
		<< "\t\tMAIN MENU" << endl
		<< string(45, '*') << endl
		<< "\nSelect one of the following:" << endl
		<< "\n\t1: Print all bots" << endl
		<< "\t2: Print all clubs" << endl
		<< "\t3: Print a bot's votes from a club" << endl
		<< "\t4: Print a bot's total votes" << endl
		<< "\t5: Print winner" << endl
		<< "\t6: Print final results" << endl
		<< "\t7: To exit" << endl;
}

void exitMessage()
{
	cout << endl << string(45, '-') << endl
		<< "  Thanks for running the STEM Bot Election!" << endl
		<< "   May the best bot serve wisely. Goodbye!" << endl
		<< string(45, '-') << endl;
}

void noDataMessage()
{
	cout << "\n\t*** No data is avilable." << endl
		<< "\t*** Please contact the administrator." << endl;
}

void processMenu(const BotList& botList, const Election& election)
{
	int sentinelVal = 1;
	while (sentinelVal != 0)
	{
		int option = 0;
		cout << "\nEnter your choice: ";
		cin >> option;

		switch (option)
		{
			case 1:
				{
					if (botList.isEmpty())
					{
						noDataMessage();
					}
					else
					{
						botList.printAllBotsInfo();
					}
					break;

				}
			case 2:
				{
					if (election.noDataFound())
					{
						noDataMessage();
					}
					else
					{
						election.printAllClubs();
					}
					break;

				}
			case 3:
				{
					if (election.noDataFound())
					{
						noDataMessage();
					}
					else
					{
						cout << "\nEnter bot's name: ";
						string botName;
						cin >> botName;

						cout << "Enter club's name: ";
						string clubName;
						cin >> clubName;

						election.printBotVotesFromClub(botName, clubName);
					}
					break;

				}
			case 4:
				{
					if (election.noDataFound())
					{
						noDataMessage();
					}
					else
					{
						cout << "\nEnter bot's name: ";
						string botName;
						cin >> botName;

						election.printBotTotalVotes(botName);
					}
					break;

				}
			case 5:
				{
					if (election.noDataFound())
					{
						noDataMessage();
					}
					else
					{
						election.printWinner();
					}
					break;

				}
			case 6:
				{
					if (election.noDataFound())
					{
						noDataMessage();
					}
					else
					{
						election.printFinalResults();
					}
					break;

				}
		}
		
		if (option == 7)
		{
			exitMessage();
			sentinelVal = 0;
		}
		else
		{
			cout << endl;
			system("Pause");

			cout << endl;
			displayMenu();
		}
	}
}
