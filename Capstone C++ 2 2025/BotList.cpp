/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "BotList.h"

#include <iostream>
#include <iomanip>

using namespace std;

void BotList::insertBot(const BotType& theBot)
{
    botList.insert(theBot);
}

int BotList::getCount() const
{
    return static_cast<int>(botList.size());
}

bool BotList::getBotByName(const string& name, BotType& outBot) const
{
    BotType tempBot(name, "", "");

    auto iterBotFound = botList.find(tempBot);

    if (iterBotFound != botList.end())
    {
        outBot = tempBot;
        return true;
    }
    else
        return false;
}

bool BotList::isEmpty() const
{
    return botList.empty();
}

void BotList::printAllBotsNames() const
{
    for (auto& i : botList)
    {
        i.printBotName();
        cout << endl;
    }
}

void BotList::printAllBotsInfo() const
{
    cout << "\n\tBOT NAME\t(ability, trait)" << endl
        << "\t" << string(33, '-') << endl;

    for (auto& i : botList)
    {
        cout << "\t" << i.getBotName() << "\t(" << i.getBotAbility() 
            << ", " << i.getBotTrait() << ")" << endl;
    }
}