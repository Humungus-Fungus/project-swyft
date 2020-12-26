#include <iostream>
#include <string>
#include <list>
#include "../FunctionDeclarations.h"

/* Todo: 
 [*] Add Djikstra's algorithm to find the shortest path ordinarily [DONE]
  * Optimise to the dimensions of cost are equal to the number of vertices, saving space
  [*] Find road lengths
 * Add Basic UI
 [*] Take into account the timings of the traffic lights (when they are green)
 * Add frequent locations list (list when they're free to go)
 * Take weather into account (flooded roads)
 * Take traffic levels into account (congestion)
 * Take road works into account (Blocked roads)
 [*] Voice recognition (offline voice commands) 
 * Text to speech ()
*/

using namespace std;

int main() {
    string seq1 = get_seq();
    string seq2 = get_seq();
    string seq3 = get_seq();

    cout << seq1 << "\n" << seq2 << "\n" << seq3 << endl;
    
    int nodes{0}; 
    string matrix = get_cost_matrix(&nodes); // Nodes has been updated
    cout << "Nodes from Main: " << nodes << endl;
    cout << "Matrix from Main:\n " << matrix << endl;
    // inputs_for_dijkstra();
    // interface();
    
    keep_open();
    return 0;
    
}


