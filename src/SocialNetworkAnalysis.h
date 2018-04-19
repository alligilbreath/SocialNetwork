//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef SOCIALNETWORKANALYSIS_H
#define SOCIALNETWORKANALYSIS_H

#include <string>
#include "UserInfo.h"

class SocialNetworkAnalysis{
private:
    std::string _inputFilePath;
    std::string _outputFilePath;
public:
    SocialNetworkAnalysis(std::string inputFilePath, std::string outputFile);
//    bool sorting(UserInfo* leftUser, UserInfo* rightUser);
   // void Run(std::string inputFilePath, std::string outputFile);
    void Run();
};
#endif /* SocialNetworkAnalysis_hpp */
