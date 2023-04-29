#ifndef database_h
#define database_h

#include <iostream>
#include <climits>
#include<string>
#define V 6
using namespace std;
static string places[V];
static int graph[V][V];

void database()
{
    int graph[V][V];
    string places[V];
        string placesdb[] = {"Delhi" , "Mumbai", "Kolkata" , "Chennai" , "Kerala" , "Patna"};
        int graphdb[V][V] = {{0, 4, 0, 0, 0, 0},
                       {4, 0, 8, 0, 0, 0},
                       {0, 8, 0, 7, 0, 4},
                       {0, 0, 7, 0, 9, 14},
                       {0, 0, 0, 9, 0, 10},
                       {0, 0, 4, 14, 10, 0}};
    for (int i = 0; i < 6; i++) 
    {
        ::places[i] = placesdb[i];
        for (int j = 0; j < 6; j++) 
        {
            ::graph[i][j] = graphdb[i][j];
        }
    }

}
#endif