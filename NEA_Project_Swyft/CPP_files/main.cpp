#include <iostream>
#include <string>
#include <list>
#include "../FunctionDeclarations.h"

/* Todo: 
 [*] Add Djikstra's algorithm to find the shortest path ordinarily [DONE]
  * Optimise to the dimensions of cost are equal to the number of vertices, saving space
  * Find road lengths
 * Add Basic UI
 * Take into account the timings of the traffic lights (when they are green)
 * Add frequent locations list (list when they're free to go)
 * Take weather into account (flooded roads)
 * Take traffic levels into account (congestion)
 * Take road works into account (Blocked roads)
 * Voice recognition (offline voice commands) 
 * Text to speech ()
*/

using namespace std;

// QoL functions
//Keep prompt open:
void keep_open() {
    int x;
    cin>>x;
}

int main() { 
    string matrix = get_cost_matrix();
    //inputs_for_dijkstra();
    //interface();
    
    keep_open();
    return 0;
    
}


