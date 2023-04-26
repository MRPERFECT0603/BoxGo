#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<unistd.h> 
#include<iomanip>
#define truckwidth 50
#define truckheight 50
// #include"animation.h"
using namespace std;
pair<int,int> min(vector<int> vec , int box)
{
    int used = 0;
    int min = 0;
    int diff1,diff2= 0;
    for(int i=1;i<vec.size();i++)
    {
        diff1 = vec[i] - box;
        diff2 = vec[i-1] - box;
        if(diff1>=0 &&  diff2<0)
        {
            min = i;
            used = 1;
            break;
        }
        if(diff1>=0 && diff2>=0 && diff1<diff2)
        {
            min = i;
            used = 1;
            break;
        }
        if(diff2 >=0 &&  diff1<0)
        {
            min = i-1;
            used = 1;
            break;
        }
        if(diff2 >=0 && diff1>=0 && diff1>diff2)
        {
            min = i-1;
            used = 1;
            break;
        }
    }
    return make_pair(min,used);
}
void NoOfTrucks(vector<int> vec)
{
    int mini=0,semi=0,heavy=0;
    int k = vec.size();
    int sum=0;
    while(k>=0)
    {
        if(sum==0 && k==0)
        break;
        sum+=vec[k];
        if(sum<12)
        {
            k--;
        }
        else if(sum>=12)
        {
            sum-=vec[k];
            if(sum>=1 && sum<=4)
            {
                mini++;
                sum=0;
            }
            else if(sum>=5 && sum<=8)
            {
                semi++;
                sum=0;
            }
            else if(sum>=9 && sum<=12)
            {
                heavy++;
                sum=0;
            }
        }
    }
    if(vec[0]>=1 && vec[0]<=4)
    {
        mini++;
                
    }
    else if(vec[0]>=5 && vec[0]<=8)
    {
        semi++;           
    }
    else if(vec[0]>=9 && vec[0]<=12)
    {
        heavy++;            
    }
    cout<<"MINI-"<<mini<<endl<<"SEMI-"<<semi<<endl<<"HEAVY-"<<heavy<<endl;
    return ;
}
//in the below funcction we fixed the height of the trucks.
void trucks(vector<int> &h , vector<int> &l)
{
    vector<int> layer;
    layer.push_back(truckheight);
    vector<int> truckLength;
    layer[0] -= h[0];
    truckLength.push_back(l[0]);
    int v=0;
    for(int i=1;i<h.size();i++)
    {
        pair<int,int> requiredLayer = min(layer,h[i]);
        if(requiredLayer.second == 1)
        {
            layer[requiredLayer.first] -= h[i];
            v=1;
        }
        if(v==0)
        {
            layer.push_back(truckheight);
            layer.back() -= h[i];
            truckLength.push_back(l[i]);
        }
    }
    NoOfTrucks(truckLength);
    return ;
}
//fixed the width for the boxes in the below function.
void bestFit(int h[] , int w[] , int l[] , int x)
{
    vector<int> layer;
    layer.push_back(truckwidth);
    vector<int> heightNeeded;
    vector<int> lengthNeeded;
    layer[0] -= w[0];
    heightNeeded.push_back(h[0]);
    lengthNeeded.push_back(l[0]);
    int v=0;
    for(int i=1;i<x;i++)
    {
        pair<int,int> requiredLayer = min(layer,w[i]);
        // cout<<requiredLayer.first<<requiredLayer.second<<endl;
        if(requiredLayer.second == 1)
        {
            layer[requiredLayer.first] -= w[i];
            if(lengthNeeded[requiredLayer.first]<l[i])
            {
                lengthNeeded[requiredLayer.first] = l[i];
            }
            v=1;
        }
        if(v==0)
        {
            layer.push_back(truckwidth);
            layer.back() -= w[i];
            heightNeeded.push_back(h[i]);
            lengthNeeded.push_back(l[i]);
        }
    }
    trucks(heightNeeded,lengthNeeded);
    return ;
}
int main()
{
    // print();
    int h[] = {42,38,27,14,9};
    int w[] = {49,39,35,26,5};
    int l[] = {12,10,8,6,4};
    int x = sizeof(h)/sizeof(int);
    bestFit(h,w,l,x);
    return 0;
}