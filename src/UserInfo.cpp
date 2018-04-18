//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "UserInfo.h"

UserInfo::UserInfo()
{
    
}

void UserInfo::AddFollower(UserInfo newUser)
{
    followers.push_back(newUser);
}

void UserInfo::AddFollowing(UserInfo newUser)
{
    following.push_back(newUser);
}

int UserInfo::GetDegreeCentrality()
{
    _degreeCentrality = followers.size();
    return _degreeCentrality;
}

UserInfo UserInfo::GetFollowerAt(int index)
{
    return followers.at(index);
}

UserInfo UserInfo::GetFollowingAt(int index)
{
    return following.at(index);
}

