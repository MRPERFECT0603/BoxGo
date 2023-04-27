// #ifndef ASCII_CAT_H
// #define ASCII_CAT_H

#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<ctime>
using namespace std;
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
void ClearScreen()
{
    system("clear");
}
void headerFormat()
{   for(int i=0;i<1;i++)
    {
        cout<<endl;
    }
    showTime();
    for(int i=0;i<1;i++)
    {
        cout<<endl;
    }
    cout<<setw(95)<<"    ____             ______         "<<endl;           
    cout<<setw(94)<<"   / __ )____  _  __/ ____/___     "<<endl;           
    cout<<setw(93)<<"  / __  / __ \\| |/_/ / __/ __ \\   "<<endl;              
    cout<<setw(92)<<" / /_/ / /_/ />  </ /_/ / /_/ /  "<<endl;               
    cout<<setw(91)<<"/_____/\\____/_/|_|\\____/\\____/  "<<endl;
    cout<<setw(80)<<"tagline"<<endl;
    for(int i=0;i<2;i++)
    {
        cout<<endl;
    }
    for(int i=0;i<156;i++)
    {
        cout<<"-";                                                                                                                          
    }
}
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
int main()
{
    ClearScreen();
    headerFormat();
    FooterFormat(30);
    return 0;
}
// #endif