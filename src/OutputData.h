//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef OutputData_h
#define OutputData_h
#include <string>
#include <vector>
#include "UserProcessing.h"
#include "UserInfo.h"

using namespace std;
class OutputData
{
private:
public:
    OutputData(string fileName);
    OutputData(string outputFile, UserInfo* leader, vector<UserInfo*> related);
    string formatName(UserInfo* name);
    OutputData();
};

#endif /* OutputData_h */
