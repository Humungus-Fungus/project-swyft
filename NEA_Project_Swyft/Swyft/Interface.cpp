#include <iostream>

using namespace std;


// The index is the number of the node in ExampleGraph.jpg. The value is the name.
string dests[9] = {"Home", "Emerald Meadows", "Golden Sands", "Silver Cinema", "Unyielding Mountains",
                   "The Sun", "Haunted House", "Amusement Park", "Airport"};

void interface() {
    cout << "----------------------" << endl;
    cout << "Choose an option: " << endl;
    cout << "1. Choose destination\n2. View traffic levels" << endl; 
    int opt {0};
    cin >> opt;
    
    string destination;
    string start_point, end_point;
    switch (opt) {
        case 1:
            cout << "Which destination would you like?" << endl;
            for (string name : dests) {
                cout << name << endl;
            }
            cin>> destination;
            cout << "\nI need to display the shortest distance between the source node and the chosen destination\n";
            break;
        case 2:
            cout << "Between which locations? Choose 2" << endl;
            cin >> start_point >> end_point;
            cout << "Sorry I don't know that yet. Maybe in an update soon?" << endl;
    }
     
}
