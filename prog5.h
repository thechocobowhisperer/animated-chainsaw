#include <string>
using namespace std;

struct Cost
{
    float hours;
    float care;
    float food;
    float materials;
};

struct Monsters
{
    string name;
    string description;
    float avgLength;
    float avgHeight;
    string location;
    bool dangerous;
    Cost cost;
};

