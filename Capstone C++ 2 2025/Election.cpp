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

const int NUM_CLUBS = 10;
const vector<string> CLUB_ABBREVIATIONS = 
    {"NL", "RG", "EC", "AE", "CH", "NC", "AX", "BL", "CY", "DL"};

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

    int index = distance(clubs.begin(), iterClubName);

    cout << "Votes for bot " << botName 
        << " from club " << clubName << ": "
        << iterBotName->second[index];


}

void Election::printBotTotalVotes(string botName) const
{
    auto iterBotName = electoralVotes.find(botName);
    int total = 0;
    cout << "Total votes for bot: " << botName << " is: " 
        << accumulate(iterBotName->second.begin(), 
            iterBotName->second.end(), total) << endl;
}

void Election::printWinner() const
{
    int currentTotal = 0, finalTotal = 0;
    string currentName;

    for (auto& i : electoralVotes)
    {
        currentTotal = accumulate(i.second.begin(), i.second.end(), 0);
        if (currentTotal > finalTotal)
        {
            finalTotal = currentTotal;
            currentName = i.first;
        }
        currentTotal = 0;
    }
    cout << "Winner is: " << currentName << " with " 
        << finalTotal << " votes." << endl;
}

void Election::printFinalResults() const
{
    for (auto& i : electoralVotes)
    {
        cout << "Name: " << i.first
            << " | Club-by-club votes: ";
        for (auto& j : i.second)
        {
            cout << j << " ";
        }

        cout << "| Total votes: ";
        int totalVotes = accumulate(i.second.begin(), i.second.end(), 0);
        cout << totalVotes << endl;
    }
}

void Election::printAllClubs() const
{

}