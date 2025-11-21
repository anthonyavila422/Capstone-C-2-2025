/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#ifndef BOTTYPE_H
#define BOTTYPE_H

#include <string>

class BotType
{
public:
    BotType() : name(), ability(), trait() {}
    BotType(std::string aName, std::string anAbility, std::string aTrait)
        : name(aName), ability(anAbility), trait(aTrait) {
    }

    std::string getBotName() const;
    std::string getBotAbility() const;
    std::string getBotTrait() const;

    void printBotName() const;
    void printBotInfo() const;

    bool operator < (const BotType&) const;
private:
    std::string name;
    std::string ability;
    std::string trait;
};
#endif
