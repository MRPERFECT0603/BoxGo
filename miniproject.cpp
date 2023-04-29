#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
using namespace std;
class Edge
{
public:
    int destinationVertexId;
    int weight;
    Edge() // default constructor
    {
    }
    Edge(int destVId, int w)
    {
        destinationVertexId = destVId;
        weight = w;
    }

    void setEdgeValues(int destVId, int w)
    {
        destinationVertexId = destVId;
        weight = w;
    }

    void setWeight(int w)
    {
        weight = w;
    }

    int getDestinationVertexId()
    {
        return destinationVertexId;
    }

    int getWeight()
    {
        return weight;
    }
};

class Vertex
{
public:
    int state_id;
    string state_name;

    list<Edge> edgelist;

    Vertex()
    {
        state_id = 0;
        state_name = " Unknown_Landmark ";
    }
    Vertex(int id, string sname)
    {
        state_id = id;

        state_name = sname;
    }

    int getStateid()
    {
        return state_id;
    }

    string getStateName()
    {
        return state_name;
    }

    void SetId(int id)
    {
        state_id = id;
    }

    void setStateName(string sname)
    {
        state_name = sname;
    }

    list<Edge> getEdgeList()
    {
        return edgelist;
    }
};

class Graph
{
public:
    vector<Vertex> vertices; // dynamic array storing elements of type vertex
    bool checkIfVertexExists(int id)
    {

        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getStateid() == id)
            {
                return true;
            }
        }
        return false;
    }

    void addVertex(int id, string sname)
    {
        bool check = checkIfVertexExists(id);
        if (check == false)
        {
            vertices.push_back(Vertex(id, sname));
            cout << "New Landmark added succesfully !!" << endl;
        }
        else
        {
            cout << " Landmark  with this Id already Exists " << endl;
        }
    }
    void printVertices(Graph g)
    {
        for (Vertex v : g.vertices)
        {
            cout << "Landmark " << v.getStateid() << " : " << v.getStateName() << endl;
        }
    }

    void addEdge(int sourceId, int destId, int weight) // function to add an edge to the graph
    {
        for (auto &v : vertices)
        {
            if (v.getStateid() == sourceId)
            {
                v.edgelist.push_back(Edge(destId, weight));
                break;
            }
        }
    }

    bool Traffic_update(int sourceId, int destId, int delay_convt_to_dist) // function to update an edge in the graph by adding a value to its weight
    {
        for (auto &v : vertices)
        {
            if (v.getStateid() == sourceId)
            {
                for (auto &e : v.edgelist)
                {
                    if (e.getDestinationVertexId() == destId)
                    {
                        int newWeight = e.getWeight() + delay_convt_to_dist;
                        e.setWeight(newWeight);
                        return true;
                    }
                }
            }
        }
        return false; // edge not found
    }

    bool bellmanFord(int sourceId, int destId, vector<int> &distance, vector<int> &predecessor) // function to run the Bellman-Ford algorithm
    {
        // Initialize the distance and predecessor arrays
        int n = vertices.size();
        distance.assign(n, INT_MAX);
        predecessor.assign(n, -1);
        distance[sourceId] = 0;

        // Relax all edges n-1 times
        for (int i = 0; i < n - 1; i++)
        {
            for (auto &v : vertices)
            {
                for (auto &e : v.edgelist)
                {
                    int u = v.getStateid();
                    int w = e.getWeight();
                    int dest = e.getDestinationVertexId();
                    if (distance[u] != INT_MAX && distance[u] + w < distance[dest])
                    {
                        distance[dest] = distance[u] + w;
                        predecessor[dest] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (auto &v : vertices)
        {
            for (auto &e : v.edgelist)
            {
                int u = v.getStateid();
                int w = e.getWeight();
                int dest = e.getDestinationVertexId();
                if (distance[u] != INT_MAX && distance[u] + w < distance[dest])
                {
                    cout << "Graph contains negative cycle" << endl;
                    return false;
                }
            }
        }

        // Return the shortest path to the destination vertex
        if (distance[destId] == INT_MAX)
        {
            cout << "No path found from " << vertices[sourceId].getStateName() << " to "
                 << vertices[destId].getStateName() << endl;
            return false;
        }
        else
        {
            return true;
        }
    }

    void printPath(int sourceId, int destId, vector<int> &predecessor) // function to print the shortest path
    {
        list<int> path;
        int current = destId;
        while (current != -1)
        {
            path.push_front(current);
            current = predecessor[current];
        }
        if (path.front() != sourceId)
        {
            cout << "No path found from " << vertices[sourceId].getStateName() << " to "
                 << vertices[destId].getStateName() << endl;
        }
        else
        {
            cout << "Shortest path from " << vertices[sourceId].getStateName() << " to "
                 << vertices[destId].getStateName() << " is:";
            for (auto &v : path)
            {
                cout << " " << vertices[v].getStateName();
                if (v != destId)
                    cout << " ->";
            }
            cout << endl;
        }
    }
};
int timedelay_to_distance_converter(int truck_speed, int time_delay)
{
    return (truck_speed * time_delay) / 60;
}
int main()
{
    int option, id;
    int no_of_landmarks;
    bool edge_flag = true;
    bool traffic_flag = true;
    int landmark_id1, landmark_id2;
    int land_dist;
    char edge_ch, traffic_ch;
    Graph g;
    string sname;
    int time_delay;
    int delay_convt_to_dist, truck_speed;

    do
    {
        cout << "What operations you want to perform ?" << endl;
        cout << "Enter Option Number " << endl;
        cout << "Enter 0 to exit" << endl;

        cout << " 1.Add landmarks towards the client destination" << endl; // add vertex   operation

        cout << "2. Add all the paths  to go from one landmark to another" << endl; // delete vertex

        cout << "3.Delete a path to go from one landmark to another " << endl; // add edges

        cout << " 4.  " << endl; // delete edges

        cin >> option;

        switch (option)
        {
        case 0:
            break;

        case 1:

            cout << "Enter the total number of landmarks" << endl;
            cin >> no_of_landmarks;
            for (int j = 0; j < no_of_landmarks; j++)
            {
                cout << "Adding a landmark towards a client destination" << endl;
                cout << "Please give landmark an integer id" << endl;
                cin >> id;

                cout << "Please enter the landmark name " << endl;
                cin >> sname;
                g.addVertex(id, sname);
            }

            break;

        case 2:
            cout << "Start Entering the known paths from one landmark to another" << endl;

            cout << "Here are the landmarks along with names and intger id for reference" << endl;
            g.printVertices(g);

            while (edge_flag == true)
            {
                cout << "  Enter Id given to landmark from where the path starts" << endl;
                cin >> landmark_id1;

                cout << "  Enter Id given to landmark  where the path ends" << endl;
                cin >> landmark_id2;

                cout << "Enter the distance from one landmark to another in km/s" << endl;
                cin >> land_dist;

                g.addEdge(landmark_id1, landmark_id2, land_dist);
                cout << "A path has been added successfully" << endl;
                cout << "Do you want to add more paths , If yes enter y otherwise enter n" << endl;
                cin >> edge_ch;
                if (edge_ch == 'y' || edge_ch == 'Y')
                {
                    edge_flag = true;
                }
                else if (edge_ch == 'n' || edge_ch == 'N')
                {
                    edge_flag = false;
                }
                else
                {
                    cout << "Please enter a valid answer \n Enter Again " << endl;
                    cin >> edge_ch;
                }
            }
            break;

        case 3:
            cout << "Please update traffic between two landmarks to help make an optimal path " << endl;
            cout << "Please Enter the speed of the truck " << endl;
            cin >> truck_speed;
            cout << "Here are the landmarks with their name and references " << endl;
            g.printVertices(g);

            while (traffic_flag = true)
            {
                cout << "Enter the landmark from where the path starts where traffic is  " << endl;
                cin >> landmark_id1;
                cout << " Enter the landmark  where the path ends where traffic is " << endl;
                cin >> landmark_id2;
                cout << "Enter the time in delay due to traffic  in minutes " << endl;
                cin >> time_delay;

                delay_convt_to_dist = timedelay_to_distance_converter(truck_speed, time_delay);

                g.Traffic_update(landmark_id1, landmark_id2, delay_convt_to_dist);

                cout << "Do you want to add traffic update between more landmarks" << endl;

                cout << "If yes then enter y otherwise enter n" << endl;
                cin >> traffic_ch;
                if (traffic_ch == 'y' || traffic_ch == 'Y')
                {
                    traffic_flag = true;
                }
                else if (traffic_ch == 'n' || traffic_ch == 'N')
                {
                    traffic_flag = false;
                }
                else
                {
                    cout << "Please enter a valid answer \n Enter Again " << endl;
                    cin >> traffic_ch;
                }
            }

            break;

        case 4:
            break;
        }
    } while (option != 0);

    return 0;
}