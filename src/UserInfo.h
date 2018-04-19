//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef UserInfo_h
#define UserInfo_h
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UserInfo{
private:
    int _degreeCentrality;
    string _userName;
    vector<UserInfo*> following;
    vector<UserInfo*> followers;
public:
    UserInfo();
    UserInfo(string name);
    UserInfo(const UserInfo &assign);
    string GetUserName(){ return _userName;};
  //  void SetUsername(string username);
    int GetDegreeCentrality();
    int GetNumFollowers();
    int GetNumFollowing();
  //  int GetIndexInUsers();
    void AddFollower(UserInfo *newUser);
    void AddFollowing(UserInfo *newUser);
 //   void SetIndexInUsers(int index);
    UserInfo* GetFollowerAt(int index);
    UserInfo* GetFollowingAt(int index);
//    bool IsValidName();
    
};

#endif /* UserInfo_h */

