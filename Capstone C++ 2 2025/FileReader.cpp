/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "FileReader.h"
#include "BotType.h"
#include "BotList.h"
#include "Election.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void readBotData(BotList& botList)
{
    ifstream botDataFile("bots.csv");

    if (botDataFile.fail())
    {
        cout << "Error opening file." << endl;
    }
    else
    {
        string line;
        getline(botDataFile, line);

        while (getline(botDataFile, line))
        {
            stringstream lineStream(line);

            string inName, inAbility, inTrait;

            getline(lineStream, inName, ',');
            getline(lineStream, inAbility, ',');
            getline(lineStream, inTrait, ',');

            BotType inputBot(inName, inAbility, inTrait);
            botList.insertBot(inputBot);
        }
        botDataFile.close();
    }

}

void readElectionResults(Election& electionResults)
{
    ifstream votesDataFile("votes.csv");

    if (votesDataFile.fail())
    {
        cout << "Error opening file." << endl;
    }
    else
    {
        string line, trash;
        getline(votesDataFile, line);

        stringstream lineStream(line);
        getline(lineStream, trash, ',');

        string clubName;
        vector<string> clubNames;

        while (getline(lineStream, clubName, ','))
        {
            clubNames.push_back(clubName);
            clubName = "";
        }
        electionResults.addClubs(clubNames);

        line = "";
        string botName, botVote;
        vector<int> votes;

        while (getline(votesDataFile, line))
        {
            stringstream otherStream(line);
            getline(otherStream, botName, ',');

            for (int i = 0; i < 10; ++i)
            {
                getline(otherStream, botVote, ',');
                votes.push_back(stoi(botVote));
                botVote = "";
            }
            electionResults.addBots(botName, votes);
            votes.clear();
        }
    }
}