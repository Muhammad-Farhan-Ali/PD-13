#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void readFromFile(string filename,string name[],int age[],int &index);
void writeToFile(string filename,string result);
string getField(string record,int field);

int main()
{
    int index=0;
    string name[10];
    int age[10];

    string nameOfPerson;
    int ageOfPerson;

    string result;

    readFromFile("names.txt",name,age,index);

    for(int i=0;i<sizeof(name)/sizeof(name[0]);i++)
    {
        if(name[i]!="")
        {
            nameOfPerson=name[i];
            break;
        }
    }
    for(int i=0;i<sizeof(age)/sizeof(age[0]);i++)
    {
        if(age[i]!=0)
        {
            ageOfPerson=age[i];
            break;
        }
    }

    if(ageOfPerson%2==0)
    {
       result="###############\n# "+to_string(ageOfPerson)+" HB "+nameOfPerson+"! "+to_string(ageOfPerson)+" #\n###############";
    }
    else
    {
        result="**************\n* "+to_string(ageOfPerson)+" HB "+nameOfPerson+"! "+to_string(ageOfPerson)+" *\n**************";   
    }

    writeToFile("cake.txt",result);

    return 0;
}

void readFromFile(string filename,string name[],int age[],int &index)
{
    string line;
    int comma=0;

    fstream file;
    file.open(filename,ios::in);

    while(!file.eof())
    {
        getline(file,line);
        name[index]=getField(line,1);
        age[index]=stoi(getField(line,2));
        index++;
    }

    file.close();
}

void writeToFile(string filename,string result)
{
    fstream file;
    file.open(filename,ios::out);

    file<<result;
    file.close();
}

string getField(string record,int field)
{
    int commaCount=1;
    string item;

    for(int i=0;i<record.length();i++)
    {
        if(record[i]==',')
        {
            commaCount=commaCount+1;
        }
        else if(commaCount==field)
        {
            item=item+record[i];
        }
    }
    return item;
}