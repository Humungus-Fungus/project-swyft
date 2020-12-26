#include <iostream>
#include <vector>
#include "../FunctionDeclarations.h"

using namespace std;

//Keep prompt open
void keep_open() {
    int x;
    cin>>x;
}

void print_array(int inp_array[], size_t size) {
	for (int i{0}; i < size; i++) {
		cout << inp_array[i] << ' ';
	}
	cout << endl;
}

void print_array(double inp_array[], size_t size) {
	for (int i{0}; i < size; i++) {
		cout << inp_array[i] << ' ';
	}
	cout << endl;
}

void print_array(vector<int> inp_array) {
	for (int i{0}; i < inp_array.size(); i++) {
		cout << inp_array[i] << ' ';
	}
	cout << endl;
}

void print_array(vector<double> inp_array) {
	for (int i{0}; i < inp_array.size(); i++) {
		cout << inp_array[i] << ' ';
	}
	cout << endl;
}

// Add inputs directly to a a vector from cin
vector<int> vec_add(vector<int> x, size_t length) {
	int inp;
	for (int i{0}; i < length; i++) {
		cout << "Enter a value: " << endl;
		cin>>inp;
		x.push_back(inp);
	}
	return x;
}

vector<double> vec_add(vector<double> x, size_t length) {
	double inp;
	for (int i{0}; i < length; i++) {
		cout << "Enter a value: " << endl;
		cin>>inp;
		x.push_back(inp);
	}
	return x;
}

// max value between two numbers
int max(int a, int b) 
{
	if (a > b) return a;
	else return b;
}

double max(double a, double b) 
{
	if (a > b) return a;
	else return b;
}