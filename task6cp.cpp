#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string ExtractString(string filename);

int main()
{
    string result="";
    result=ExtractString("task6cp.txt");

    if(result=="")
    {
        cout<<"\"What.... Why did you make this!\""<<endl;
    }
    else
    {
        cout<<result<<endl;
    }

    return 0;
}
string ExtractString(string filename)
{
    string line="";
    string result="";

    fstream file;
    file.open(filename,ios::in);

    while(!file.eof())
    {
        getline(file,line);
        for(int i=0;line[i]!='\0';i++)
        {
            if((line[i]>=97 && line[i]<=122) || (line[i]>=65 && line[i]<=90) || line[i]==32 || line[i]==34 || line[i]==39)
            {
                result=result+line[i];
            }
        }
    }
    return result;
}