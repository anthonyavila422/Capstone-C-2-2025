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
    cout << "===== PHASE 1: TestingTesting BotType =====\n\n";

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
    // Your code here...

    // Test BotList::getCount
    // Your code here...

    // Call readBotData
    // Your code here...

    // After calling readBotData, verify:
    // fileBotList.getCount() == number of bots in bots.csv
    // AND printed bot info matches the file data exactly.
    // Your code here...

    cout << "===== PHASE 4: Testing Election and FileReader with votes.csv =====\n\n";

    // Create an Election object.
    // Your code here...

    // Before reading any data, test BotList::noDataFound
    // Your code here...

    // Test readElectionResults
    // Your code here...

    // Test BotList::noDataFound
    // Your code here...

    // Test BotList::printAllBots
    // Your code here...

    cout << "===== PHASE 5: Testing Election menu operations with specific bot/club =====\n\n";

    // Choose an existing bot name and club name and test all print function of the Election class
    // Your code here...

    cout << "===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}