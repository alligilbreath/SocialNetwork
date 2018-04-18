//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef UserProcessing_h
#define UserProcessing_h
#include "UserInfo.h"
#include "InputData.h"

class UserProcessing{
private:
    vector<UserInfo*> _users;
    UserInfo _rootUser;
    vector<UserInfo*> _potentials;
    bool _invalidData;
public:
    UserProcessing(InputData inputData);
    bool IsValid();
    int ExistingIndex(string currUser);
    
};
#endif /* UserProcessing_h */
