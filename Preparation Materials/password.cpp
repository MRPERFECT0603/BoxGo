#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int LoginAccess()
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
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
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
int main()
{
    cout<<LoginAccess();
    return 0;
}