#include<iostream>
#include<string>
#include<algorithm>
#include <fstream>
#include<vector>
#include<utility>
#include<unistd.h> 
#include<iomanip>
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
void scheduling(pair<string,int> profit[] , int deadline[] , int ndeadline)
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
int schedullingData()
{
    ifstream infile("ShippingOrder.TXT");
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
    string Destination[rows];
    int deadline[rows];
    int profit[rows];

    // read the data into the arrays
    for (int i = 0; i < rows; i++) {
        infile >> Destination[i] >> deadline[i] >> profit[i];
    }
    // print the data for verification
    // for (int i = 0; i < rows; i++) {
    //     cout << Destination[i] << " " << deadline[i] << " " << profit[i] << endl;
    // }
    infile.close();
    int x = sizeof(deadline)/sizeof(int);
    string destcopy[x];
    int dcopy[x];
    int pcopy[x];
    for(int i=0;i<x;i++)
    {
        pcopy[i] = profit[i];
    }
    cout << "Given array is \n";
    for (int i = 0; i < x; i++)
        cout << pcopy[i] << " ";

    mergeSort(pcopy, 0, x - 1);

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
                dcopy[i]=deadline[j];
                destcopy[i]=Destination[j];
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        cout << pcopy[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < x; i++)
    {
        cout << dcopy[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < x; i++)
    {
        cout << destcopy[i] << " ";
    }
    pair<string,int> ppcopy[x];
    for(int i=0;i<x;i++)
    {
        ppcopy[i] = make_pair(destcopy[i],pcopy[i]);
    }
    scheduling(ppcopy,dcopy,x);
    return 0;
}
int main()
{
    // pair<string,int> profit[] = {make_pair("a",100),make_pair("b",27),make_pair("c",25),make_pair("d",19),make_pair("e",15)};
    // int deadline[] = {2,2,1,1,3};
    // int ndeadline = sizeof(deadline)/sizeof(int);
    schedullingData();
    // scheduling(profit,deadline,ndeadline);
    return 0;
}