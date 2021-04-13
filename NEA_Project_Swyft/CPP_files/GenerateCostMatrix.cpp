#include <iostream> // Input and output
#include <fstream> // reading to/writing from files
#include <string> // manipulation of strings
#include <vector> // manipulation and use of vectors
#include "../FunctionDeclarations.h" // Allows it to be used by main

using namespace std; // saves typing std at the start

string get_cost_matrix(int &node_number){
    int distance{0}; // Represents the weight of each connection in a weighted graph [manual]
    bool first_time{1}; // Allows for loop to allow first loop without ending early [manual]
    int node_search{0}; // Searches for the number of nodes [automatic]
    int node_count{0}; // When we count the number of nodes [both]
    string string_matrix = ""; // The final output - the matrix [both]
    vector<int> vec_raw_matrix; // Takes the raw matrix from the external file without processing fully
    bool is_automatic{1}; // Option for menu
    
    cout<<"Manual or automatic? (0 means manual, 1 means automatic)" << endl;
    cin>>is_automatic; // Takes input for the 'is_automatic' variable

    // Automatic
    // Parsing data from a database
    if (is_automatic) {
        fstream dummy_text;  // Creating the object to hold the file
        string raw_matrix_data; // This will hold the data extracted from the file
        dummy_text.open("Dummy Data/DummyDataCSV.csv", ios::in);  // Opening the file
        
        // Here, if the file is open, the data is moved to the raw_matrix_data string
        if (dummy_text.is_open()) // If the file is open
          {
            string input; // this stores the input of the file
            while(getline(dummy_text, input)) // a way to obtain the contents of the file
            {
                raw_matrix_data += input; // saving the contents of the file to this variable
            }
            dummy_text.close();  // Closing the file do it doesn't haunt the memory with its ghost
        }

        // Take into account delimiter ',' and split string into items to fit in the vector
        string item; // This represents each item in the matrix
        for (int i{0}; i < raw_matrix_data.length(); i++) // Loops through each item in the matrix
        {
            // If the element at index i of raw_matrix_data is a comma, then the value stored in 'item'
            // is added to the vector version of the raw_matrix, and item is made blank again.
            // in the event that the element at index i is a number, it is saved in the 'item' variable
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
        for (int i{0}; i < node_count || first_time; i++) // looping through nodes, but if it's the first
        // loop then the condition 'i < node_count' is ignored
        {        
            cout << "Distances of neighbors from Node " << i << ": " << endl;
            
            while (true) // infinite loop, will get broken soon
            {
                cin>>distance; // inputs the distance
                cout<<' '<<endl; // gap
                if (distance == -1) // if the user enters '-1', then the program moves onto the next node
                {
                    cout<<"-Next node-"<<endl;
                    first_time = false; // it is no longer the first loop, and so this variable is set to false
                    break; // breaking out of the infinite loop
                }
                string_matrix += to_string(distance) + " "; // The final string version of the matrix will be
                // created using the distances

                (first_time) ? node_count++ : node_count+=0; // Each extra distance we add creates a new instance of a node
            }
            string_matrix += '\n'; // adds a newline character to string matrix to signify the end of a row
            
        }
        cout<< "Manual string matrix: " << string_matrix;
    }

    node_number = node_count; // Node count should also be extracted. It'll be useful for dijkstra
    return string_matrix; // returned in string format is strings are very flexible
}