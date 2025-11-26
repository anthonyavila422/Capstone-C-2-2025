/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "BotList.h"

#include <iostream>

using namespace std;

void BotList::insertBot(const BotType& theBot)
{
    botList.insert(theBot);
}

int BotList::getCount() const
{
    return static_cast<int>(botList.size());
}

bool BotList::getBotByName(string name, BotType& outBot) const
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
        cout << i.getBotName() << endl;
    }
}

void BotList::printAllBotsInfo() const
{
    for (auto& i : botList)
    {
        cout << "Name: " << i.getBotName() << " Ability: " << i.getBotAbility() << " Trait: " << i.getBotTrait() << endl;
    }
}