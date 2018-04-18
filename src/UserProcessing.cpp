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
    ReadInputFile(inputFileName);
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
            UserInfo currUser(user);
            UserInfo currFollower(follower);
            if(currUser.IsValidName() && currFollower.IsValidName())
            {
                _users.push_back(currUser);
                currUser.AddFollower(currFollower);
                currFollower.AddFollowing(currUser);
                
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
    return true;
    
}


