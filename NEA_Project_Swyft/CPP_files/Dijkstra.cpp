#include <iostream>
#include <vector>
#include <algorithm>
#include "../FunctionDeclarations.h"

using namespace std;

const int infinity {999};

// The way cost works: cost[x][y] is the distance (weight) between node x and node y
int vertices, start_node, cost[100][100]; // using cost matrix for graph

int dist[100]; // storing a distance value for all nodes (from start node)

bool visited[100] = {0}; // Whether the node has been visited or not

int parent_node[100]; // The index will be the key, the value will be the parent

// This procedure sets the distances to infinity for each vertex
void initialise() {
    for (int i {0}; i < vertices; i++) {
        parent_node[i] = i; // i is just a placeholder value, it'll be replaced by the actual parent soon
        dist[i] = infinity;
    }
    dist[start_node] = 0; // all distances are infinity at the start of the algorithm, except for the distance
    // between the start and the start, which is obviously 0.
}

int get_nearest_node() {
    int min_value {infinity};
    int closest_node {0};
    // looks through all nodes to return the closest one
    for (int i {0}; i < vertices; i++) {
        if ( !visited[i] && (dist[i] < min_value)) {
            min_value = dist[i];
            closest_node = i;
        }
    }
    
    return closest_node;
}

void dijkstra() {
    cout << "Dijkstra starting..." << endl;
    for (int i {0}; i < vertices; i++) {
        int nearest_node = get_nearest_node();
        visited[nearest_node] = true;
        
        // Updating for adjacent nodes
        for (int adj {0}; adj < vertices; adj++) {
            // Note: dist[adj] is the old distance from start to adj. Col67 - Col111 is the candidate for the
            // new distance. In English: update the distance if the candidate is less than the old value, as the
            // old value could be the actual minimum
            if (cost[nearest_node][adj] != infinity && dist[adj] > dist[nearest_node] + cost[nearest_node][adj]) {
                dist[adj] = dist[nearest_node] + cost[nearest_node][adj];
                parent_node[adj] = nearest_node;
            }
        }
    }
    cout << "Dijkstra ending..." << endl;
}

vector<int> display(int destination) {
    vector<int> path;
    
    cout << "Node:\t\t\tCost:\t\t\tPath:" << endl;
    
    for (int i {0}; i < vertices; i++) {
        cout << i << "\t\t\t" << dist[i] << "\t\t\t";

        cout << i << " ";
        int parnode = parent_node[i];
        if (i==destination) path.push_back(cost[parnode][i]);

        while (parnode != start_node) {
            cout << " <-- " << parnode << " ";
            if (i==destination) path.push_back(cost[parent_node[parnode]][parnode]);
            parnode = parent_node[parnode];
        }
        cout << endl; // Now, we have the road lengths, but in reverse order. To fix this, they will be reversed
    }
    reverse(path.begin(), path.end()); // road lengths are now prepared via paths
    cout << endl;

    return path;
}

vector<int> inputs_for_dijkstra(int roads, vector<int> matrix, int target) {   
    vertices = roads; // Now the vertices global variable has been updated to the number of roads (which it is)

    cout << "Thank you, now enter the cost matrix" << endl;

   int counter {0};
   for (int i {0}; i < vertices; i++) {
        for (int j {0}; j < vertices; j++) {
            cost[i][j] = matrix[counter];
            counter++;
        }
    }

    cout << "Thank you for the cost matrix, now enter the start node: ";
    cin >> start_node;
    cout << "Done." << endl;
    initialise();
    dijkstra();
    vector<int> road_lens = display(target);
    // print_array(road_lens);
    return road_lens;
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