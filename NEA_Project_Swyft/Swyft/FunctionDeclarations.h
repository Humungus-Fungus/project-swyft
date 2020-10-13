// declarations of functions

// Interface
void interface();

// Calculates the fuel over a period of time finder
float calc_fuel(float,float,float);
float calc_fuel_percentage(float,float);

// Shortest path - Dijkstra's algorithm
int get_nearest_node();
void inputs_for_dijkstra();
void initialise();
void inputs_for_dijkstra();
void dijkstra();
//Addition to dijkstra
std::string get_cost_matrix(int,int);