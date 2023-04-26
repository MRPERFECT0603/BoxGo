#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void knapsack(vector<int> v , vector<int> w ,int wt)
{
    int nv = v.size();
    int nw = w.size();
    if(nw==0)
    {
        return ;
    }
    int arr[nw+1][wt+1];
    //initializaing everyone to -1
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            arr[i][j] = -1;
        }
    }
    //just couting random stuff
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //making the corner cases 0
    for(int i=0;i<=nw;i++)
    {
        arr[i][0] = 0;
    }
    for(int i=0;i<=wt;i++)
    {
        arr[0][i] = 0;
    }
    //just couting random stuff
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //knapsack laga rha hu chill kr 
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
    //just couting random stuff
    for(int i = 0;i<=nw;i++)
    {
        for(int j = 0;j<=wt;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //deleting the ones zo hogya h
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
    //just couting random stuff
    for (int i = items.size() - 1; i >= 0; i--)
    {
        cout << items[i] << " ";
    }
    cout << endl;
    for(int i=0;i<items.size();i++)
    {
        v.erase(v.begin() + items[i]);
        w.erase(w.begin() + items[i]);
    }
    knapsack(v,w,wt);
    return ;
}
int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(60);
    v.push_back(50);
    vector<int> w;
    w.push_back(6);
    w.push_back(3);
    w.push_back(7);
    w.push_back(2);
    int wt =10;
    knapsack(v,w,wt);
    return 0;
}