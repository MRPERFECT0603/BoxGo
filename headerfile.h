#ifndef HEADERFORMAT_H
#define HEADERFORMAT_H
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<ctime>
using namespace std;

//FUNCTION TO PRINT THE DATE AND TIME ON THE SCREEN

void showTime()
{
    
     // get the current time
    time_t now = time(0);

    // convert the current time to string form
    char* time_str = ctime(&now);

    // print the current time on the terminal
    cout<<setw(156);
    cout << "You Logged in at: "<<endl;
    cout<<setw(156);
    cout<< time_str << endl;
}

//CLEAR SCREEN FUNCTION 

void ClearScreen()
{
    system("clear");
}

//FUNCTION TO PRINT THE FORMAT OF HEADER ON THE SCREEN

void headerFormat()
{ 
    ClearScreen();
    for(int i=0;i<156;i++)
    {
        cout<<"-";                                                                                                                          
    }
    cout<<endl;
    for(int i=0;i<1;i++)
    {
        cout<<endl;
    }
    showTime();
    for(int i=0;i<1;i++)
    {
        cout<<endl;
    }
    cout<<setw(95)<<"     ____             ______         "<<endl;           
    cout<<setw(94)<<"   / __ )____  _  __/ ____/___     "<<endl;           
    cout<<setw(93)<<"  / __  / __ \\| |/_/ / __/ __ \\   "<<endl;              
    cout<<setw(92)<<" / /_/ / /_/ />  </ /_/ / /_/ /  "<<endl;               
    cout<<setw(91)<<"/_____/\\____/_/|_|\\____/\\____/  "<<endl;
    cout<<setw(100)<<"Har baar delivery ka samaan, BoxGo se karo aasaan."<<endl;
    for(int i=0;i<2;i++)
    {
        cout<<endl;
    }
    for(int i=0;i<156;i++)
    {
        cout<<"-";                                                                                                                          
    }
}

//FOOTER FORMAT PRINT ON THE SCREEN

void FooterFormat(int x)
{
    for(int i=0;i<x;i++)
    {
        cout<<endl;
    }
    for(int i=0;i<156;i++)
    {
        cout<<"-";                                                                                                                          
    }
    cout<<"@copyright by Vivek Shaurya";
}

//FUNCTION TO PRINT THE LAST PAGE AND THANK YOU NOTE

void lastPage()
{
    ClearScreen();
    headerFormat();
    cout<<endl<<endl<<endl<<endl;
    cout<<setw(90)<<"Thank You for Using BoxGo."<<endl<<endl;
    cout<<setw(90)<<"--------------------------"<<endl<<endl;
    cout<<setw(90)<<"Designed and Developed by:-"<<endl<<endl;
    cout<<setw(90)<<"--------------------------"<<endl<<endl;
    cout<<setw(85)<<"1. Vivek Shaurya."<<endl;
    cout<<setw(83)<<"2. Ansh Mishra."<<endl;
    cout<<setw(83)<<"3. Sanat Walia."<<endl;
    cout<<setw(84)<<"4. Yashvin Pant."<<endl<<endl;
    cout<<setw(90)<<"--------------------------"<<endl<<endl;
    FooterFormat(8);
}
#endif