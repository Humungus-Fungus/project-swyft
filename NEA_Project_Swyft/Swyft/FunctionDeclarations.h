// declarations of functions

// Interface
void interface();

// Calculates the fuel over a period of time finder
float calc_fuel(float initial_fuel, float mileage, float distance);
float calc_fuel_percentage(float max_fuel, float current_fuel);

// Shortest path - Dijkstra's algorithm
int get_nearest_node();
void inputs_for_dijkstra();
void initialise();
void inputs_for_dijkstra();
void dijkstra();