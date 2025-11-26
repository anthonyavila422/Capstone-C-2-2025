/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "BotType.h"
#include "BotList.h"
#include "Election.h"
#include "FileReader.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
    BotList myList;
    //readBotData(myList);

    Election myElection;
    readElectionResults(myElection);

    displayMenu();
    processMenu(myList, myElection);

    cout << endl;
    system("Pause");
    return 0;
}