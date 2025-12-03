/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "Election.h"

#include <iostream>
#include <numeric>
#include <iomanip>

using namespace std;

void Election::addClubs(const vector<string>& theClubs)
{
    clubs = theClubs;
}

void Election::addBots(const string& botName,const vector<int>& votesForBot)
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

void Election::printBotVotesFromClub(const string& botName,const string& clubName) const
{
    auto iterClubName = find(clubs.begin(), clubs.end(), clubName);
    auto iterBotName = electoralVotes.find(botName);

    int index = distance(clubs.begin(), iterClubName);

    cout << "\n\t" << botName
        << " received " << iterBotName->second[index] << " vote(s) from "
        << clubName << "." << endl;


}

void Election::printBotTotalVotes(const string& botName) const
{
    auto iterBotName = electoralVotes.find(botName);
    int total = 0;

    cout << "\n\t" << botName << " received a total of "
        << accumulate(iterBotName->second.begin(), 
            iterBotName->second.end(), total) << " vote(s)." << endl;
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
    cout << "\n\tWinner: " << currentName << " with " 
        << finalTotal << " vote(s)." << endl;
}

void Election::printFinalResults() const
{
    cout << "\n\tBot\t       ";

    for (auto& i : CLUB_ABBREVIATIONS)
    {
        cout << i << " ";
    }

    cout << "  Total" << endl << "\t" << string(52, '*') << endl;

    for (auto& i : electoralVotes)
    {
        cout << "\t" << i.first
            << "\t";

        for (auto& j : i.second)
        {
            cout << j << "  ";
        }

        int totalVotes = accumulate(i.second.begin(), i.second.end(), 0);

        cout << "\t" << "  " << totalVotes << endl;
    }
}

void Election::printAllClubs() const
{
    cout << "\n\tCLUB\t (abbreviation)" << endl 
        << "\t" << string(23, '-') << endl;

    for (int i = 0; i < 10; ++i)
    {
        cout << "\t" << setw(9) << left << clubs[i] 
            << "(" << CLUB_ABBREVIATIONS[i] << ")" << endl;
    }
}