//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "SocialNetworkAnalysis.h"
#include "UserProcessing.h"
#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

SocialNetworkAnalysis::SocialNetworkAnalysis(string inputFilePath, string outputFilePath){
    _inputFilePath = inputFilePath;
    _outputFilePath = outputFilePath;
}

void SocialNetworkAnalysis::Run(){
    UserProcessing processUsers(_inputFilePath, _outputFilePath);
    if(processUsers.IsGoodInput())
    {
        processUsers.WriteOutput(_outputFilePath);
    }

}
