#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int mini=0,semi=0,heavy=0;
    int array[] = {12,11,9,8,6,4};
    int k=(sizeof(array)/sizeof(int))-1;
    int sum=0;
    while(k>=0)
    {
        if(sum==0 && k==0)
        break;
        sum+=array[k];
        if(sum<12)
        {
            k--;
        }
        else if(sum>=12)
        {
            sum-=array[k];
            if(sum>=1 && sum<=4)
            {
                // cout<<"Mini"<<endl;
                mini++;
                sum=0;
            }
            else if(sum>=5 && sum<=8)
            {
                // cout<<"Semi"<<endl;
                semi++;
                sum=0;
            }
            else if(sum>=9 && sum<=12)
            {
                // cout<<"Heavy"<<endl;
                heavy++;
                sum=0;
            }
        }
    }
    if(array[0]>=1 && array[0]<=4)
    {
        // cout<<"Mini"<<endl;
        mini++;
                
    }
    else if(array[0]>=5 && array[0]<=8)
    {
        // cout<<"Semi"<<endl;
        semi++;
                
    }
    else if(array[0]>=9 && array[0]<=12)
    {
        // cout<<"Heavy"<<endl;
        heavy++;
                
    }
    cout<<mini<<' '<<semi<<" "<<heavy<<endl;
    return 0;
}