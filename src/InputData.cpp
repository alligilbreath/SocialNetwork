//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <stdio.h>
#include "InputData.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
InputData::InputData()
{
}

InputData::InputData(string inputFileName)
{
    _validData = ReadFile(inputFileName);
}


bool InputData::ReadFile(string inputFileName)
{
    ifstream inFS;
    cout << "Opening file " << inputFileName << endl;
    inFS.open(inputFileName);//open the file
    if (!(inFS.is_open()))//check if file is open
    {
        cout << "Could not open file" << endl;
        return false;//data is no good
    }
    std::string line;
    while (getline(inFS, line))//while there are still more lines to process
    {
        stringstream iss(line);//make a string stream out of the current line
        if (Validate(iss.str()))
        {
            nameLine temp;
            iss >> temp.leftName;
            iss >> temp.rightName;
            //    hashtheTags(temp);
            /*            if (temp.leftTag.size() > max)
             {
             cout << temp.leftTag << endl;
             max = temp.leftTag.size();
             }
             if (temp.rightTag.size() > max)
             {
             cout << temp.rightTag << endl;
             max = temp.rightTag.size();
             }*/
            linesOfNames.push_back(temp);        // increment if valid
        }
        else
        {
            cout << "Invalid line" << endl;
        }
    }
    if (linesOfNames.size() == 0)
    {
        return false;//Cannot have an empty word
    }
    return true;//if reached this point, everything is valid except maybe the time differences; need to check those elsewhere
}

bool InputData::Validate(string lineFromFile)
{
    if (lineFromFile.size() > 36 || lineFromFile.size() == 0)//15 + 6 + 15
    {
        return false;
    }
    else
    {
        for(unsigned int i = 0; i < lineFromFile.size(); i++)
        {
            if(ispunct(lineFromFile[i]) && lineFromFile[i] != '_')
            {
                return false;
            }
        }
        return true;
    }
}

vector<nameLine> InputData::GetNameLines()
{
    return linesOfNames;
}
