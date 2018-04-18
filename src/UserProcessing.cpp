//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <stdio.h>
#include "UserProcessing.h"

UserProcessing::UserProcessing(string inputFileName, string outputFileName)
{
    _goodInput = ReadInputFile(inputFileName);
}

bool UserProcessing::ReadInputFile(string inputFileName)
{
    
    ifstream inputFile(inputFileName);
    if(!inputFile.is_open())
    {
        cout << "Could not open " << inputFileName << endl;
        return false;
    }
    bool firstRead = true;
    bool userAlreadyExists = false;
    int userIndex;
    int followerIndex;
    bool followerAlreadyExists = false;
    string currentLine;
    string user;
    string follower;
    UserInfo currUser;
    UserInfo currFollower;
    
    while(getline(inputFile, currentLine))
    {
        stringstream currentStream(currentLine);
        if(firstRead == true)
        {
            currentStream >> user;
            _rootUser.SetUsername(user);
            firstRead = false;
        }
        else
        {
            currentStream >> user >> follower;
            for(int i = 0; i < _users.size(); i++)
            {
                if(_users.at(i).GetUserName() == user)
                {
                    userIndex = i;
                    userAlreadyExists = true;
                }
                else if(_users.at(i).GetUserName() == follower)
                {
                    followerIndex = i;
                    followerAlreadyExists = true;
                }
            }
            if(userAlreadyExists && followerAlreadyExists)
            {
                _users.at(userIndex).AddFollower(_users.at(followerIndex));
                _users.at(followerIndex).AddFollowing(_users.at(userIndex));
            }
            else if(userAlreadyExists)
            {
                UserInfo currFollower(follower);
                if(currFollower.IsValidName())
                {
                    _users.at(userIndex).AddFollower(currFollower);
                    currFollower.AddFollowing(_users.at(userIndex));
                    _users.push_back(currFollower);
                }
                else
                {
                    return false;
                }
            }
            else if(followerAlreadyExists)
            {
                UserInfo currUser(user);
                if(currUser.IsValidName())
                {
                    currUser.AddFollower(_users.at(followerIndex));
                    _users.at(followerIndex).AddFollowing(currUser);
                    _users.push_back(currUser);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                UserInfo currUser(user);
                UserInfo currFollower(follower);
                if(currUser.IsValidName() && currFollower.IsValidName())
                {
                    currUser.AddFollower(currFollower);
                    currFollower.AddFollowing(currUser);
                    _users.push_back(currUser);
                    _users.push_back(currFollower);
                    
                }
                else
                {
                    if(!currUser.IsValidName())
                    {
                        cout << "Input file is " << inputFileName << endl;
                        cout << "Invalid username found and it's user: " << currUser.GetUserName() << endl;
                        return false;
                    }
                    else
                    {
                        cout << "Input file is " << inputFileName << endl;
                        cout << "Invalid username found and it's follower: " << currFollower.GetUserName() << endl;
                        return false;
                    }
                    
                }
            }
        }
    }
    bool foundRootUser = false;
    for(unsigned int i = 0; i < _users.size(); i++)
    {
        if(_users.at(i).GetUserName() == _rootUser.GetUserName())
        {
            foundRootUser = true;
        }
    }
    if(foundRootUser == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool UserProcessing::IsGoodInput()
{
    return _goodInput;
}

void UserProcessing::WriteOutput(std::string outputFileName)
{
    return;
}

