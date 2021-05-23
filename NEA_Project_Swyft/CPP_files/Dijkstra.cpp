#include <iostream> // adds input/output functionality
#include <vector> // adds vectors, a type of data structure which contains sequences of elements dynamically
#include <algorithm> // adds some algotithms which are used to improve the efficiency of the code
#include <fstream> // allows for accessing external files such as csv's or text documents
#include "../FunctionDeclarations.h" // contains headers of all the functions contained in the other files to
// be accessed here

using namespace std; // saves needing to type std:: in front of anything from the iostream library, and more

const unsigned long infinity {999}; // Representing infinity here as 999

const int roads {text_read("Dummy Data/DummyData.txt")}; // Takes list of all road lenths from external file

int vertices, start_node; // Start_node is the node from which Dijkstra will start, vertices is the number
// of vertices in the graph

// The way cost works: cost[x][y] is the weight of the edge between node x and node y
vector<vector<int>> cost; // using cost matrix for graph, which is stored in this variable

vector<int> sub_cost(roads); // The cost from each vertice

vector<int> dist(roads); // storing a distance value for all nodes (sum of weights of edges from start node)

vector<bool> visited(roads); // Whether the node has been visited or not

vector<int> parent_node(roads); // The index will be the key, the value will be the parent. Used to backtrack

// This procedure sets the distances to infinity for each vertex
void initialise()
{
    for (int i {0}; i < vertices; i++)  // for each item in  the vector 'vertices'...
    {
        parent_node[i] = i; // i is just a placeholder value, it'll be replaced by the actual parent soon
        dist[i] = ::infinity; // Initially, all distances from the start node are set to infinity
    }
    dist[start_node] = 0; // Although all distances are infinity at the start of the algorithm, the distance
    // between the start node and itself is 0.
}

// This procedure gets the nearest node
int get_nearest_node() 
{
    int min_value {::infinity}; // Initially, the closest value is infinity
    int closest_node {0}; // Closest node set to itself at first because we haven't looked for any yet
    for (int i {0}; i < vertices; i++) // looks through all nodes to return the closest one
    {
        if ( !visited[i] && (dist[i] < min_value)) { // here, if the node hasn't been visited yet AND its 
        // distance is less than the lowest so far, then it must be the closest node
            min_value = dist[i]; // This becomes the new minimum value
            closest_node = i; // This becomes the new closest node
        }
    }
    return closest_node; // outputs the closest (nearest) node once it's done looping through all
}

void dijkstra() // Main algorithm where the shortest path is found in the graph
{
    for (int i {0}; i < vertices; i++) // Looping through all nodes/vertices
    {
        int nearest_node = get_nearest_node(); // Retrieves nearest node using previous method
        visited[nearest_node] = true; // This marks the closest node as 'visited', so the algorithm doesn't
        // need to go over it again
        
        // Updating for adjacent nodes
        for (int adj {0}; adj < vertices; adj++) // for each adjacent node in the vector 'vertices'...
        {
            // Note: dist[adj] is the old distance from start to adj. Col70 - Col114 is the candidate for the
            // new distance. In English: update the distance if the candidate is less than the old value, the
            // old value could be the actual minimum
            if (cost[nearest_node][adj] != ::infinity && 
            dist[adj] > dist[nearest_node] + cost[nearest_node][adj]) // Here, first the weight of the edge
            // between the nearest and adjacent node is checked to make sure it's not infinity, and if the
            // total distance (sum of the weight of the edges between the start node and the adjacent node)
            // is greater than the total distance (sum of the weight of the edges between the start node and
            // the nearest node) plus the weight of the edge between the nearest and adjacent node, then...
            {
                dist[adj] = dist[nearest_node] + cost[nearest_node][adj]; // distance to adj is updated to 
                // reflect this
                parent_node[adj] = nearest_node; // The parent node of adj is set to the nearest node
                // <ADD A DIAGRAM FOR THIS IN THE DOCUMENT>
            }
        }
    }
    cout << "Dijkstra ending..." << endl;
}

vector<int> display(int destination) // Shows the output to the user
{
    vector<int> path; // path from the start node to the destination
    
    cout << "Node:\t\t\tCost:\t\t\tPath:" << endl;
    
    for (int i {0}; i < vertices; i++) // Looping through vertices
    {
        cout << i << "\t\t\t" << dist[i] << "\t\t\t";

        cout << i << " ";
        int parnode = parent_node[i]; // This sets the parent node to the actual parent node
        if (i==destination) path.push_back(cost[parnode][i]); // This records the path to the destination

        while (parnode != start_node) // keep retracing steps until you got back to the start node
        {
            cout << " <-- " << parnode << " ";
            if (i==destination) path.push_back(cost[parent_node[parnode]][parnode]); // Adds the rest of the 
            // path to the destination
            parnode = parent_node[parnode]; // updates the parent node to the parent node's parent
        }
        cout << endl; // Now, we have the road lengths, but in reverse order. To fix this, they will be reversed
    }
    reverse(path.begin(), path.end()); // road lengths are now prepared via paths
    cout << endl;

    return path; // Outputs the complete path to the destination from the start node
}

vector<int> inputs_for_dijkstra(int roads, vector<int> matrix) // Method which obtains the inputs required for
// Dijkstra to work
{
    int target; // Declaring the target
    ::vertices = roads; // Now the vertices global variable has been updated to the number of roads
    // (which it is)

    for (int i {0}; i < vertices; i++) // looping through all the vertices in the graph
    {
        cost.push_back(sub_cost); // add each mini-cost, the cost between one node and another
    }

   int counter {0}; // To keep track of how many times we've gone through the loop
   for (int i {0}; i < vertices; i++) // looping through all vertices again
   {
        for (int j {0}; j < vertices; j++) // looping through all vertices once more as we are using a 2D list
        {
            cost[i][j] = matrix[counter]; // The cost matrix to set to the matrix at this particular stage of 
            //the loop
            counter++; // Counter increments
        }
    }
    
    bool start_flag {1};
    string str_start_node;

    while (start_flag) {
        cout << "Enter the start node: ";
        cin >> str_start_node; // User enters start node

        start_flag = false;

        for (int i{0}; i < str_start_node.length(); i++)
        if (!isdigit(str_start_node[i])) start_flag = true;
        if (!start_flag && (stoi(str_start_node) >= vertices || stoi(str_start_node) < 0)) start_flag = true;
        if (start_flag) cout << "Invalid start node, try again" << endl;
    }

    start_node = stoi(str_start_node);
    cout << "Done." << endl;

    string str_target_node;
    bool target_flag {1};

    while (target_flag) {
        target_flag = false;
        cout << "Please enter the target node: ";
        cin>> str_target_node;


        for (int i{0}; i < str_target_node.length(); i++)
        if (!isdigit(str_target_node[i])) target_flag = true;
        if (!target_flag && (stoi(str_target_node) >= vertices || stoi(str_target_node) < 0 || str_target_node == str_start_node)) target_flag = true;
        if (target_flag) cout << "Invalid target node, try again" << endl;
    }

    target = stoi(str_target_node); // target node turns from string to integer

    initialise();
    dijkstra();
    vector<int> road_lens = display(target); // gets the road lengths from the display function
    return road_lens; // returns the lengths of the roads for other methods to use
}

/*
 
The cost matrix of BetterGraph: 

 0    999  999  999  6    999  999  999  999
 999  0    6    6    9    999  999  999  999
 999 6    0    17   999  4    999  999  999
 999  6    17   0    999  999  5    999  999
 6    9    999  999  0    999  14   999  999
 999  999  4    999  999  0    999  16   999
 999  999  999  5    14   999  0    999  999
 999  999  999  999  999  16   999  0    2
 999  999  999  999  999  999  999  2    0 

*/