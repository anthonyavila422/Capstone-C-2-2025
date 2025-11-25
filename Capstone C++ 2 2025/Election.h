/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#ifndef ELECTION_H
#define ELECTION_H

#include <vector>
#include <map>
#include <string>

class Election
{
public:
    void addClubs(std::vector<std::string>& theClubs);
    void addBots(std::string botName, std::vector<int>& votesForBot);

    bool noDataFound() const;

    void printAllBots() const;
    void printBotVotesFromClub(std::string botName, std::string clubName) const;
    void printBotTotalVotes(std::string botName) const;
    void printWinner() const;
    void printFinalResults() const;

private:
    std::vector<std::string> clubs;
    std::map<std::string, std::vector<int>> electoralVotes;
};

#endif
