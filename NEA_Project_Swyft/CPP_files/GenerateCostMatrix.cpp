#include <iostream>
#include <fstream>
#include <string>
#include "../FunctionDeclarations.h"

using namespace std;

string get_cost_matrix(){
    int distance{0}; // Represents the weight of each connection in a weighted graph [manual]
    bool first_time{1}; // Allows for loop to allow forst loop without ending early [manual]
    int node_search{0}; // Searches for the number of nodes [automatic]
    int node_count{0}; // When we count the number of nodes [both]
    string string_matrix = ""; // The final output - the matrix [both]
    bool is_automatic{1}; // Option for menu
    
    cout<<"Manual or automatic? (0 means manual, 1 means automatic)" << endl;
    cin>>is_automatic;

    // Automatic
    // Parsing data from a database
    if (is_automatic) {
        fstream dummy_text;  // Creating the object to hold the file
        string raw_matrix_data; // This will hold the data extracted from the file
        dummy_text.open("Dummy Data/DummyData.txt", ios::in);  // Opening the file
        
        // Here, if the file is open, the data is moved to the raw_matrix_data string
        if (dummy_text.is_open()) {
            string input;
            while(getline(dummy_text, input)) {
                raw_matrix_data += input;
            }
            dummy_text.close();  // Closing the file do it doesn't haunt the memory like a ghost
        }

        //  The zeros will always be in the same place in every matrix, so they will be used to create the
        //  matrix. The number of non-zero numbers between each zero = the number of nodes
        //  This for loop is for parsing through the string
        for (char c : raw_matrix_data) {
            (c == '0') ? node_count=node_search, node_search=0 : node_search++;
        }
        
        //  This for loop is for constructing the matrix
        for (int i{1}; i <= raw_matrix_data.length(); i++) {
            string_matrix += raw_matrix_data[i-1];  // Add a character from the raw data into the matrix
            if (i % node_count == 0) string_matrix += "\n";  // Add a newline if the node count has been
            // reached.
        }
    } else {
    // Manual
    // Iterating through each node
        for (int i{0}; i < node_count || first_time; i++) {        
            cout << "Distances of neighbors from Node " << i << ": " << endl;
            
            while (true) {
                cin>>distance;
                cout<<' '<<endl; //  gap
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
        cout<< "Manual string matrix: " <<string_matrix;
    }

    return string_matrix;
}