//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <stdio.h>
#include "UserProcessing.h"

UserProcessing::UserProcessing(InputData inputData)
{
    _invalidData = false;
    vector<nameLine> temp = inputData.GetNameLines();
    for (unsigned int i = 1; i < temp.size(); i++)
    {
        //p = userIndex
        int userIndex = CheckPrev(temp.at(i).leftName);
        if (userIndex == -1)
        {
            _users.push_back(new UserInfo(temp.at(i).leftName));
            //j is followerIndex
            int followerIndex = CheckPrev(temp.at(i).rightName);
            if (followerIndex == -1)
            {
                _users.push_back(new UserInfo(temp.at(i).rightName));
                _users.at(_users.size() - 2)->AddFollowing((_users.at(_users.size()-1)));
                _users.at(_users.size() - 1)->AddFollower((_users.at(_users.size() - 2)));
            }
            else
            {
                _users.at(_users.size() - 1)->AddFollowing(_users.at(followerIndex));
                _users.at(followerIndex)->AddFollower((_users.at(_users.size() - 1)));
            }
        }
        else
        {
            int followerIndex = CheckPrev(temp.at(i).rightName);
            if (followerIndex == -1)
            {
                _users.push_back(new UserInfo(temp.at(i).rightName));
                _users.at(userIndex)->AddFollowing((_users.at(_users.size() - 1)));
                _users.at(_users.size() - 1)->AddFollower((_users.at(userIndex)));
            }
            else
            {
                _users.at(userIndex)->AddFollowing((_users.at(followerIndex)));
                _users.at(followerIndex)->AddFollower((_users.at(userIndex)));
            }
        }
    }
    int rootIndex = CheckPrev(temp.at(0).leftName);
    if (rootIndex == -1)
    {
        cout << "User does not exist!" << endl;
        _invalidData = true;
    }
    else
    {
        //lead person is root user
        _rootUser = _users.at(rootIndex);
        int centrality1 = _rootUser->GetNumFollowing();
        for (int i = 0; i < centrality1; i++)
        {
            UserInfo *tempA = _rootUser->GetFollowingAt(i);
            int centrality2 = tempA->GetNumFollowing();
            for (int j = 0; j < centrality2; j++)
            {
                if (CheckIfImportant(tempA->GetFollowingAt(j)))
                {
                    _potentials.push_back(tempA->GetFollowingAt(j));
                    UserInfo *tempB = tempA->GetFollowingAt(j);
                    int centrality3 = tempB->GetNumFollowing();
                    for (int k = 0; k < centrality3; k++)
                    {
                        if (CheckIfImportant(tempB->GetFollowingAt(k)))
                        {
                            _potentials.push_back(tempB->GetFollowingAt(k));
                        }
                    }
                }
            }
        }
        //LeadPerson
    }
}

//check if the user is a.) root user b.) someone the root user follows or
bool UserProcessing::CheckIfImportant(UserInfo* currUser)
{
    if (_rootUser == currUser)
    {
        return false;
    }
    for (int i = 0; i < _rootUser->GetNumFollowing(); i++)
    {
        if (_rootUser->GetFollowingAt(i) == currUser)
        {
            return false;
        }
    }
    for (unsigned int i = 0; i < _potentials.size(); i++)
    {
        if (_potentials.at(i) == currUser)
        {
            return false;
        }
    }
    return true;
}

//check if previously in dataset
int UserProcessing::CheckPrev(std::string user)
{
    for (unsigned int i = 0; i < _users.size(); i++)
    {
        if (_users.at(i)->GetUserName().compare(user) == 0)
        {
            return i;
        }
    }
    return -1;
    
}

bool UserProcessing::IsValid()
{
    return !_invalidData;
}

int UserProcessing::GetDegreeCentrality()
{
    return _rootUser->GetDegreeCentrality();
}

vector<UserInfo*> UserProcessing::GetUsers()
{
    return _users;
}

vector<UserInfo*> UserProcessing::GetPotentials()
{
    return _potentials;
}

UserInfo* UserProcessing::GetRoot()
{
    return _rootUser;
}
