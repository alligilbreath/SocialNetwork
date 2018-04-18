//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef UserProcessing_h
#define UserProcessing_h
#include "UserInfo.h"

class UserProcessing{
private:
    vector<UserInfo> _users;
    UserInfo _rootUser;
    vector<UserInfo> _potentials;
    bool _goodInput;
public:
    UserProcessing(string inputFileName, string outputFileName);
    bool ReadInputFile(string inputFileName);
    bool IsGoodInput();
    void WriteOutput(string outputFileName);
    
};
#endif /* UserProcessing_h */
