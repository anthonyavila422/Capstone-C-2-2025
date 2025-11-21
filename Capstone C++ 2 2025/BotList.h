/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#ifndef BOTLIST_H
#define BOTLIST_H

#include "BotType.h"

#include <set>
#include <string>

class BotList
{
public:
    void insertBot(const BotType& theBot);

    int getCount() const;
    bool getBotByName(std::string name, BotType& outBot) const;

    bool isEmpty() const;

    void printAllBotsNames() const;
    void printAllBotsInfo() const;

private:
    std::set<BotType> botList;
};
#endif
