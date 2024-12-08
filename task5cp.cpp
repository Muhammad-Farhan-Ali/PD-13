#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string morseCode(string input);

int main()
{
    string uncodedData="";
    cout<<"Enter your string to be coded: ";
    getline(cin,uncodedData);

    cout<<morseCode(uncodedData)<<endl;

    return 0;
}
string morseCode(string input)
{
    string MorseCode[27]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
                          ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","....."};

    char letters[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
    char smallLetters[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};

    string result="";
    for(int i=0;i<input.length();i++)
    {
        for(int j=0;j<27;j++)
        {
            if(input[i]==letters[j] || input[i]==smallLetters[j])
            {
                result=result+MorseCode[j];
                break;
            }
        }
        result=result+" ";
    }

    return result;
}