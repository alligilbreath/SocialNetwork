//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "UserInfo.h"

UserInfo::UserInfo()
{
    _degreeCentrality = 0;
}

UserInfo::UserInfo(string userName)
{
    _userName = userName;
    _degreeCentrality = 0;
}

void UserInfo::AddFollower(UserInfo newUser)
{
    followers.push_back(newUser);
    _degreeCentrality = followers.size();
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
        for(unsigned int i = 0; i < _userName.size(); i++)
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

