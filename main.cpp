/*                              *******JAYPPEE INSTITUE OF INFORMATION TECHNOLOGY*******
                                                       SEC-62

                                          *ALGORITHM AND PROBLEM SOLVING*
                
                                             SEMESTER-4 MINOR PROJECT


                INTRODUCTION:
                *                  *A ONE STOP SOLUTION FOR THE MOVERS AND PACKERS*             *
                    
                *                                     *BOXGO*                                   *


                SUBMITTED TO:-
                Dr. ANKITA WADHWA
                Dr. KRITI JAIN
                Dr. PURTEE KHOLI
                

                SUMITTED BY:-
                
                1.VIVEK SHAURYA   (21803013)
                2.ANSH MISHRA     (21803011)
                3.SANAT WALIA     (21803012)
                4.YASHVIN PANT    (21803009)

*/



//HEADER FILES 
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<utility>
#include<unistd.h> 
#include<iomanip>

//USER-DEFINED HEADER FILES
#include "animation.h"
#include "headerfile.h"
#include "database.h"

//SOME USER-DEFINED CONSTANTS 
#define truckwidth 40
#define truckheight 40
#define wt 10
#define V 6

using namespace std;

//ALL THE FUNCTIONS DECALARATION 
int minDistance(int dist[], bool sptSet[]);
void printPath(int parent[], int j, string places[]);
void printSolution(int dist[], int parent[], int src, string places[]);
void dijkstra(int graph[V][V], string places[],int src);
void ShortestPath();
int knapsack(vector<int> v , vector<int> w,int count);
int maxvalue();
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
pair<int,int> min(vector<int> vec , int box);
void NoOfTrucks(vector<int> vec);
void trucks(vector<int> &h , vector<int> &l);
void bestFit(int h[] , int w[] , int l[] , int x);
int bestfitdata();
void schedulingonprofit(pair<string,int> profit[] , int deadline[] , int ndeadline);
int scheduling();
bool is_color_valid(int v, vector<int>& colors, int c);
bool color_graph_backtracking(vector<int>& colors, int v);
void SlotBooking();
bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b);
void activitySelection(vector<pair<int,int> > duration, int num_act);
int sequencingData();
void mainPage();
int loginAccess();
void loginWrap();

//MINIMUM DISTANCE BETWEEN TWO VERTICES 

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

//PRINTING THE PATH 

void printPath(int parent[], int j, string places[]) 
{
    if (parent[j] == -1)
    {
        return;
    }
    printPath(parent, parent[j],places);
    cout<< "->"<<places[j] ;
}

//PRINTING THE PATH FOR ASKED PLACE

void printSolution(int dist[], int parent[], int src, string places[]) 
{
    // cout << "Vertex   Distance   Path\n";
    // for (int i = 0; i < V; i++) {
    //     cout << src << " -> " << i << "       " << dist[i] << "       " << src << " ";
    //     printPath(parent, i);
    //     cout << endl;
    // }
    cout<<endl<<endl;
    cout<<setw(85)<<"Enter the Destination:"<<endl;
    cout<<setw(70)<<"->";
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
        cout<<endl<<endl;
        cout<<setw(70)<<"Main Office -> "<<dest<<"  *Distance: "<<dist[desvar]<<"KM"<<endl;
        cout<<endl;
        cout<<setw(70)<<"Path to follow: "<<places[0];
        printPath(parent, desvar, places);
    }

    else
    {
        cout<<endl<<setw(105)<<"Destination Not in the Database.Pleace Update  your Database.";
    }
}

//DIJKSTRA ALGORITHM FOR FINDING THE MINIMUM PATH BETWEEN TWO VERTICES 

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

//WRAP FUNTION FOR THE DIJKSTRA ALGORITHM

void ShortestPath()
{
    ClearScreen();
    headerFormat();
    database();
    dijkstra(graph, places,0);
}

//DP APPROACH FOR FILLING THE ARRAY OF 0-1 KNAPSACK

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
    cout<<endl<<endl;
    cout<<setw(72)<<"Box "<<count<<":  ";
    for (int i = items.size() - 1; i >= 0; i--)
    {
        // cout << items[i] << " "; 
        cout<<w[items[i]]<<" ";                                     //HERE BACKTRACKING TO GET THE COMBINATION FOR MAXIMUM VALUE AND THEN AGAIN CALLING THE KANPSACK FOR REMAINING ITEMS 
    } 
    cout << endl;
    cout<<setw(64);
    for(int i=0;i<20;i++)
    {
        cout<<"-";
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

//WRAP FUNCTION TO GET THE VALUES FROM THE FILE AND CALLING THE KANPSACK FUNCTION

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

// MERGE FUNCTION THE UTLILTY FUNCTION FOR MERGE SORT 

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

// MERGE SORT FUNCTION TO SORT THE ARRAYS USED IN THE PROGRAMS IN DESCENDING

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//PAIR FOR THE LENGTHS TO GET MINIMUM NUMBER OF TRUCKS

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

//FINALLY AFTER GETTING THE LENGTH ARRAY GIVING THE NUMBER OF MINI,SEMI AND HEAVY TRUCKS

/*
1-2->MINI
5-8->SEMI
9-12->HEAVY
*/

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
    cout<<endl<<endl;
    cout<<setw(73)<<"*MINI-"<<mini<<endl<<endl<<setw(73)<<"*SEMI-"<<semi<<endl<<endl<<setw(73)<<"*HEAVY-"<<heavy<<endl;
    FooterFormat(15);
    return ;
}

//in the below function we fixed the height of the trucks.

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
    // for(int i=0;i<heightNeeded.size();i++)
    // {
    //     cout<<heightNeeded[i]<<lengthNeeded[i]<<endl;
    // }
    trucks(heightNeeded,lengthNeeded);
    return ;
}

//FUNCTION TO GET THE DATA FROM THE FILE IN THE PROGRAMME TO CALL THE BOX-FITTING ALGORITHM

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

    mergeSort(hcopy, 0, x - 1);

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

//SCHEDULLING THE TRUCKS ON THE BASIS OF PROFIT (JOB-SCHEDULLING APPROACH)

void schedulingonprofit(pair<string,int> profit[] , int deadline[] , int ndeadline)
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
    // for(int i=0;i<ndeadline;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    cout<<setw(95)<<"Schedule Your Orders in the given Sequence:";
    int count=1;
    for(int i=0;i<ndeadline;i++)
    {
        for(int j=0;j<ndeadline;j++)
        {
            if(profit[j].second == arr[i])
            {
                cout<<endl<<endl;
                cout<<setw(70)<<count<<". "<<profit[j].first<<" ";
                count++;
            }
        }
    }
    FooterFormat(18);
}

//TAKING THE DATA FROM THE FILE AND CALL SCHEDULLING FUNCTION 

int scheduling()
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

    mergeSort(pcopy, 0, x - 1);

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
    // for (int i = 0; i < x; i++)
    // {
    //     cout << pcopy[i] << " ";
    // }
    // cout<<endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout << dcopy[i] << " ";
    // }
    // cout<<endl;
    // for (int i = 0; i < x; i++)
    // {
    //     cout << destcopy[i] << " ";
    // }
    pair<string,int> ppcopy[x];
    for(int i=0;i<x;i++)
    {
        ppcopy[i] = make_pair(destcopy[i],pcopy[i]);
    }
    schedulingonprofit(ppcopy,dcopy,x);
    return 0;
}

// Helper function to check if a color can be assigned to a vertex

bool is_color_valid(int v, vector<int>& colors, int c) {
    coloringGraph();
    for (int i = 0; i < num_trucks; ++i) {
        if (graphcolour[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

// Backtracking function to color the graph

bool color_graph_backtracking(vector<int>& colors, int v) {
    if (v == num_trucks) {
        return true; // All vertices have been colored
    }
    for (int c = 0; c < num_loading_areas; ++c) {
        if (is_color_valid(v, colors, c)) {
            colors[v] = c; // Assign color to vertex v
            if (color_graph_backtracking(colors, v+1)) {
                return true; // Continue coloring remaining vertices
            }
            colors[v] = -1; // Reset color assignment for vertex v
        }
    }
    return false; // No valid color can be assigned to vertex v
}

//CHECKING THE BACKTRACKING USING MAP-COLOURING AND PRINTING THE VALUE

void SlotBooking()
{
    ClearScreen();
    headerFormat();
    vector<int> colors(num_trucks, -1);
    if (color_graph_backtracking(colors, 0)) {
        // Print the resulting schedule
        cout<<endl<<endl;
        for (int i = 0; i <= num_loading_areas; ++i) {
            cout<<setw(60)<< "Loading area " << i+1 << ": ";
            for (int j = 0; j < num_trucks; ++j) {
                if (colors[j] == i) {
                    cout << "Truck " << j+1 << "    ";
                }
            }
            cout << endl<<endl;
        }
    } else {
        cout << "No valid coloring exists." << endl;
    }
    FooterFormat(15);

}

//UTILITY FUNCTION FOR THE SORT ALGO TO SORT ACCORDING TO THE DESCENDING ORDER OF SECOND VALUE

bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

//FUNCTION TO SELECT THE ACTIVITIES ON THE BASIS OF ARRIVAL AND DEPARTURE TIMMING 

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
    cout<<endl<<endl;
    cout<<setw(93)<<"Arrival Time     Departure Time"<<endl;
    for(int i=0;i<activity.size();i++)
    {
       cout<<setw(68)<<activity[i].first<<"                "<<activity[i].second<<"    "<<endl<<endl;
    }
    FooterFormat(17);
}

// GETTING THE DATA FOR SEQUENCING THE TRUCKS

int sequencingData()
{

    ifstream infile("Trucktimming.TXT");
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
    vector<pair<int,int> > timming;
    // read the data into the arrays
    int first=0,second=0;
    for (int i = 0; i < rows; i++) {
        infile >> first >>second;
        timming.push_back(make_pair(first,second));
    }
    // print the data for verification
    // for (int i = 0; i < rows; i++) {
    //     cout << Destination[i] << " " << deadline[i] << " " << profit[i] << endl;
    // }
    infile.close();
    activitySelection(timming , 4);
    return 0;
}

//MAIN PAGE FUNCTION FOR THE MENU CONTROL 

void mainPage()
{
    label:
    ClearScreen();
    headerFormat();
    cout<<endl<<endl;
    cout<<setw(57)<<endl;
    for(int i =0;i<36;i++)
    {
        cout<<"-";
    }
    cout<<endl<<endl;
    cout<<setw(88)<<"CHOOSE FROM THE BELOW OPTIONS"<<endl;
    cout<<setw(57)<<endl;
    for(int i =0;i<36;i++)
    {
        cout<<"-";
    }
    cout<<endl;
    cout<<setw(45);
    for(int i =0;i<60;i++)
    {
        cout<<"-";
    }
    cout<<endl<<endl;
    cout<<setw(100)<<"1. Find the Combination to get maximum value in a box."<<endl;
    cout<<setw(93)<<"2. Findout the Minimum number of Trucks Needed."<<endl;
    cout<<setw(108)<<"3. Schedule Your trucks on loading dock for maximizing profit."<<endl;
    cout<<setw(95)<<"4. Find the Shortest Path to a given Destination."<<endl;
    cout<<setw(79)<<"5. Slot Booking for Loading dock."<<endl;
    cout<<setw(93)<<"6. Sequencing truck according to their timming."<<endl;
    cout<<endl;
    cout<<setw(45);
    for(int i =0;i<60;i++)
    {
        cout<<"-";
    }
    cout<<endl;
    int option;
    int option1;
    cout<<setw(83)<<"Enter The Option Here"<<endl;
    cout<<setw(70)<<"->";
    cin>>option;
    switch(option)
    {
        case 1:
            ClearScreen();
            headerFormat();
            maxvalue();
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(88)<<"Press 1 to go the home screen."<<endl;
            cout<<setw(71)<<"->";
            cin>>option1;
            if(option1==1)
            {
                goto label;
            }
        break;
        case 2:
            ClearScreen();
            headerFormat();
            bestfitdata();
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(88)<<"Press 1 to go the home screen."<<endl;
            cout<<setw(71)<<"->";
            cin>>option1;
            if(option1==1)
            {
                goto label;
            }
        break;
        case 3:
            ClearScreen();
            headerFormat();
            scheduling();
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(88)<<"Press 1 to go the home screen."<<endl;
            cout<<setw(71)<<"->";
            cin>>option1;
            if(option1==1)
            {
                goto label;
            }
        break;
        case 4:
            ClearScreen();
            headerFormat();
            ShortestPath();
            // cout<<endl<<endl<<endl<<endl;
            FooterFormat(15);
            cout<<endl;
            cout<<setw(88)<<"Press 1 to go the home screen."<<endl;
            cout<<setw(71)<<"->";
            cin>>option1;
            if(option1==1)
            {
                goto label;
            }
        break;
        case 5:
            ClearScreen();
            headerFormat();
            SlotBooking();
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(88)<<"Press 1 to go the home screen."<<endl;
            cout<<setw(71)<<"->";
            cin>>option1;
            if(option1==1)
            {
                goto label;
            }
        break;
        case 6:
            ClearScreen();
            headerFormat();
            sequencingData();
            cout<<endl<<endl<<endl<<endl;
            cout<<setw(88)<<"Press 1 to go the home screen."<<endl;
            cout<<setw(71)<<"->";
            cin>>option1;
            if(option1==1)
            {
                goto label;
            }
        break;
        default:
        cout<<setw(100)<<"Wrong option choosed, Please Pick the correct Option."<<endl;
        sleep(1);
        ClearScreen();
        goto label;

    }

}

//LOGIN ACCESS FUNCTION TO CHECK PASSWORD AND USERNAME TO ACCESS THE PROGRAMME

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
    cout<<endl<<endl;
    cout<<setw(61);
    for(int i=0;i<30;i++)
    {
        cout<<"-";
    }
    cout<<endl<<endl;
    cout<<setw(85)<<"Enter the UserName:"<<endl;
    cout<<setw(72)<<"->";
    cin>>user;
    cout<<endl<<endl;
    cout<<setw(85)<<"Enter the Password:"<<endl;
    cout<<setw(72)<<"->";
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

//LOGIN WRAP FUNCTION FOR DIFFERENT SCENARIO.

void loginWrap()
{
    label:ClearScreen();
    cout<<endl<<endl<<endl<<endl<<endl;
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
        cout<<endl<<endl;
        cout<<setw(84)<<"UserName not found."<<endl;
        cout<<setw(91)<<"Please Enter the correct UserName."<<endl;
        sleep(2);
        goto label;
    }
    if(output == -1)
    {
        cout<<endl<<endl;
        cout<<setw(82)<<"Error in opening the Database."<<endl;
        sleep(2);
    }
    if(output == 0)
    {
        cout<<endl<<endl;
        cout<<setw(100)<<"Incorrect Password, Use the correct password."<<endl;
        sleep(2);
        goto label;
        
    }
    if(output == 1)
    {   cout<<endl<<endl;
        cout<<setw(82)<<"Access Granted."<<endl;
        sleep(1);
        mainPage();
    }
}

// MAIN FUNCTION (DRIVER FUNCTION)

int main()
{
    // printanimation(); 
    loginWrap();
    lastPage();
    return 0;
}