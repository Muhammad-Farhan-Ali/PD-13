#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string getFields(string record,int field);
void readFromFile(string filename,string name[],int minOrders[],int arr1[],int size1,int arr2[],int size2);
string pizzaPoints(int orders,int price,string name[],int arr1[],int size1,int arr2[],int size2);

int main()
{
    string name[2];
    int minOrders[2];
    int arr1[8];
    int arr2[10];

    int orders=0,price=0;

    readFromFile("task7cp.txt",name,minOrders,arr1,sizeof(arr1)/sizeof(arr1[0]),arr2,sizeof(arr2)/sizeof(arr2[0]));

    cout<<"Enter minimum number of orders: ";
    cin>>orders;
    cout<<"Enter minimum price of order: ";
    cin>>price;

    cout<<pizzaPoints(orders,price,name,arr1,sizeof(arr1)/sizeof(arr1[0]),arr2,sizeof(arr2)/sizeof(arr2[0]));

    return 0;
}
string getFields(string record,int field)
{
    int commaCount=1;
    string item="";

    for(int i=0;i<record.length();i++)
    {
        if(record[i]==',' || record[i]==' ')
        {
            commaCount++;
        }
        else if(commaCount==field)
        {
            if(record[i]!='[' && record[i]!=']')
            {
                item=item+record[i];
            }
        }
    }

    return item;
}
void readFromFile(string filename,string name[],int minOrders[],int arr1[],int size1,int arr2[],int size2)
{
    string line="";
    int index=0;
    int data=0;

    fstream file;
    file.open(filename,ios::in);
    while(!file.eof())
    {
        getline(file,line);
        name[index]=getFields(line,1);
        minOrders[index]=stoi(getFields(line,2));

        if(data==0)
        {
            for(int i=0;i<size1;i++)
            {
                arr1[i]=stoi(getFields(line,i+3));
            }
        }
        else if(data!=0)
        {
            for(int i=0;i<size2;i++)
            {
                arr2[i]=stoi(getFields(line,i+3));
            }
        }       
        data++;
        index++;
    }
}
string pizzaPoints(int orders,int price,string name[],int arr1[],int size1,int arr2[],int size2)
{
    string result="";
    int check1=0,check2=0;

    for(int i=0;i<size1;i++)
    {
        if(arr1[i]>=price)
        {
            check1++;
        }
    }

    for(int i=0;i<size2;i++)
    {
        if(arr2[i]>=price)
        {
            check2++;
        }
    }

    if(check1>=orders)
    {
        result=result+name[0]+"\n";
    }
    if(check2>=orders)
    {
        result=result+name[1]+"\n";
    }

    return result;
}
