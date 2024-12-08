#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string alphabets;
    string missingLetters="";
    int index=0;
    bool check=true;

    fstream file;
    file.open("alphabets.txt",ios::in);

    while(!file.eof())
    {
        getline(file,alphabets);
        for(int j=97;j<=122;j++)
        {
            for(int i=0;i<alphabets.length();i++)
            {
                if(char(j)==alphabets[i])
                {
                    check=false;
                    break;
                }
                else
                {
                    check=true;
                }
            }
            if(check)
            {
                missingLetters=missingLetters+char(j);
            }
        }
    }

    file.close();

    file.open("alphabets.txt",ios::app);
    file<<endl<<missingLetters;

    return 0;
}