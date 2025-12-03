/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "BotType.h"

#include <iostream>

using namespace std;

string BotType::getBotName() const
{
    return name;
}

string BotType::getBotAbility() const
{
    return ability;
}

string BotType::getBotTrait() const
{
    return trait;
}

void BotType::printBotName() const
{
    cout << "Bot name is: " << name << endl;
}

void BotType::printBotInfo() const
{
    cout << "Bot name is: " << name << endl
        << "Bot ability is: " << ability << endl
        << "Bot trait is: " << trait << endl;
}

bool BotType::operator < (const BotType& otherBot) const
{
    return name < otherBot.name;
}