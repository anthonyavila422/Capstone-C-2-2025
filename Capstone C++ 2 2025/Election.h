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

class Election
{
public:
    void addClubs(vector<string> theClubs);
    void addBots(string botName, vector<int> votesForBot);

    bool noDataFound() const;

    void printAllBots() const;
    void printBotVotesFromClub(string botName, string clubName) const;
    void printBotTotalVotes(string botName) const;
    void printWinner() const;
    void printFinalResults() const;

private:
    std::vector<string> clubs;
    std::map<string, vector<int>> electoralVotes;
};

#endif
