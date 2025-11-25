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

#include <iostream>

using namespace std;

int main()
{
    cout << "===== PHASE 1: Testinginging BotType =====\n\n";
    
    //Test default constructor, BotType::printBotInfo().
    BotType bot1;
    bot1.printBotInfo();
    cout << endl;

    //Test parameterized constructor + all accessors + all print functions.
    BotType bot2("NAME", "ABILITY", "TRAIT");

    cout << "Name Accessor: " << bot2.getBotName() << endl;
    cout << "Ability Accessor: " << bot2.getBotAbility() << endl;
    cout << "Trait Accessor: " << bot2.getBotTrait() << endl << endl;

    cout << "Bot name print function: ";
    bot2.printBotName();
    cout << endl;
    cout << "Bot info print function: ";

    bot2.printBotInfo();
    cout << endl;

    cout << "===== PHASE 2: Testing BotList (manual insert) =====\n\n";

    // Create BotList object.
    BotList myBotList;

    // Test BotList::isEmpty() on an empty list
    cout << "Is Empty on empty list: " << myBotList.isEmpty() << endl;

    // Create and insert a few bots in the list.
    BotType insertBot1("Joe", "Ability1", "Trait1");
    BotType insertBot2("Shmoe", "Ability2", "Trait2");
    BotType insertBot3("Bro", "Ability3", "Trait3");

    myBotList.insertBot(insertBot1);
    myBotList.insertBot(insertBot2);
    myBotList.insertBot(insertBot3);

    // Test BotList::getCount()
    cout << "Bot List count: " << myBotList.getCount() << endl;

    // Test BotList::isEmpty()
    cout << "Is empty on non-empty list: " << myBotList.isEmpty() << endl;
    cout << endl;

    // Test BotList::printAllBotsNames()
    cout << "Print all bot names: " << endl;
    myBotList.printAllBotsNames();
    cout << endl;

    // Test BotList::printAllBotsInfo()
    cout << "Print all bot info: " << endl;
    myBotList.printAllBotsInfo();
    cout << endl;

    // Test BotList::getBotByName() - found case
    cout << "Get bot by name found case: " << myBotList.getBotByName("Joe", bot1) << endl;

    // Create a BotList object.   
    BotList otherBotList;

    // Test BotList::getBotByName() - not found case 
    // Expected result: returns false AND outBot must remain unchanged.
    cout << "Get bot by name not found case: " << otherBotList.getBotByName("Joe", bot1) << endl;

    cout << "===== PHASE 3: Testing FileReader with bots.csv =====\n\n";

    // Create a BotList object.
    BotList fileBotList;

    // Test BotList::getCount
    fileBotList.getCount();

    // Call readBotData
    readBotData(fileBotList);

    // After calling readBotData, verify:
    // fileBotList.getCount() == number of bots in bots.csv
    // AND printed bot info matches the file data exactly.
    cout << "Count after readBotData: " << fileBotList.getCount() << endl;
    cout << "Printed bot info: ";
    fileBotList.printAllBotsInfo();
    cout << endl;

    cout << "===== PHASE 4: Testing Election and FileReader with votes.csv =====\n\n";

    // Create an Election object.
    Election testElection;

    // Before reading any data, test BotList::noDataFound
    cout << "Test for noDataFound before file read: " << testElection.noDataFound() << endl;

    // Test readElectionResults
    readElectionResults(testElection);

    // Test BotList::noDataFound
    cout << "Test noDataFound after file read: " << testElection.noDataFound() << endl;
    cout << endl;
    // Test BotList::printAllBots
    cout << "Test printAllBots: " << endl;
    testElection.printAllBots();
    cout << endl;

    cout << "===== PHASE 5: Testing Election menu operations with specific bot/club =====\n\n";

    // Choose an existing bot name and club name and test all print function of the Election class
    cout << "Test printBotVotesFromClub: " << endl;
    testElection.printBotVotesFromClub("PixelPilot", "AeroGrp");
    cout << endl << endl;
    
    cout << "Test printBotTotalVotes: " << endl;
    testElection.printBotTotalVotes("MetaMender");
    cout << endl;
    
    cout << "Test printFinalResults: " << endl;
    testElection.printFinalResults();
    cout << endl;

    cout << "Test printWinner: " << endl;
    testElection.printWinner();

    cout << "===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}