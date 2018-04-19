//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <stdio.h>
#include "OutputData.h"
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//used for blank file
OutputData::OutputData(string fileName)
{
    ofstream outputFile;
    cout << "Opening file" << fileName << endl;
    outputFile.open(fileName);
    if (!outputFile.is_open())
    {
        cout << "Could not open file " << fileName << endl;
    }
    outputFile.close();
}

OutputData::OutputData(string fileName, UserInfo* leader, vector<UserInfo*> related)
{
    ofstream outputFile;
    cout << "Opening file" << fileName << endl;
    outputFile.open(fileName);
    if (!outputFile.is_open())//check if file is open
    {
        cout << "Could not open file" << endl;
    }
    if (related.size() != 0 || leader->GetDegreeCentrality() >500)
    {
        outputFile << "Looking for new accounts for " << formatName(leader) << " to follow" << endl;
        
    }
    for (unsigned int i = 0; i < related.size(); i++)//writes every vechicle state in order
    {
        /*if (i == 0 && related.at(i)->getName().compare(leader->getName()) != 0)
         {
         outFile << formatName(related.at(i)) << endl;
         }*/
        outputFile << formatName(related.at(i)) << endl;
    }
    outputFile.close();//sends out a blank file
}

string OutputData::formatName(UserInfo* name)
{
    stringstream temp;
    temp << name->GetUserName();
    temp << " (";
    temp << name->GetDegreeCentrality();
    temp << ")";
    return temp.str();
}

OutputData::OutputData()
{
    
}

