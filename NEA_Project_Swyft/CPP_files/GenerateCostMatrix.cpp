#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../FunctionDeclarations.h"

using namespace std;

string get_cost_matrix(int &node_number){
    int distance{0}; // Represents the weight of each connection in a weighted graph [manual]
    bool first_time{1}; // Allows for loop to allow forst loop without ending early [manual]
    int node_search{0}; // Searches for the number of nodes [automatic]
    int node_count{0}; // When we count the number of nodes [both]
    string string_matrix = ""; // The final output - the matrix [both]
    vector<int> vec_raw_matrix;
    bool is_automatic{1}; // Option for menu
    
    cout<<"Manual or automatic? (0 means manual, 1 means automatic)" << endl;
    cin>>is_automatic;

    // Automatic
    // Parsing data from a database
    if (is_automatic) {
        fstream dummy_text;  // Creating the object to hold the file
        string raw_matrix_data; // This will hold the data extracted from the file
        dummy_text.open("Dummy Data/DummyDataCSV.csv", ios::in);  // Opening the file
        
        // Here, if the file is open, the data is moved to the raw_matrix_data string
        if (dummy_text.is_open()) {
            string input;
            while(getline(dummy_text, input)) {
                raw_matrix_data += input;
            }
            dummy_text.close();  // Closing the file do it doesn't haunt the memory like a ghost
        }

        // Take into account delimiter ',' and split string into items to fit in the vector
        string item;
        for (int i{0}; i < raw_matrix_data.length(); i++) {
            (raw_matrix_data[i] == ',') ? vec_raw_matrix.push_back(stoi(item)), item = "" : item+=raw_matrix_data[i];
        }


        //  The zeros will always be in the same place in every matrix, so they will be used to create the
        //  matrix. The number of non-zero numbers between each zero = the number of nodes
        //  This for loop is for parsing through the string
        for (int i : vec_raw_matrix) {
            (i == 0) ? node_count=node_search, node_search=0 : node_search++;
        }
        
        //  This for loop is for constructing the matrix
        for (int i{0}; i < vec_raw_matrix.size(); i++) {
            string_matrix += to_string(vec_raw_matrix[i]) + " ";  // Add a character from the raw data into
            // the matrix, and add a space as a delimiter
        }

        cout << "Final node count for automatic: " << node_count << endl;
    } else {
    // Manual
    // Iterating through each node
        for (int i{0}; i < node_count || first_time; i++) {        
            cout << "Distances of neighbors from Node " << i << ": " << endl;
            
            while (true) {
                cin>>distance;
                cout<<' '<<endl; // gap
                if (distance == -1) {
                    cout<<"-Next node-"<<endl;
                    first_time = false;
                    break;
                }
                string_matrix += to_string(distance) + " ";
                (first_time) ? node_count++ : node_count+=0; // Each extra distance we add creates a new instance of a node
                
                // For debugging
                // cout << "\ni: " << i << endl;
                // cout << "nodes: " << node_count << endl;
            }
            string_matrix += '\n';
            
        }
        cout<< "Manual string matrix: " << string_matrix;
    }

    node_number = node_count; // Node count should also be extracted. It'll be useful for dijkstra
    return string_matrix; // returned in string format is strings are very flexible
}