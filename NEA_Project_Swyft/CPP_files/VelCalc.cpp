#include <iostream> // Needed for input and output 
#include "../FunctionDeclarations.h" // Needed for using the program in the solution

using namespace std; // Saves time

float calc_unknown(float param1, float param2, char req) {
	// vel = disp/time

	// Depending on the value of req (which value is required), a different branch is chosen
	switch (req) {
	case 'v':
		return param1 / param2; // Here, param1 is disp and param2 is time
	case 'd':
		return param1 * param2; // Params are velocity and time, order doesn't matter
	case 't':
		return param1 / param2; // Param1 is disp, param2 is vel
	default:
		cout << "Sorry, unrecognized req (last parameter)" << endl;
		return 0;
	}
}
