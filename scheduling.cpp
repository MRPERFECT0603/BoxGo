#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;
void scheduling(pair<char,int> profit[] , int deadline[] , int ndeadline)
{
    int arr[ndeadline];
    for(int i=0;i<ndeadline;i++)
    {
        arr[i] = 0;
    }
    for(int i=0;i<ndeadline;i++)
    {
        for(int j=deadline[i]-1;j>=0;j--)
        {
            if(arr[j]==0)
            {
                arr[j] = profit[i].second;
                break;
            }
        }
    }
    for(int i=0;i<ndeadline;i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<ndeadline;i++)
    {
        for(int j=0;j<ndeadline;j++)
        {
            if(profit[j].second == arr[i])
            {
                cout<<profit[j].first<<" ";
            }
        }
    }
}
int main()
{
    pair<char,int> profit[] = {make_pair('a',100),make_pair('b',27),make_pair('c',25),make_pair('d',19),make_pair('e',15)};
    int deadline[] = {2,2,1,1,3};
    int ndeadline = sizeof(deadline)/sizeof(int);
    scheduling(profit,deadline,ndeadline);
    return 0;
}