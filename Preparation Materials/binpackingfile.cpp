#include <iostream>
#include <fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<unistd.h> 
#include<iomanip>
#define truckwidth 50
#define truckheight 50
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
int bestfitdata()
{
    // open the file
    ifstream infile("Boxes.txt");
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
    int length[rows];
    int width[rows];
    int height[rows];

    // read the data into the arrays
    for (int i = 0; i < rows; i++) {
        infile >> length[i] >> width[i] >> height[i];
    }

    // print the data for verification
    // for (int i = 0; i < rows; i++) {
    //     cout << length[i] << " " << width[i] << " " << height[i] << endl;
    // }
    // cout<<sizeof(length)/sizeof(int);
    // close the file
    infile.close();
    int x = sizeof(height)/sizeof(int);
    int hcopy[x];
    int wcopy[x];
    int lcopy[x];
    for(int i=0;i<x;i++)
    {
        hcopy[i] = height[i];
    }
    // cout << "Given array is \n";
    // for (int i = 0; i < x; i++)
    //     cout << hcopy[i] << " ";

    mergeSort(hcopy, 0, x - 1);

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
            if(hcopy[i]==height[j])
            {
                wcopy[i]=width[j];
                lcopy[i]=length[j];
            }
        }
    }
    // for (int i = 0; i < x; i++)
    // {
    //     cout << hcopy[i] << " ";
    // }
    // cout<<endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout << wcopy[i] << " ";
    // }
    // cout<<endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout << lcopy[i] << " ";
    // }
    bestFit(hcopy,wcopy,lcopy,x);
    return 0;
}
int main() {
    
    bestfitdata();
    return 0;
}
