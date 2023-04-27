#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include "animation.h"
#include "headerfile.h"
using namespace std;
void mainPage()
{
    label:ClearScreen();
    headerFormat();
    cout<<"CHOOSE FROM THE BELOW OPTION"<<endl;
    cout<<"1. Find the Combination to get maximum value in a box."<<endl;
    cout<<"2. Findout the Minimum number of Trucks Needed."<<endl;
    cout<<"3. Schedule Your trucks on loading dock for maximizing profit."<<endl;
    cout<<"4. Find the Shortest Path to a given Place."<<endl;
    cout<<"5. Ansh."<<endl;
    int option;
    cin>>option;
    switch(option)
    {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        default:
        cout<<"Wrong option choosed, Please Pick the correct Number.";
        goto label;
    }

}
int loginAccess()
{
   ifstream infile("LoginDetails.txt");
    if (!infile.is_open())
    {
        cerr << "Error: Unable to open file!" << endl;
        return -1;
    }
    int ROWS = 0;
    string line;
    while (getline(infile, line))
    {
        ROWS++;
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    --ROWS;
    string header;
    getline(infile, header);

    const int COLS = 2;
    // define the 2D array
    string data[ROWS][COLS];

    // read the data into the 2D array
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            infile >> data[i][j];
        }
    }

    // print the data for verification
    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    string user;
    string password;
    cout<<"enter the username"<<endl;
    cin>>user;
    cout<<"enter the password"<<endl;
    cin>>password;
    for(int i=0;i<ROWS;i++)
    {
        if(data[i][0] == user)
        {
            if(data[i][1] == password)
            return 1;
            else
            return 0;
        }
    }
    // close the file
    infile.close();
    return -2;
    
}
void loginWrap()
{
    label:headerFormat();
    /*
    -1 == Error in opening the file.
    1 == Access granted.
    0 == Access denied.
    -2 == username not found.
    */
    int output;
    output = loginAccess(); 
    if(output == -2)
    {
        cout<<"UserName not found."<<endl;
        cout<<"Please Enter the correct UserName."<<endl;
        sleep(3);
        goto label;
    }
    if(output == -1)
    {
        cout<<"Error in opening the Database."<<endl;
        sleep(3);
    }
    if(output == 0)
    {
        cout<<"Incorrect Password, Use the correct password."<<endl;
        sleep(3);
        goto label;
        
    }
    if(output == 1)
    {
        cout<<"Access Granted."<<endl;
        sleep(1);
        mainPage();
    }
}
int main()
{
    // printanimation();
    loginWrap();
    return 0;
}