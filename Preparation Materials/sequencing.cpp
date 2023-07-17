#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

void activitySelection(vector<pair<int,int> > duration, int num_act)
{
    // Sort the vector in descending order of second value
    sort(duration.begin(), duration.end(), compareSecond);
    vector<pair<int,int> > activity;
    activity.push_back(duration[0]);
    int j=0;
    for(int i=1;i<duration.size();i++)
    {
        if(activity[j].second<=duration[i].first)
        {
            activity.push_back(duration[i]);
            j++;
        }
    }
    for(int i=0;i<activity.size();i++)
    {
       cout<<activity[i].first<<","<<activity[i].second<<"    ";
    }
}
int main()
{
    vector<pair<int,int> > duration;
    duration.push_back(make_pair(3,8));
    duration.push_back(make_pair(2,4));
    duration.push_back(make_pair(1,3));
    duration.push_back(make_pair(10,11));
    activitySelection(duration ,4);
    return 0;
}
