#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include "animation.h"
#include "headerfile.h"
#include "database.h"
#include<vector>
#include<utility>
#include<unistd.h> 
#include<iomanip>
#define truckwidth 50
#define truckheight 50
#define wt 10
#define V 6
using namespace std;
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
        
    return min_index;
}

void printPath(int parent[], int j) 
{
    if (parent[j] == -1)
    {
        return;
    }
    printPath(parent, parent[j]);
    cout << j << " ";
}

void printSolution(int dist[], int parent[], int src, string places[]) 
{
    // cout << "Vertex   Distance   Path\n";
    // for (int i = 0; i < V; i++) {
    //     cout << src << " -> " << i << "       " << dist[i] << "       " << src << " ";
    //     printPath(parent, i);
    //     cout << endl;
    // }
    cout<<"enter the location"<<endl;
    string dest;
    cin>>dest;
    int desvar;
    for(int i=0;i<V;i++)
    {
        if(places[i] == dest)
        {
            desvar = i;
            break;
        }
        else desvar=-1;
    }
    if(desvar!=-1)
    {
        cout<<"Main Office -> "<<dest<<dist[desvar]<<endl;
        cout<<"Path to follow:"<<src<<" ";
        printPath(parent, desvar);
    }
}

void dijkstra(int graph[V][V], string places[],int src) 
{
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) 
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
            
    }
    printSolution(dist, parent, src, places);
}
void ShortestPath()
{
    ClearScreen();
    headerFormat();
    database();
    dijkstra(graph, places,0);
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
void mainPage()
{
    label:ClearScreen();
    headerFormat();
    cout<<"CHOOSE FROM THE BELOW OPTION"<<endl;
    cout<<"1. Find the Combination to get maximum value in a box."<<endl;
    cout<<"2. Findout the Minimum number of Trucks Needed."<<endl;
    cout<<"3. Schedule Your trucks on loading dock for maximizing profit."<<endl;
    cout<<"4. Find the Shortest Path to a given Place."<<endl;
    cout<<"5. Ansh/Sanat"<<endl;
    int option;
    cin>>option;
    switch(option)
    {
        case 1:
            maxvalue();
        break;
        case 2:
            bestfitdata();
        break;
        case 3:
        break;
        case 4:
            ShortestPath();
        break;
        case 5:
        break;
        default:
        cout<<"Wrong option choosed, Please Pick the correct Number.";
        goto label;
    }

}
int loginAccess()
{
   ifstream infile("LoginDetails.txt");
    if (!infile.is_open())
    {
        cerr << "Error: Unable to open file!" << endl;
        return -1;
    }
    int ROWS = 0;
    string line;
    while (getline(infile, line))
    {
        ROWS++;
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    --ROWS;
    string header;
    getline(infile, header);

    const int COLS = 2;
    // define the 2D array
    string data[ROWS][COLS];

    // read the data into the 2D array
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            infile >> data[i][j];
        }
    }

    // print the data for verification
    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    string user;
    string password;
    cout<<"enter the username"<<endl;
    cin>>user;
    cout<<"enter the password"<<endl;
    cin>>password;
    for(int i=0;i<ROWS;i++)
    {
        if(data[i][0] == user)
        {
            if(data[i][1] == password)
            return 1;
            else
            return 0;
        }
    }
    // close the file
    infile.close();
    return -2;
    
}
void loginWrap()
{
    label:headerFormat();
    /*
    -1 == Error in opening the file.
    1 == Access granted.
    0 == Access denied.
    -2 == username not found.
    */
    int output;
    output = loginAccess(); 
    if(output == -2)
    {
        cout<<"UserName not found."<<endl;
        cout<<"Please Enter the correct UserName."<<endl;
        sleep(3);
        goto label;
    }
    if(output == -1)
    {
        cout<<"Error in opening the Database."<<endl;
        sleep(3);
    }
    if(output == 0)
    {
        cout<<"Incorrect Password, Use the correct password."<<endl;
        sleep(3);
        goto label;
        
    }
    if(output == 1)
    {
        cout<<"Access Granted."<<endl;
        sleep(1);
        mainPage();
    }
}
int main()
{
    // printanimation();
    loginWrap();
    return 0;
}