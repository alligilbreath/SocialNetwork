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

UserInfo::UserInfo(string userName)
{
    _userName = userName;
}

void UserInfo::AddFollower(UserInfo newUser)
{
    followers.push_back(newUser);
}

void UserInfo::SetUsername(string username)
{
    _userName = username;
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

bool UserInfo::IsValidName()
{
    char currentChar;
    if(_userName.size() == 0 && _userName.size() > 15)
    {
        return false;
    }
    else
    {
        for(int i = 0; i < _userName.size(); i++)
        {
            currentChar = _userName[i];
            if(ispunct(currentChar) && currentChar != '_')
            {
                return false;
            }
        }
    }
    return true;
}

