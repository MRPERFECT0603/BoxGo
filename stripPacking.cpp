#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
//nextfit jishme directly dhabe dalte zate h 
int nextFit(int h[], int w[], int x )
{
    int givenBox = 30;
    int remainingw = 30;
    int heightneeded = 0;
    heightneeded = h[0];
    remainingw -= w[0];
    for(int i=1;i<x;i++)
    {
        if(remainingw>=w[i])
        {
            remainingw-=w[i];
        }
        else
        {
            heightneeded += h[i];
            remainingw = givenBox - w[i];
        }
    }
    return heightneeded;
}
//firstfit me second layer me dhabe dalne se phle first layer me check krte h fir daalte h 
int firstfitnew(int h[] , int w[] , int x)
{
    vector<int> layer;
    layer.push_back(30);
    int heightNeeded = 0;
    layer[0] -= w[0];
    heightNeeded += h[0];
    int v=0;
    for(int i=1;i<x;i++)
    {
        for(int j=0;j<layer.size();j++)
        {
            if(layer[j]>=w[i])
            {
                layer[j] -= w[i];
                v=1;
                break;
            }
        }
        if(v==0)
        {
            layer.push_back(30);
            layer.back() -= w[i];
            heightNeeded+= h[i];
        }
    }
    return heightNeeded;
}
pair<int,int> min(vector<int> vec , int box)
{
    int used = 0;
    int min = 0;
    int diff1,diff2= 0;
    for(int i=1;i<vec.size();i++)
    {
        diff1 = vec[i] - box;
        diff2 = vec[i-1] - box;
        if(diff1 >=0 &&  diff2<0)
        {
            min = i;
            used = 1;
        }
        if(diff1>=0 && diff2>=0 && diff1<diff2)
        {
            min = i;
            used = 1;
        }
        if(diff2 >=0 &&  diff1<0)
        {
            min = i-1;
            used = 1;
        }
        if(diff2 >=0 && diff1>diff2 && diff1>=0)
        {
            min = i-1;
            used = 1;
        }
    }
    cout<<min<<used<<endl;
    return make_pair(min,used);
}
int bestFit(int h[] , int w[] , int x)
{
    vector<int> layer;
    layer.push_back(30);
    int heightNeeded = 0;
    layer[0] -= w[0];
    heightNeeded += h[0];
    int v=0;
    for(int i=1;i<x;i++)
    {
        pair<int,int> requiredLayer = min(layer,w[i]);
        if(requiredLayer.second == 1)
        {
            layer[requiredLayer.first] -= w[i];
            v=1;
        }
        if(v==0)
        {
            layer.push_back(30);
            layer.back() -= w[i];
            heightNeeded+= h[i];
        }
    }
    for(int i =0;i<layer.size();i++)
    {
        cout<<layer[i]<<" ";
    }
    return heightNeeded;
}
int main()
{
    int h[] = {27,10,9,6,3};
    int w[] = {26,22,6,4,2};
    int l[] = {3,1,4,10,7};
    int x = sizeof(h)/sizeof(int);
    cout<<bestFit(h,w,x);
    return 0;
}


/*
//nextfit jishme directly dhabe dalte zate h 
int nextFit(int h[], int w[], int x )
{
    int givenBox = 30;
    int remainingw = 30;
    int heightneeded = 0;
    heightneeded = h[0];
    remainingw -= w[0];
    for(int i=1;i<x;i++)
    {
        if(remainingw>=w[i])
        {
            remainingw-=w[i];
        }
        else
        {
            heightneeded += h[i];
            remainingw = givenBox - w[i];
        }
    }
    return heightneeded;
}
//firstfit me second layer me dhabe dalne se phle first layer me check krte h fir daalte h 
int firstfitnew(int h[] , int w[] , int x)
{
    vector<int> layer;
    layer.push_back(30);
    int heightNeeded = 0;
    layer[0] -= w[0];
    heightNeeded += h[0];
    int v=0;
    for(int i=1;i<x;i++)
    {
        for(int j=0;j<layer.size();j++)
        {
            if(layer[j]>=w[i])
            {
                layer[j] -= w[i];
                v=1;
                break;
            }
        }
        if(v==0)
        {
            layer.push_back(30);
            layer.back() -= w[i];
            heightNeeded+= h[i];
        }
    }
    return heightNeeded;
}
*/