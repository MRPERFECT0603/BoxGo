#ifndef database_h
#define database_h

#include <iostream>
#include <climits>
#include<string>
#define V 6
#define num_trucks 10
#define num_loading_areas 3
using namespace std;
//GLOBAL DATA STRUCTURE TO GET ACCESS EVERYWHERE IN THE MAIN FILE 
static string places[V];
static int graph[V][V];
static bool graphcolour[num_trucks][num_trucks];
//DATABASE FOR THE PATHS AND THE PLACES 
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
//GRAPH FOR THE TRUCKS AND OVERLAPPING SCHEDULE 
void coloringGraph()
{
    bool graph[num_trucks][num_trucks] = {
    {false, true, true, false, false, false, false, false, false, false},
    {true, false, true, false, false, false, false, false, false, false},
    {true, true, false, true, false, false, false, false, false, false},
    {false, false, true, false, false, false, false, false, false, false},
    {false, false, false, false, false, true, true, false, false, false},
    {false, false, false, false, true, false, true, false, false, false},
    {false, false, false, false, true, true, false, true, false, false},
    {false, false, false, false, false, false, true, false, false, false},
    {false, false, false, false, false, false, false, false, false, true},
    {false, false, false, false, false, false, false, false, true, false}
};
    for(int i=0;i<num_trucks;i++)
    {
        for(int j=0;j<num_trucks;j++)
        {
            graphcolour[i][j] = graph[i][j];
        }
    }
}
#endif