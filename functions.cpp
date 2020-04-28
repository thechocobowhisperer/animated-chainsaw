<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include"prog5.h"
using namespace std;

int enterMonsters(int&,Monsters*);
void deleteMonster();
bool moveArrayElements();
void printMonsters();
void printStatistics();
void saveMonstersToFile();
float convertToFloat(string s);




int enterMonsters(int &population,  Monsters* creatureArray )
{
    int choice;
    if(population>=100)
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
        cin.ignore();
        ifstream inFile;
        string chooseFile;
        string line;
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
                        creatureArray[population].name = line;
                        getline(inFile,line,'#');
                        creatureArray[population].description= line;
                        getline(inFile,line,'#');
                        creatureArray[population].avgLength= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[population].avgHeight= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[population].location= line;
                        getline(inFile,line,'#');
                        if(line=="1")
                            creatureArray[population].dangerous= 1;
                        else
                            creatureArray[population].dangerous= 0;
                        getline(inFile,line,'#');
                        creatureArray[population].cost.hours= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[population].cost.care= convertToFloat(line);
                        population++;
                    }
                }
            break;
            case 2:
                bool enterRepeat = false;
                char answer;
                do
                {
                    char danger;
                    cout<<"NAME: ";
                    getline(cin,creatureArray[population].name);
                    cout<<"DESCRIPTION: ";
                    getline(cin,creatureArray[population].description);
                    cout<<"AVERAGE LENGTH (in feet): ";
                    cin>>creatureArray[population].avgLength;
                    cout<<"AVERAGE HEIGHT (in feet): ";
                    cin>>creatureArray[population].avgHeight;
                    cout<<"LOCATION: ";
                    getline(cin,creatureArray[population].location);
                    cout<<"IS IT A DANGEROUS MONSTER? (y or n): ";
                    cin>>danger;
                    if(toupper(danger) == 'Y')
                        creatureArray[population].dangerous = 1;
                    else
                        creatureArray[population].dangerous = 0;
                    cout<<"How many hours do you spend caring for the "<<creatureArray[population].name<<"?\n";
                    cout<<"NUM HOURS: ";
                    cin>>creatureArray[population].cost.hours;
                    cout<<"What is the cost per hour for caring for the "<<creatureArray[population].name<<"?\n";
                    cout<<"COST PER HOUR: ";
                    cin>>creatureArray[population].cost.care;
                    population++;
                    cout<<"Do you want to add another Monster?";
                    if(toupper(answer)=='Y')
                        enterRepeat=true;
                    else
                        enterRepeat=false;
                }while(enterRepeat);
    
            break;
            default:
        }
    }
    return population;
}

void deleteMonster()
{

}

bool moveArrayElements()
{

}

void printMonsters()
{

}

void printStatistics()
{

}

void saveMonstersToFile()
{

}

float converToFloat(string s)
{
    istringstream i(s);
    float x;
    if (!(i>>x))
        x=0;
    return x;
=======
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include"prog5.h"
using namespace std;

int enterMonsters(int&,Monsters*);
void deleteMonster();
bool moveArrayElements();
void printMonsters();
void printStatistics();
void saveMonstersToFile();
float convertToFloat(string s);




int enterMonsters(int &population,  Monsters* creatureArray )
{
    int choice;
    if(population>=100)
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
        cin.ignore();
        ifstream inFile;
        string chooseFile;
        string line;
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
                        creatureArray[population].name = line;
                        getline(inFile,line,'#');
                        creatureArray[population].description= line;
                        getline(inFile,line,'#');
                        creatureArray[population].avgLength= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[population].avgHeight= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[population].location= line;
                        getline(inFile,line,'#');
                        if(line=="1")
                            creatureArray[population].dangerous= 1;
                        else
                            creatureArray[population].dangerous= 0;
                        getline(inFile,line,'#');
                        creatureArray[population].cost.hours= convertToFloat(line);
                        getline(inFile,line,'#');
                        creatureArray[population].cost.care= convertToFloat(line);
                        population++;
                    }
                }
            break;
            case 2:
                bool enterRepeat = false;
                char answer;
                do
                {
                    char danger;
                    cout<<"NAME: ";
                    getline(cin,creatureArray[population].name);
                    cout<<"DESCRIPTION: ";
                    getline(cin,creatureArray[population].description);
                    cout<<"AVERAGE LENGTH (in feet): ";
                    cin>>creatureArray[population].avgLength;
                    cout<<"AVERAGE HEIGHT (in feet): ";
                    cin>>creatureArray[population].avgHeight;
                    cout<<"LOCATION: ";
                    getline(cin,creatureArray[population].location);
                    cout<<"IS IT A DANGEROUS MONSTER? (y or n): ";
                    cin>>danger;
                    if(toupper(danger) == 'Y')
                        creatureArray[population].dangerous = 1;
                    else
                        creatureArray[population].dangerous = 0;
                    cout<<"How many hours do you spend caring for the "<<creatureArray[population].name<<"?\n";
                    cout<<"NUM HOURS: ";
                    cin>>creatureArray[population].cost.hours;
                    cout<<"What is the cost per hour for caring for the "<<creatureArray[population].name<<"?\n";
                    cout<<"COST PER HOUR: ";
                    cin>>creatureArray[population].cost.care;
                    population++;
                    cout<<"Do you want to add another Monster?";
                    if(toupper(answer)=='Y')
                        enterRepeat=true;
                    else
                        enterRepeat=false;
                }while(enterRepeat);
    
            break;
            default:
        }
    }
    return population;
}

void deleteMonster()
{

}

bool moveArrayElements()
{

}

void printMonsters()
{

}

void printStatistics()
{

}

void saveMonstersToFile()
{

}

float converToFloat(string s)
{
    istringstream i(s);
    float x;
    if (!(i>>x))
        x=0;
    return x;
>>>>>>> 2223d296c9e4ee50c87ad22948695f6fce7f6955
}