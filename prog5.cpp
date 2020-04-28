#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct Cost
{
    float hours,care,food,materials;
};

struct Monsters
{
    string name,description,location;
    float avgLength,avgHeight;
    bool dangerous;
    Cost cost;
};


int enterMonsters(int,Monsters*);
int deleteMonster(int,Monsters*);
void printMonsters(int,Monsters*);
// bool moveArrayElements(string,int,Monsters*);
float convertToFloat(string);
void printStatistics();
void saveMonstersToFile();


int main()
{   
    int population=0;
    int choice=0;
    int capacity=100;
    bool runAgain=true;
    Monsters* monsterArray = new Monsters[capacity];
    do{
        char leave;
        cout<<"What would you like to do?\n";
        cout<<"\t\t1.\tEnter some Monsters\n";
        cout<<"\t\t2.\tDelete a Monster\n";
        cout<<"\t\t3.\tList/Print Monsters\n";
        cout<<"\t\t4.\tPrint Statistics on Monster Cost\n";
        cout<<"\t\t5.\tEnd Program\n";
        cout<<"\t\tEnter 1, 2, 3, 4, or 5\n";
        cout<<"CHOICE:";
        // Validate user choice
        while(!(cin>>choice))
        {   
            // Error invalid choice
            cout<< "Error... Enter a valid choice: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        while (choice < 1 || choice > 5)
        {
            cout << "Please choose 1-5:";
            while(!(cin>>choice))
            {
                // Error invalid choice
                cout<< "Error... Enter a valid choice: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
        }
        switch(choice)
        {
            case 1:
                population = enterMonsters(population, monsterArray);
                break;
            case 2:
                population = deleteMonster(population, monsterArray);
                break;
            case 3:
                printMonsters(population, monsterArray);
                break;
            case 4:
                break;
            default:
                {
                    cout<<"Do you really want to leave Monster Island?\n";
                    cin>>leave;
                    if(toupper(leave)=='Y')
                        {
                            runAgain=false;
                            cout<<"Thanks for visiting! Sorry to see you go.";
                        }
                    else
                        runAgain=true;
                }
        }
    }while(runAgain);
    

    return 0;
}

float convertToFloat(string s)
{
    istringstream i(s);
    float x;
    if (!(i>>x))
        x=0;
    return x;
}

int enterMonsters(int citizens,  Monsters* creatureArray )
{
    int choice;
    cin.ignore();
    string chooseFile;
    ifstream inFile;
    string line;
    bool enterRepeat = false;
    char answer;
    if(citizens>=100)
    {
        cout<<"Sorry, but the island is at capacity and can't take any more Monsters.";
    }
    else
    {
        cout<<"What would you like to do?\n";
        cout<<"\t\t1.\tLoad my Monsters from a file\n";
        cout<<"\t\t2.\tEnter one Monster manually\n";
        cout<<"\t\tChoose 1 or 2\n";
        cout<<"CHOICE:";
        
        // Validate user choice
        while(!(cin>>choice))
        {   
            // Error invalid choice
            cout<< "Error... Enter a valid choice: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        while (choice < 1 || choice > 2)
        {
            cout << "Please choose 1 or 2:";
            while(!(cin>>choice))
            {
                // Error invalid choice
                cout<< "Error... Enter a valid choice: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
        }
        
        switch (choice)
        {   
            case 1:
                cout<<"What is the name of the file with your list of monsters? (ex:filename.txt)\n";
                cout<<"FILENAME: ";
                cin>>chooseFile;
                inFile.open(chooseFile.c_str());
                if(inFile.good())
                {
                    while(!inFile.eof())
                    {   
                        getline(inFile,line,'#'); 
                        creatureArray[citizens].name = line;
                        getline(inFile,line,'#');
                        creatureArray[citizens].description= line;
                        getline(inFile,line,'#');
                        creatureArray[citizens].avgLength= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[citizens].avgHeight= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[citizens].location= line;
                        getline(inFile,line,'#');
                        if(line=="1")
                            creatureArray[citizens].dangerous= 1;
                        else
                            creatureArray[citizens].dangerous= 0;
                        getline(inFile,line,'#');
                        creatureArray[citizens].cost.hours= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[citizens].cost.care= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[citizens].cost.food= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[citizens].cost.materials= convertToFloat(line);
                        citizens++;
                    }
                    cout<<"\n\nAll monsters from "<<chooseFile<<" have been added to the program.\n";
                }
                else
                {
                    cout<<"Something went wrong...\n";
                }
                
            break;
            case 2:
                do
                {
                    char danger;
                    cout<<"NAME: ";
                    getline(cin,creatureArray[citizens].name);
                    cout<<"DESCRIPTION: ";
                    getline(cin,creatureArray[citizens].description);
                    cout<<"AVERAGE LENGTH (in feet): ";
                    cin>>creatureArray[citizens].avgLength;
                    cin.ignore();
                    cout<<"AVERAGE HEIGHT (in feet): ";
                    cin>>creatureArray[citizens].avgHeight;
                    cin.ignore();
                    cout<<"LOCATION: ";
                    getline(cin,creatureArray[citizens].location);
                    cout<<"IS IT A DANGEROUS MONSTER? (y or n): ";
                    cin>>danger;
                    if(toupper(danger) == 'Y')
                        creatureArray[citizens].dangerous = 1;
                    else
                        creatureArray[citizens].dangerous = 0;
                    cout<<"How many hours do you spend caring for the "<<creatureArray[citizens].name<<"?\n";
                    cout<<"NUM HOURS: ";
                    cin>>creatureArray[citizens].cost.hours;
                    cin.ignore();
                    cout<<"What is the cost per hour for caring for the "<<creatureArray[citizens].name<<"?\n";
                    cout<<"COST PER HOUR: ";
                    cin>>creatureArray[citizens].cost.care;
                    cin.ignore();
                    cout<<"How much money do you spend on food for the "<<creatureArray[citizens].name<<"?\n";
                    cout<<"FOOD COST: ";
                    cin>>creatureArray[citizens].cost.food;
                    cin.ignore();
                    cout<<"How much money do you spend on grooming and medical supplies for the "<<creatureArray[citizens].name<<"?\n";
                    cout<<"SUPPLY COST: ";
                    cin>>creatureArray[citizens].cost.materials;

                    citizens++;
                    cout<<"Do you want to add another Monster?";
                    cin>>answer;
                    cin.ignore();
                    if(toupper(answer)=='Y')
                        enterRepeat=true;
                    else
                        enterRepeat=false;
                }while(enterRepeat);
                break;
            default:
                cout<<"Nothing to see here.";
                break;
        }
    }
    return citizens;
}

int deleteMonster(int citizens, Monsters* creatureArray)
{   
    string monsterName;
    cout<<"The following is a list of all the monsters you take care of:\n";
    for(int i=0;i<citizens;i++)
        {
            cout<<"index "<<i<<": "<<creatureArray[i].name<<endl;
        }
    cout<<endl<<endl;
    cout<<"What monster do you wish to remove?"<<endl;
    cout<<"MONSTER NAME: ";
    cin>>monsterName;
    // moveArrayElements(monsterName,citizens,creatureArray);
    return citizens;
}

/* bool moveArrayElements(string monsterName, int citizens, Monsters* creatureArray)
{
    int monsterLoc;
    for(int i=0;i<100; i++)
    {
        monsterLoc=i;
    }
    if(strcmp(monsterName,creatureArray[monsterLoc].name)==0)
    {
        for(int i=monsterLoc;i<100;i++)
        {//delete creature at index i and shift next index left
        creatureArray[i]=creatureArray[i+1];
        }
        return true;
    }
    else
    {
        return false;
    }
        
} */

void printMonsters(int citizens, Monsters* creatureArray)
{
    string horizontalLine(80,'-');
    cout<<horizontalLine<<endl;
    for(int i=0;i<citizens;i++)
    {   
        
        cout<<"Monster "<<i+1<<": ";
        cout<<"Name:\t\t\t"<<creatureArray[i].name<<endl;
        cout<<"Description:\t\t"<<endl;
        cout<<creatureArray[i].description<<endl;
        cout<<"Length: \t\t"<<creatureArray[i].avgLength<<" feet"<<endl;
        cout<<"Height: \t\t"<<creatureArray[i].avgHeight<<" feet"<<endl;
        if(creatureArray[i].dangerous==1)
            cout<<"Dangerous?\t\t"<<"yes"<<endl;
        else
            cout<<"Dangerous?\t\t"<<"no"<<endl;      
        cout<<"Number of Hours to Care for Monster: \t\t\t$"<<creatureArray[i].cost.hours<<endl;
        cout<<"Number of Hours to Care for Monster: \t\t\t$"<<creatureArray[i].cost.care<<endl;
        cout<<"Number of Hours to Care for Monster: \t\t\t$"<<creatureArray[i].cost.food<<endl;
        cout<<"Number of Hours to Care for Monster: \t\t\t$"<<creatureArray[i].cost.materials<<endl;

        cout<<horizontalLine<<endl;
    }
}

void printStatistics(int citizens, Monsters* creatureArray)
{

}

void saveMonstersToFile()
{

}

