//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef InputData_h
#define InputData_h
#include <string>
#include <vector>

using namespace std;

struct nameLine
{
    string leftName;
    string rightName;
};

class InputData
{
private:
    vector<nameLine> linesOfNames;
    bool _validData;
public:
    InputData();
    InputData(string inputFileName);
    bool ReadFile(string inputFileName);
    bool Validate(string inputLine);
    vector<nameLine> GetNameLines();
};

#endif /* InputData_h */
