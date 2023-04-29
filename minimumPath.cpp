#include <iostream>
#include <climits>
#include<string>
#include  "database.h"
using namespace std;

#define V 6

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

void printSolution(int dist[], int parent[], int src, string places[]) {
    cout << "Vertex   Distance   Path\n";
    for (int i = 0; i < V; i++) {
        cout << src << " -> " << i << "       " << dist[i] << "       " << src << " ";
        printPath(parent, i);
        cout << endl;
    }
    cout<<"enter the location"<<endl;
    string dest;
    cin>>dest;
    int desvar;
    for(int i=0;i<V;i++)
    {
        if(places[i] == dest)
        {
            desvar = i;
            break;
        }
        else desvar=-1;
    }
    if(desvar!=-1)
    {
        cout<<"Main Office -> "<<dest<<dist[desvar]<<endl;
        cout<<"Path to follow:"<<src<<" ";
        printPath(parent, desvar);
    }
}

void dijkstra(int graph[V][V], string places[],int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, parent, src, places);
}

int main() {
    // string places[] = {"Delhi" , "Mumbai", "Kolkata" , "Chennai" , "Kerala" , "Patna"};
    // int graph[V][V] = {{0, 4, 0, 0, 0, 0},
    //                    {4, 0, 8, 0, 0, 0},
    //                    {0, 8, 0, 7, 0, 4},
    //                    {0, 0, 7, 0, 9, 14},
    //                    {0, 0, 0, 9, 0, 10},
    //                    {0, 0, 4, 14, 10, 0}};
    database();
    dijkstra(graph, places,0);
    return 0;
}
 