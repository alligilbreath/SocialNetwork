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
    UserInfo *_rootUser;
    vector<UserInfo*> _potentials;
    bool _invalidData;
public:
    UserProcessing(InputData inputData);
    bool IsValid();
    int CheckPrev(string user);
    int GetDegreeCentrality();
    UserInfo* GetRoot();
    bool CheckIfImportant(UserInfo* user);
    vector<UserInfo*> GetUsers();
    vector<UserInfo*> GetPotentials();
    
    
};
#endif /* UserProcessing_h */
