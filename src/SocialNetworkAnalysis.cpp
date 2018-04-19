//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "SocialNetworkAnalysis.h"
#include "InputData.h"
#include "UserProcessing.h"
#include "UserInfo.h"
#include "OutputData.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

SocialNetworkAnalysis::SocialNetworkAnalysis(std::string inputFilePath, std::string outputFilePath)
{
    _inputFilePath = inputFilePath;
    _outputFilePath = outputFilePath;
}

bool sorting(UserInfo* leftUser, UserInfo* rightUser)
{
    if(rightUser->GetDegreeCentrality() < leftUser->GetDegreeCentrality())
    {
        return true;
    }
    string rightName = rightUser->GetUserName();
    string leftName = leftUser->GetUserName();
    transform(rightName.begin(), rightName.end(), rightName.begin(), ::tolower);
    transform(leftName.begin(), leftName.end(), leftName.begin(), ::tolower);
    
    if (rightUser->GetDegreeCentrality() == leftUser->GetDegreeCentrality() && rightName.compare(leftName) > 0)
    {
        return true;
    }
    return false;
}
void SocialNetworkAnalysis::Run(){
    InputData input(_inputFilePath);
    UserProcessing formated(input);
    if (formated.IsValid() == false)
    {
        cout << "File invalidated" << endl;
        InputData fileFailed(_outputFilePath);
        //write empty file here
        return;
    }
    UserInfo* rootUser = formated.GetRoot();
    vector<UserInfo*> potentials = formated.GetPotentials();
    sort(potentials.begin(), potentials.end(), sorting);
    OutputData fileO(_outputFilePath, rootUser, potentials);
    //DataSet splitData(source);
}

