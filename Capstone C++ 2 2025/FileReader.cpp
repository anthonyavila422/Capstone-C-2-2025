/*
    Avila, Anthony

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "FileReader.h"
#include "BotType.h"
#include "BotList.h"

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
}