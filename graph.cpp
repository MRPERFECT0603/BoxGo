#include <iostream>
#include <vector>

using namespace std;

// Define the graph representing the problem using an adjacency matrix
const int num_trucks = 10;
const int num_loading_areas = 4;
bool graph[num_trucks][num_trucks] = {
    {false, true, true, false, false, false, false, false, false, false},
    {true, false, true, false, false, false, false, false, false, false},
    {true, true, false, true, false, false, false, false, false, false},
    {false, false, true, false, false, false, false, false, false, false},
    {false, false, false, false, false, true, true, false, false, false},
    {false, false, false, false, true, false, true, false, false, false},
    {false, false, false, false, true, true, false, true, false, false},
    {false, false, false, false, false, false, true, false, false, false},
    {false, false, false, false, false, false, false, false, false, true},
    {false, false, false, false, false, false, false, false, true, false}
};

// Helper function to check if a color can be assigned to a vertex
bool is_color_valid(int v, vector<int>& colors, int c) {
    for (int i = 0; i < num_trucks; ++i) {
        if (graph[v][i] && colors[i] == c) {
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

int main()
{
    vector<int> colors(num_trucks, -1);
    if (color_graph_backtracking(colors, 0)) {
        // Print the resulting schedule
        for (int i = 0; i <= num_loading_areas; ++i) {
            cout << "Loading area " << i << ": ";
            for (int j = 0; j < num_trucks; ++j) {
                if (colors[j] == i) {
                    cout << "Truck " << j << " (duration " << j+1 << ") ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "No valid coloring exists." << endl;
    }

    return 0;
}
