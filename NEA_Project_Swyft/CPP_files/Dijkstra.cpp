#include <iostream> // adds input/output functionality
#include <vector> // adds vectors, a type of data structure which contains sequences of elements dynamically
#include <algorithm> // adds some algotithms which are used to improve the efficiency of the code
#include <fstream> // allows for accessing external files such as csv's or text documents
#include "../FunctionDeclarations.h" // contains headers of all the functions contained in the other files to
// be accessed here

using namespace std; // saves needing to type std:: in front of anything from the iostream library, and more

// Boost all arrays declared here into vectors

const unsigned long infinity {999}; // I am representing infinity here as 999

const int roads {text_read("Dummy Data/DummyData.txt")}; // Takes list of all road lenths from external file

int vertices, start_node; // Start_node is for the node from which Dijkstra will start, vertices is the number
// of vertices in the graph

// The way cost works: cost[x][y] is the distance (weight) between node x and node y
vector<vector<int>> cost; // using cost matrix for graph

vector<int> sub_cost(roads); // The cost from each vertice

vector<int> dist(roads); // storing a distance value for all nodes (from start node)

vector<bool> visited(roads); // Whether the node has been visited or not

vector<int> parent_node(roads); // The index will be the key, the value will be the parent

// This procedure sets the distances to infinity for each vertex
void initialise(/*long infinity*/) {
    for (int i {0}; i < vertices; i++) {
        parent_node[i] = i; // i is just a placeholder value, it'll be replaced by the actual parent soon
        dist[i] = ::infinity; // Initially, all distances from the start node are set to infinity
    }
    dist[start_node] = 0; // all distances are infinity at the start of the algorithm, except for the distance
    // between the start and the start, which is obviously 0.
}

// Gets the nearest node
int get_nearest_node() {
    int min_value {::infinity}; // Initially, the closest value is infinity
    int closest_node {0}; // Closest node set to itself at first because we haven't looked for any yet
    for (int i {0}; i < vertices; i++) // looks through all nodes to return the closest one
    {
        if ( !visited[i] && (dist[i] < min_value)) { // here, if the node hasn't been visited yet and its 
        // distance is less than the lowest so far, then it must be the closest node
            min_value = dist[i]; // This becomes the new minimum
            closest_node = i; // This becomes the new closest node
        }
    }
    return closest_node; // outputs the closest node once it's done looping through all
}

void dijkstra() // Main algorithm where the shortest path is found in the graph
{
    cout << "Dijkstra starting..." << endl;
    for (int i {0}; i < vertices; i++) // Looping through all nodes/vertices, same thing
    {
        int nearest_node = get_nearest_node(); // Retrieves nearest node from previous method
        visited[nearest_node] = true; // This marks the closest node as 'visited'
        
        // Updating for adjacent nodes
        for (int adj {0}; adj < vertices; adj++) {
            // Note: dist[adj] is the old distance from start to adj. Col70 - Col114 is the candidate for the
            // new distance. In English: update the distance if the candidate is less than the old value, as the
            // old value could be the actual minimum
            if (cost[nearest_node][adj] != ::infinity && dist[adj] > dist[nearest_node] + cost[nearest_node][adj]) {
                dist[adj] = dist[nearest_node] + cost[nearest_node][adj];
                parent_node[adj] = nearest_node;
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
    ::vertices = roads; // Now the vertices global variable has been updated to the number of roads (which it is)

    for (int i {0}; i < vertices; i++) // looping through all the vertices in the graph
    {
        cost.push_back(sub_cost); // add each mini-cost, the cost between one node and another
    }

    cout << "Thank you, now enter the cost matrix" << endl;

   int counter {0}; // To keep track of how many times we've gone through the loop
   for (int i {0}; i < vertices; i++) // looping through all vertices again
   {
        for (int j {0}; j < vertices; j++) // looping through all vertices once more as we are using a 2D list
        {
            cost[i][j] = matrix[counter]; // The cost matrix to set to the matrix at this particular stage of the loop
            counter++; // Counter increments
        }
    }

    cout << "Thank you for the cost matrix, now enter the start node: ";
    cin >> start_node; // User enters start node
    while (!(start_node < vertices && start_node > 0)) // The start node cannot be less that 0 or greater than 
    //the total number of nodes
    {
        cout << "Invalid start node, try again" << endl;
        cin >> start_node; // User attempts to enter the start node again
    }
    cout << "Done." << endl;
    cout << "Please enter the target node: ";
    cin >> target; // User enterts the target node
    while (!(target >= 0 && target < vertices && target != start_node)) // The target must be between 0 and the 
    // total number of nodes, and can't be the start node either
    {
        cout << "Invalid target, try again" << endl;
        cin >> target; // User attempts to enter target nodes
    }

    initialise();
    dijkstra();
    vector<int> road_lens = display(target); // gets the road lengths from the display function
    return road_lens; // returns the lengths of the roads for other methods to use
}

/*
 
The cost matrix of BetterGraph: 

 0    999  999  999  6    999  999  999  999
 999  0    6    6    9    999  999  999  999
 999  6    0    17   999  4    999  999  999
 999  6    17   0    999  999  5    999  999
 6    9    999  999  0    999  14   999  999
 999  999  4    999  999  0    999  16   999
 999  999  999  5    14   999  0    999  999
 999  999  999  999  999  16   999  0    2
 999  999  999  999  999  999  999  2    0 

*/