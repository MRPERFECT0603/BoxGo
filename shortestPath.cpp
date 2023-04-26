#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void addEdge(vector<int> graph[] , int v , int u)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void PrintGraph(vector<int> graph[] , int v)
{
    for(int i = 0;i<v;i++)
    {
        for(int u:graph[i])
        {
            cout<<u<<" ";
        }
        cout<<endl;
    }
}
void shortestPath(vector<int> graph[] , int v , int source , int destination)
{
    bool visted[v];
    int distance[v];
    for(int i = 0; i<v;i++)
    {
        visted[i] = false;
        distance[i] = 0;
    }
    distance[source] = 0;
    queue<int> q;
    q.push(source);
    visted[source] = true;
    while(q.empty() == false)
    { 
        int u = q.front();
        q.pop();
        for(int v : graph[u])
        {
            if(visted[v] == false)
            {
                distance[v] = distance[u]+1;
                visted[v] = true;
                q.push(v);
            }
        }
    }
    if(distance[destination] != 0)
    cout<<"the shortest Distance between the source and the destination:"<<distance[destination]<<endl;
    else
    cout<<"no path between the source and the destination."<<endl;
}
int main()
{
    int vertex = 6;
    vector<int> vivek[vertex];
    addEdge(vivek , 0 , 2);
    addEdge(vivek , 1 , 3);
    addEdge(vivek , 1 , 5);
    addEdge(vivek , 2 , 3);
    addEdge(vivek , 2 , 4);
    addEdge(vivek , 3 , 5);
    addEdge(vivek , 4 , 5);
    // PrintGraph(vivek , vertex);
    shortestPath(vivek , vertex , 0,4);
    return 0;
}