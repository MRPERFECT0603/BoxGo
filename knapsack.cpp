#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int knapsack(int v[] , int nv , int w[] , int nw , int wt)
{
    int arr[nw+1][wt+1];
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            arr[i][j] = -1;
        }
    }
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=nw;i++)
    {
        arr[i][0] = 0;
    }
    for(int i=0;i<=wt;i++)
    {
        arr[0][i] = 0;
    }
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=nw;i++)
    {
        for(int j=1;j<=wt;j++)
        {
            if(w[i-1]>j)
            {
                arr[i][j] = arr[i-1][j];
            }
            else
            {
                arr[i][j] = max(v[i-1] + arr[i-1][j-w[i-1]] , arr[i-1][j]); 
            }
        }
    }
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int i = nw, j = wt;
    vector<int> items;
    while (i > 0 && j > 0) {
        if (arr[i][j] != arr[i-1][j])
        {
            items.push_back(i-1);
            j -= w[i-1];
        }
        i--;
    }
    for (int i = items.size() - 1; i >= 0; i--)
    {
        cout << items[i] << " ";
    }
    cout << endl;
    
    return arr[nw][wt];
}
int main()
{
    int v[] = {10,30,60,50};
    int w[] = {6,3,7,2};
    int wt =10;
    int nv = sizeof(v)/sizeof(int);
    int nw = sizeof(w)/sizeof(int);
    cout<<nw<<endl;
    knapsack(v,nv,w,nw,wt);
    return 0;
}