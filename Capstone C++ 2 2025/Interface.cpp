/*
	Avila, Anthony

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/


#include "Interface.h"


#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


// Definition function displayMenu
void displayMenu()
{
	cout << string(45, '*') << endl
		<< "\t\tMAIN MENU" << endl
		<< string(45, '*') << endl;

	cout << "\nSelect one of the following:" << endl
		<< "\n\t1: Print all bots" << endl
		<< "\t2: Print all clubs" << endl
		<< "\t3: Print a bot's votes from a club" << endl
		<< "\t4: Print a bot's total votes" << endl
		<< "\t5: Print winner" << endl
		<< "\t6: Print final results" << endl
		<< "\t7: To exit" << endl;
}


// Definition function exitMessage
void exitMessage()
{
	// Your code here...
}


// Definition function noDataMessage
void noDataMessage()
{
	cout << "\n\t*** No data is avilable." << endl
		<< "\t*** Please contact the administrator." << endl;
}


// Definition function processMenu
void processMenu(const BotList& botList, const Election& election)
{
	int sentinelVal = 1;
	while (sentinelVal != 0)
	{
		int option;
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
					}
				}
			case 4:
				{
					
				}
			case 5:
				{
					
				}
			case 6:
				{
					
				}
			case 7:
				{
					
				}
		}

	}
}
