#include <iostream>
#include <vector>

using namespace std;

// Declarations of Methods

// Print contents of an array/vector
void print_array(int[], size_t);
void print_array(double[], size_t);
void print_array(vector<int>);
void print_array(vector<double>);

// returns the biggest of the two
int max(int,int);
double max(double,double);

// add values straight into a vector from cin
vector<int> vec_add(vector<int>,size_t);
vector<double> vec_add(vector<double>,size_t);

//Keeps prompt open
void keep_open();

// Writes to a text file
void text_write(int,string);

// Reads from a text file
const int text_read(string);

// Interface
void interface();

// Calculates the fuel over a period of time finder
float calc_fuel(float,float,float);
float calc_fuel_percentage(float,float);

// Shortest path - Dijkstra's algorithm
int get_nearest_node();
void initialise();
vector<int> inputs_for_dijkstra(int,vector<int>);
void dijkstra();
vector<int> display(int);
//Addition to dijkstra
string get_cost_matrix(int &node_number);

// For traffic light regression
float calc_unknown(float, float, char);
vector<int> get_seq(int);

// Gets the final sequence
vector<int> get_final_seq(vector<vector<int>>,vector<int>,vector<int>,const int le=5,int inc=0);