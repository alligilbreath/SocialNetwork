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
public:
    UserProcessing(string inputFile);
    
};
#endif /* UserProcessing_h */
