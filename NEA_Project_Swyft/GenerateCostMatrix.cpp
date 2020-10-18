#include <iostream>
#include <string>
#include "FunctionDeclarations.h"

using namespace std;

string get_cost_matrix(){
    int distance{0};
    int node_count{0}; // When we count the number of nodes
    bool first_time{true};
    string string_matrix = "";
    
    // Iterating through each node
    for (int i{0}; i < node_count || first_time; i++) {        
        cout << "Distances of neighbors from Node " << i << ": " << endl;
        
        while (true) {
            cin>>distance;
            cout<<' '<<endl;
            if (distance == -1) {
                cout<<"-Next node-"<<endl;
                first_time = false;
                break;
            }
            string_matrix += std::to_string(distance) + " ";
            (first_time) ? node_count++ : node_count+=0; // Each extra distance we add creates a new instance of a node
            
            // For debugging
            // cout << "\ni: " << i << endl;
            // cout << "nodes: " << node_count << endl;
        }
        string_matrix += '\n';
        
    }
    cout<<string_matrix;
    return string_matrix;
}