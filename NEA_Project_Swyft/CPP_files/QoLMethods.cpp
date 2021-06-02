#include <iostream>
#include <vector>
#include <fstream>
#include "../FunctionDeclarations.h"

using namespace std;

// Edits a text file
void text_write(int val, string loc) {
	ofstream file {loc};
	file << val;
	file.close();
}

// Reads from a text file
const int text_read(string loc) 
{
	ifstream file {loc}; // Stores the file as an object
	int val; // Declares a variable to store contents of file
	file >> val; // Contents are stored
	return val; // And returned
}

// Reads from a text file
const string text_read(string loc, string x) 
{
	ifstream file {loc}; // Stores the file as an object
	string val; // Declares a variable to store contents of file
	file >> val; // Contents are stored
	return val; // And returned
}

//Keep prompt open
void keep_open() {
    int x; // Empty meaningless character
    cin>>x; // used as input so prompt doesn't close till input entered
}

void print_array(int inp_array[], size_t size) {
	// For each item in the array...
	for (int i{0}; i < size; i++) {
		// It is output
		cout << inp_array[i] << ' ';
	}
	cout << endl; // Empty newline character outputted for clarity
}

void print_array(double inp_array[], size_t size) {
	// For each item in the array...
	for (int i{0}; i < size; i++) {
		// It is output
		cout << inp_array[i] << ' ';
	}
	cout << endl; // Empty newline character outputted for clarity
}

void print_array(vector<int> inp_array) {
	// For each item in the array...
	for (int i{0}; i < inp_array.size(); i++) {
		// It is output
		cout << inp_array[i] << ' ';
	}
	cout << endl; // Empty newline character outputted for clarity
}

void print_array(vector<double> inp_array) {
	// For each item in the array...
	for (int i{0}; i < inp_array.size(); i++) {
		// It is output
		cout << inp_array[i] << ' ';
	}
	cout << endl; // Empty newline character outputted for clarity
}

void print_array(vector<string> inp_array) {
	// For each item in the array...
	for (int i{0}; i < inp_array.size(); i++) {
		// It is output
		cout << inp_array[i] << ' ';
	}
	cout << endl; // Empty newline character outputted for clarity
}

// Add inputs directly to a a vector from cin
vector<int> vec_add(vector<int> x, size_t length) {
	int inp; // Value to be added
	// For each time that the value needs to be added...
	for (int i{0}; i < length; i++) {
		cout << "Enter a value: " << endl; // A value is requested from the user
		cin>>inp; // The value is stored
		x.push_back(inp); // The value is added
	}
	return x;
}

vector<double> vec_add(vector<double> x, size_t length) {
	double inp; // Value to be added
	// For each time that the value needs to be added...
	for (int i{0}; i < length; i++) {
		cout << "Enter a value: " << endl; // A value is requested from the user
		cin>>inp; // The value is stored
		x.push_back(inp); // The value is added
	}
	return x;
}

// max value between two numbers
int max(int a, int b) 
{
	if (a > b) return a; // If the value is is numerically greater than b, a is outputted
	else return b; // b is outputted
}

double max(double a, double b) 
{
	if (a > b) return a; // If the value is is numerically greater than b, a is outputted
	else return b; // b is outputted
}
