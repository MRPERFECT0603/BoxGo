#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<unistd.h> 
#include<iomanip>
#define wt 10
using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_arr[n1], right_arr[n2];

    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (left_arr[i] >= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int knapsack(vector<int> v , vector<int> w,int count)
{
    int nv = v.size();
    int nw = w.size();
    if(nw==0)
    {
        return 0;
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
    // for(int i = 0;i<=nw;i++)
    // {
    //     for(int j = 0;j<=wt;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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
    // for(int i = 0;i<=nw;i++)
    // {
    //     for(int j = 0;j<=wt;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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
    // for(int i = 0;i<=nw;i++)
    // {
    //     for(int j = 0;j<=wt;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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
    cout<<"Box "<<count<<":  ";
    for (int i = items.size() - 1; i >= 0; i--)
    {
        // cout << items[i] << " "; 
        cout<<w[items[i]]<<" ";
    } 
    count++;
    cout << endl;
    for(int i=0;i<items.size();i++)
    {
        v.erase(v.begin() + items[i]);
        w.erase(w.begin() + items[i]);
    }
    knapsack(v,w,count);
    return 0;
}
int maxvalue()
{
    ifstream infile("Boxcontent.TXT");
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }
    int rows = 0;
    string line;
    while (getline(infile, line)) {
        rows++;
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    --rows;
    string header;
    getline(infile,header);
    // define the arrays
    int profit[rows];
    int weight[rows];

    // read the data into the arrays
    for (int i = 0; i < rows; i++) {
        infile >> profit[i] >> weight[i];
    }
    // print the data for verification
    // for (int i = 0; i < rows; i++) {
    //     cout << length[i] << " " << width[i] << " " << height[i] << endl;
    // }
    // cout<<sizeof(length)/sizeof(int);
    // close the file
    infile.close();
    int x = sizeof(profit)/sizeof(int);
    int pcopy[x];
    int wcopy[x];
    for(int i=0;i<x;i++)
    {
        pcopy[i] = profit[i];
    }
    // cout << "Given array is \n";
    // for (int i = 0; i < x; i++)
    //     cout << hcopy[i] << " ";

    // mergeSort(pcopy, 0, x - 1);

    // cout << "\nSorted array is \n";
    // for (int i = 0; i < x; i++)
    // {
    //     cout << hcopy[i] << " ";
    // }
    cout<<endl;
    for (int i = 0; i < x; i++)
    {
        for(int j=0;j<x;j++)
        {
            if(pcopy[i]==profit[j])
            {
                wcopy[i]=weight[j];
            }
        }
    }
    // for (int i = 0; i < x; i++)
    // {
    //     cout << pcopy[i] << " ";
    // }
    // cout<<endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout << wcopy[i] << " ";
    // }
    vector<int> vpcopy;
    vector<int> vwcopy;
    for(int i=0;i<x;i++)
    {
        vpcopy.push_back(pcopy[i]);
        vwcopy.push_back(wcopy[i]);
    }
    cout<<endl;
    int count=1;
    knapsack(vpcopy,vwcopy,count);
    return 0;
}
int main()
{
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(30);
    // v.push_back(60);
    // v.push_back(50);
    // vector<int> w;
    // w.push_back(6);
    // w.push_back(3);
    // w.push_back(7);
    // w.push_back(2);
    // int wt =10;
    // knapsack(v,w,wt);
    maxvalue();
    return 0;
}