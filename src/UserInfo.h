//
//  UserInfo.h
//  Project
//
//  Created by Alli Gilbreath on 4/18/18.
//

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
    vector<UserInfo> following;
    vector<UserInfo> followers;
public:
    UserInfo();
    UserInfo(string name){ _userName = name;};
    string GetUserName(){ return _userName;};
    int GetDegreeCentrality(){ return _degreeCentrality;};
    int GetNumFollowers();
    int GetNumFollowing();
    void AddFollower(UserInfo newUser);
    void AddFollowing(UserInfo newUser);
    UserInfo GetFollowerAt(int index);
    UserInfo GetFollowingAt(int index);
    
    
};

#endif /* UserInfo_h */

