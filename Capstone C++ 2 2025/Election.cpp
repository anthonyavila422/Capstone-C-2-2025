/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "Election.h"

#include <iostream>
#include <numeric>

using namespace std;

void Election::addClubs(vector<string>& theClubs)
{
    clubs = theClubs;
}

void Election::addBots(string botName, vector<int>& votesForBot)
{
    electoralVotes.insert({ botName, votesForBot });
}

bool Election::noDataFound() const
{
    return clubs.empty() || electoralVotes.empty();
}

void Election::printAllBots() const
{
    for (auto& i : electoralVotes)
    {
        cout << i.first << endl;
    }
}

void Election::printBotVotesFromClub(string botName, string clubName) const
{
    auto iterClubName = find(clubs.begin(), clubs.end(), clubName);
    auto iterBotName = electoralVotes.find(botName);


}

void Election::printBotTotalVotes(string botName) const
{
    auto iterBotName = electoralVotes.find(botName);
    int total = 0;
    cout << accumulate(iterBotName->second.begin(), iterBotName->second.end(), total)
        << endl;
}

void Election::printWinner() const
{
    int currentTotal, finalTotal = 0;
    string currentName;

    for (auto& i : electoralVotes)
    {
        accumulate(i.second.begin(), i.second.end(), currentTotal);
        if (currentTotal > finalTotal)
        {
            finalTotal = currentTotal;
            currentName = i.first;
        }
        currentTotal = 0;
    }
}

void Election::printFinalResults() const
{

}